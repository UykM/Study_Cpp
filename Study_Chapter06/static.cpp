/*
전역변수에 선언된 static 의 의미 
-> 선언된 파일 내에서만 참조를 허용하겠다는 의미

함수 내에 선언된 static 의 의미
-> 한번만 초기화되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않는다.

#include <iostream>
using namespace std;

void Counter()
{
	static int cnt;				// static 변수는 전역변수와 마찬가지로 초기화하지 않으면 0으로 초기화된다.
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for(int i = 0; i<10; i++)
		Counter();
	return 0;
}

실행 결과				// static 변수 cnt 는 해당 함수가 호출될 때마다 새롭게 할당되는 지역변수가 아니라 소멸되지 않는다.
Current cnt: 1
Current cnt: 2
Current cnt: 3
Current cnt: 4
...
*/


// 전역변수가 필요한 상황 - static 멤버변수(클래스 변수)
#include <iostream>
using namespace std;

// 아래의 두 변수는 각각 클래스의 객체들이 공유하는 변수이기에, 아래처럼 전역변수로 선언될 시에 문제를 일으킬 소지가 매우 높음.
// int simObjCnt = 0;		// SoSimple 객체들이 공유하는 변수
// int cmxObjCnt = 0;		// SoComplex 객체들이 공유하는 변수
// 따라서, static 멤버변수로 선언한다면 문제를 일으킬 소지를 제거할 수 있음.

class SoSimple
{
private:
	static int simObjCnt;		 // static 멤버변수(클래스 변수)로 선언
public:
	SoSimple()
	{
		// simObjCnt = 0;		이러한 방식으로 static 멤버변수를 초기화 (X)
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt = 0;		// static 변수 초기화 방법 - 클래스 외부에서 초기화 하는 이유는?
									// 변수 simObjCnt 와 같은 static 멤버변수는 객체가 생성될 때 동시에 생성되는 변수가 아니라,
									// 이미 메모리 공간에 할당이 이뤄진 변수이기 때문에 초기화는 별도로 진행되어야 함.

class SoComplex
{
public:
	static int cmxObjCnt;		// static 멤버변수로 선언
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;		// SoComplex com2(com1); - 복사생성자 호출
	SoComplex();
}


/* static 멤버변수는 사실 어디서든 접근이 가능한 변수!
#include <iostream>
using namespace std;

class SoSimple
{
public:						// private 으로 선언될 경우엔, 해당 클래스의 객체들만 접근이 가능.
	static int simObjCnt;	// 하지만, 이처럼 public으로 선언될 경우엔, 클래스의 이름 또는 객체의 이름을 통해서 어디서든 접근이 가능.
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;

int main(void)
{
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;		// public static 멤버에 접근할 때에는 이 첫 문장처럼 클래스의 이름을 이용해서 접근
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;				// 2, 3번째 문장처럼 접근하면 public static 멤버가 아닌 멤버변수에 접근하는 것과 같은 오해 발생!
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
	return 0;
}

실행 결과
0번째 SoSimple 객체
2번째 SoSimple 객체
2번째 SoSimple 객체
2번째 SoSimple 객체
*/

/* static 멤버함수 - static 멤버변수의 특성과 동일
- 선언된 클래스의 모든 객체가 공유
- pulbic 으로 선언되면, 클래스의 이름을 이용해서 호출 가능

☆ 객체의 멤버로 존재 X
class SoSimple
{
private:
	int num1;
	static int nu2;
public:
	SoSimple(int n): num1(n)
	{ }
	static void Adder(int n)
	{
		num1 += n;		// Complie error! - static 멤버함수인 Adder 에서 멤버함수인 num1 에 접근했음. ( 객체의 멤버가 아닌데, 어떻게 멤버변수에 접근을 하겠는가? )
		num2 += n;							
	}
};
int SoSimple::num2 = 0;

// static 멤버함수 내에서는 static 멤버변수와 static static 멤버함수만 호출 가능!

// 이러한 특성을 지닌 static 멤버변수와 static 멤버함수을 활용한다면 전역변수와 전역함수를 대체할 수 있음.
*/

/* const static 멤버
// Chapter04 에서 공부했듯이, 클래스 내에 선언된 const 멤버변수(상수)의 초기회는 Initializer 를 통해서만 가능.
// 하지만, 다음 예제처럼 const static 으로 선언되는 멤버변수(상수)는 선언과 동시에 초기화 가능!

class CountryArea
{
public:
	const static int RUSSIA		=1707540;
	const static int CANADA		=998467;
	const static int CHINA		=957290;
	const static int SOUTH_KOREA	=9922;
};

*/

/* 키워드 mutable (const 와 explicit 키워드와 달리 가급적 사용의 빈도수를 낮춰야 하는 키워드) 
- const 함수 내에서의 값의 변경을 예외적으로 허용한다는 의미

#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2;	// const 함수에 대해 예외를 둔다!
public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
	{ }
	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << endl;
	}
	void CopyToNum2() const
	{
		num2 = num1;
		// num2 의 값을 num1 의 값으로 변환 ( 반대로 num1 = num2 (X) )
		// 따라서, num1 = num2; 와 같이 대입연산을 거꾸로 진행하는 상황을 방지할 수 있음.
		// 이러한 측면에서 보면 mutable 을 좋게 평가할 수 있겠지만,
		// mutable 의 과도한 사용은 C++에 있어서 그 중요성을 인정받은 키워드인 const의 선언을 의미없게 함.
	}
};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();
	return 0;
}

실행결과
1, 2
1, 1


*/