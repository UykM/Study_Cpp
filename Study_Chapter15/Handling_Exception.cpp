/*
* try ��ϰ� catch ����� �׻� �̾ �����ؾ���.
* try ����� �׾ȿ� ���Ե� ������ ������� ����
* try ��� ������ ���ܰ� �߻����� ������ catch ��� ���ĸ� ����
* try ��� ������ ���ܰ� �߻��ϸ�, ���ܰ� �߻��� ���� ������ ������ try ������ �ǳʶ�.
try
{
	// ���ܹ߻� ��������
	if( ... )
		throw -1;	// int�� ���� ������ �߻�!
}
catch(ó���� ������ ���� ���)		// catch ����� ���̻��� �̾ �� �� ����!
{
	// ����ó�� �ڵ��� ����
}
// catch(char expn) { ... }	 // char�� ���� �����͸� �����϶�!
// �� ���, ���� �������� �ڷ����� catch�� �Ű����� ���� ��ġ���� ������,
// �ڷ����� ����ġ�� ���� ���ܴ� ó������ ����(catch ������� ���� ���� X).

throw expn;		// expn �� ����, ��� �׸��� ��ü �� ǥ�� ������ ��� �����Ͱ� �� �� ����.
				// expn : ����, ���ܰ�ü, ���� ������
*/

/*	������ �߻��� ó���� ���� ���� �Ϲ����� ��
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
		cout << "�� ���� ���� �Է�: ";
		cin >> str1 >> str2;

		try
		{
			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break;
		}
		catch (char ch)
		{
			cout << "���� " << ch << "�� �ԷµǾ����ϴ�." << endl;
			cout << "���Է� �����մϴ�." << endl << endl;
		}
	}
	cout << "���α׷��� �����մϴ�." << endl;
	return 0;
}
*/

/*	���� Ǯ��
* ������ ���ܰ� �߻��� ���ۿ� ������ ������ �ڵ�
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
		cout << "�����ڵ�: " << expn << endl;
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

�Լ������� ���� ������ ����
�Լ�ȣ�� ���� : main -> SimpleFuncOne -> SimpleFuncTwo -> SimpleFuncThree
SimpleFuncThree �Լ������� ������ ���� �߻�
try~catch���� main �Լ��� ���ǵǾ� �־, ���⼭ �߻��� ���ܵ����Ͱ� '����'���� ���޵�
�� �������� �Լ������� Ǯ��.
*/


/*	�Լ��� ������ ������ �Լ� ������ �߻� ������ ������ ������ ������ ���� ������ִ� ���� ����.
int Func(int num) throw (int, char)
{
	...
}

��ó�� throw ������ �Ǹ�,

try
{
	...
	Func(20);
	...
}
catch(int expn) { ... }
catch(char expn) { ... }

��ó�� �Լ��� ȣ�⹮ ���� ����!
*/

// ���ܰ�ü - ���ܹ߻��� �˸��µ� ����ϴ� ��ü
// ���� Ŭ���� - ���ܰ�ü�� ������ ���� ���ǵ� Ŭ����
/*
#include <iostream>
#include <cstring>
using namespace std;

class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;
};

class DepositException : public AccountException		// ���� Ŭ����
{
private:
	int reqDep;
public:
	DepositException(int money) : reqDep(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[���� �޽���: " << reqDep << "�� �ԱݺҰ�]" << endl;
	}
};

class WithdrawException : public AccountException		// ���� Ŭ����
{
private:
	int balance;
public:
	WithdrawException(int money) : balance(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[���� �޽���: �ܾ�" << balance << ", �ܾ׺���" << endl;
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
	void Deposit(int money) throw (AccountException)	// ��ӿ� ���ؼ� DepositException ��ü�� AccountException ��ü�� ���ֵǱ� ������ �̷��� ���� ����
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	void Withdraw(int money) throw (AccountException)	// ��ӿ� ���ؼ� WithdrawException ��ü�� AccountException ��ü�� ���ֵǱ� ������ �̷��� ���� ����
	{
		if (money > balance)
			throw WithdrawException(balance);
		balance += money;
	}
	void ShowMyMoney()
	{
		cout << "�ܰ�: " << balance << endl << endl;
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
	catch (AccountException& expn)		// ���ܰ�ü�� ������ �ʿ䰡 ���� ������ �����ڸ� ������.
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (AccountException& expn)		// ���ܰ�ü�� ������ �ʿ䰡 ���� ������ �����ڸ� ������.
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();
	return 0;
}
*/

/*	new �����ڿ� ���ؼ� �߻��ϴ� ����
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
			cout << num << "��° �Ҵ� �õ�" << endl;
			new int[10000][10000];
		}
	}
	catch(bad_alloc &bad)
	{
		cout << bad.what() << endl;		// what �Լ��� ������ ���������� ���ڿ��� ���·� ��ȯ
		cout << "�� �̻� �Ҵ� �Ұ�!" << endl;
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
	void Show() { std::cout << "AAA ����!" << std::endl; }
};

class BBB : public AAA
{
public:
	void Show() { std::cout << "BBB ����!" << std::endl; }
};

class CCC : public BBB
{
public:
	void Show() { std::cout << "CCC ����!" << std::endl; }
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
	// �ǵ����� ���� ��� ���
	catch(AAA& expn)
	{
		std::cout << "catch AAA" << std::endl;
		expn.Show();
	}
	catch(BBB& expn)		// �� catch ��� ���� X
	{
		std::cout << "catch BBB" << std::endl;
		expn.Show();
	}
	catch(CCC& expn)		// �� catch ��� ���� X
	{
		std::cout << "catch CCC" << std::endl;
		expn.Show();
	}
	
	// �ǵ��� ��� ���
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
	// BBB ��ü�� ������ AAA ��ü������, AAA ��ü�� ������ BBB ��ü�� �ƴϸ�,
	// CCC ��ü�� ������ AAA ��ü������, AAA ��ü�� ������ CCC ��ü�� �ƴϱ� ������, ���ϴ� ��� ���

	return 0;
}
*/

