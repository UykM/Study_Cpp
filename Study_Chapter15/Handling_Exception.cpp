/*
* try 블록과 catch 블록은 항상 이어서 정의해야함.
* try 블록은 그안에 삽입된 문장이 순서대로 실행
* try 블록 내에서 예외가 발생하지 않으면 catch 블록 이후를 실행
* try 블록 내에서 예외가 발생하면, 예외가 발생한 지점 이후의 나머지 try 영역은 건너뜀.
try
{
	// 예외발생 예상지역
	if( ... )
		throw -1;	// int형 예외 데이터 발생!
}
catch(처리할 예외의 종류 명시)		// catch 블록은 둘이상이 이어서 올 수 있음!
{
	// 예외처리 코드의 삽입
}
// catch(char expn) { ... }	 // char형 예외 데이터를 전달하라!
// 이 경우, 예외 데이터의 자료형과 catch의 매개변수 형이 일치하지 않으면,
// 자료형의 불일치로 인해 예외는 처리되지 않음(catch 블록으로 값이 전달 X).

throw expn;		// expn 은 변수, 상수 그리고 객체 등 표현 가능한 모든 데이터가 될 수 있음.
				// expn : 예외, 예외객체, 예외 데이터
*/

/*	예외의 발생과 처리에 대한 가장 일반적인 모델
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StoI(char* str)
{
	int len = strlen(str);
	int num = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i]>'9')
			throw str[i];
		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
	}
	return num;
}

int main(void)
{
	char str1[100];
	char str2[100];

	while (1)
	{
		cout << "두 개의 숫자 입력: ";
		cin >> str1 >> str2;

		try
		{
			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break;
		}
		catch (char ch)
		{
			cout << "문자 " << ch << "가 입력되었습니다." << endl;
			cout << "재입력 진행합니다." << endl << endl;
		}
	}
	cout << "프로그램을 종료합니다." << endl;
	return 0;
}
*/

/*	스택 풀기
* 다음은 예외가 발생할 수밖에 없도록 구현된 코드
#include <iostream>
using namespace std;

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void)
{
	try
	{
		SimpleFuncOne();
	}
	catch (int expn)
	{
		cout << "예외코드: " << expn << endl;
	}
	return 0;
}

void SimpleFuncOne(void)
{
	cout << "SimpleFuncOne(void)" << endl;
	SimpleFuncTwo();
}

void SimpleFuncTwo(void)
{
	cout << "SimpleFuncTwo(void)" << endl;
	SimpleFuncThree();
}

void SimpleFuncThree(void)
{
	cout << "SimpleFuncThree(void)" << endl;
	throw - 1;
}

함수스택이 다음 순서로 쌓임
함수호출 순서 : main -> SimpleFuncOne -> SimpleFuncTwo -> SimpleFuncThree
SimpleFuncThree 함수에서는 무조건 예외 발생
try~catch문이 main 함수에 정의되어 있어서, 여기서 발생한 예외데이터가 '역순'으로 전달됨
그 과정에서 함수스택이 풀림.
*/


/*	함수를 정의할 때에는 함수 내에서 발생 가능한 예외의 종류를 다음과 같이 명시해주는 것이 좋음.
int Func(int num) throw (int, char)
{
	...
}

위처럼 throw 선언이 되면,

try
{
	...
	Func(20);
	...
}
catch(int expn) { ... }
catch(char expn) { ... }

이처럼 함수의 호출문 구성 가능!
*/

// 예외객체 - 예외발생을 알리는데 사용하는 객체
// 예외 클래스 - 예외객체의 생성을 위해 정의된 클래스
/*
#include <iostream>
#include <cstring>
using namespace std;

class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;
};

class DepositException : public AccountException		// 예외 클래스
{
private:
	int reqDep;
public:
	DepositException(int money) : reqDep(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: " << reqDep << "는 입금불가]" << endl;
	}
};

class WithdrawException : public AccountException		// 예외 클래스
{
private:
	int balance;
public:
	WithdrawException(int money) : balance(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[예외 메시지: 잔액" << balance << ", 잔액부족" << endl;
	}
};

class Account
{
private:
	char accNum[50];
	int balance;
public:
	Account(const char* acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw (AccountException)	// 상속에 의해서 DepositException 객체도 AccountException 객체로 간주되기 때문에 이러한 선언 가능
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	void Withdraw(int money) throw (AccountException)	// 상속에 의해서 WithdrawException 객체도 AccountException 객체로 간주되기 때문에 이러한 선언 가능
	{
		if (money > balance)
			throw WithdrawException(balance);
		balance += money;
	}
	void ShowMyMoney()
	{
		cout << "잔고: " << balance << endl << endl;
	}
};

int main(void)
{
	Account myAcc("56789-827120", 5000);

	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (AccountException& expn)		// 예외객체를 복사할 필요가 없기 때문에 참조자를 선언함.
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (AccountException& expn)		// 예외객체를 복사할 필요가 없기 때문에 참조자를 선언함.
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();
	return 0;
}
*/

/*	new 연산자에 의해서 발생하는 예외
#include <iostream>
#include <new>
using namespace std;

int main(void)
{
	int num = 0;

	try
	{
		while(1)
		{
			num++;
			cout << num << "번째 할당 시도" << endl;
			new int[10000][10000];
		}
	}
	catch(bad_alloc &bad)
	{
		cout << bad.what() << endl;		// what 함수는 예외의 원인정보를 문자열의 형태로 반환
		cout << "더 이상 할당 불가!" << endl;
	}
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

class AAA
{
public:
	void Show() { std::cout << "AAA 예외!" << std::endl; }
};

class BBB : public AAA
{
public:
	void Show() { std::cout << "BBB 예외!" << std::endl; }
};

class CCC : public BBB
{
public:
	void Show() { std::cout << "CCC 예외!" << std::endl; }
};

void ExceptionGenerator(int expn)
{
	if(expn == 1)
		throw AAA();
	else if(expn == 2)
		throw BBB();
	else
		throw CCC();
}

int main()
{
	try
	{
		ExceptionGenerator(3);
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	// 의도하지 않은 결과 출력
	catch(AAA& expn)
	{
		std::cout << "catch AAA" << std::endl;
		expn.Show();
	}
	catch(BBB& expn)		// 이 catch 블록 실행 X
	{
		std::cout << "catch BBB" << std::endl;
		expn.Show();
	}
	catch(CCC& expn)		// 이 catch 블록 실행 X
	{
		std::cout << "catch CCC" << std::endl;
		expn.Show();
	}
	
	// 의도한 결과 출력
	catch(CCC& expn)
	{
		std::cout << "catch CCC" << std::endl;
		expn.Show();
	}
	catch(BBB& expn)
	{
		std::cout << "catch BBB" << std::endl;
		expn.Show();
	}
	catch(AAA& expn)
	{
		std::cout << "catch AAA" << std::endl;
		expn.Show();
	}
	// BBB 객체는 일종의 AAA 객체이지만, AAA 객체가 일종의 BBB 객체는 아니며,
	// CCC 객체는 일종의 AAA 객체이지만, AAA 객체가 일종의 CCC 객체는 아니기 때문에, 원하는 결과 출력

	return 0;
}
*/

