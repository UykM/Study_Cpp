// 디폴트 대입 연산자
// 멤버 대 멤버의 복사(얕은 복사)를 진행
// 연산자 내에서 동적 할당을 한다면, 그리고 깊은 복사가 필요하다면 직접 정의
// 복사 생성자의 특성과 매우 유하사지만, 호출되는 시점에서 차이가 있음.
/*
#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1=0, int n2=0) : num1(n1), num2(n2)
	{ }
	void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{ }
	void ShowData() { cout << num3 << ", " << num3 << endl; }

	Second& operator=(const Second& ref)
	{
		cout << "Seccond& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main(void)
{
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc;		// fcpy.operator=(fsrc)
	scpy = ssrc;		// scpy.operator=(ssrc)
	fcpy.ShowData();
	scpy.ShowData();

	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;
	sob1 = sob2 = ssrc;

	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return 0;
}
*/

// 디폴트 복사 생성자의 문제 
/*
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}

실핼결과
이름: Lee dong woo
나이: 29
이름: Lee dong woo
나이: 29
called destructor!		// 소멸자가 한 번밖에 호출되지 않음.

// 얕은 복사로 인해서 하나의 문자열이 두 개의 객체가 동시에 참조하는 상황이 벌어지고
// 객체 소멸과정(man2 객체가 소멸)에서 이미 소멸된 문자열("Lee dong woo")을 중복 소멸하는 문제 발생
// 문자열 "Yoon ji yul"은 메모리 누수된 상태로 존재
*/

// 디폴트 대입 연산자의 문제점 (디폴트 복사 생성자와 유사)
// 생성자 내에서 동적 할당을 하는 경우, 디폴트 대입 연산자는 두 가지 문제가 발생
// 이는 깊은 복사를 진행하고, 메모리 누수가 발생하지 않도록깊은 복사에 앞서 메모리 헤체의 과정을 거쳐
// 직접 정의해야함!

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person& operator=(const Person& ref)
	{
		delete[]name;		// 메모리의 누수를 막기 위한 메모리 해체 연산
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}


/* 상속 구조에서의 대입 연산자 호출
* 대입 연산자 = 생성자 X
* 유도 클래스(derived class)의 생성자에는 아무런 명시를 하지 않아도 기초 클래스(base class)의 생성자가 호출됨.
* 유도 클래스의 대입 연산자에는 아무런 명시를 하지 않으면, 기초 클래스의 대입 연산자가 호출 X

#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{ }
	void ShowData() { cout << num1 << ", " << num2 << endl; }

	First& operator=(const First& ref)
	{
		cout << "Frist& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First
{
private:
	int num3, num4;
public:
	Second(int n1, int n2, int n3, int n4) 
		: First(n1, n2), num3(n3), num4(n4)
	{ }
	void ShowData() 
	{ 
		First::ShowData();
		cout << num3 << ", " << num3 << endl; 
	}

	// Seconst& operator=(const Second&) 주석 처리
	Second& operator=(const Second& ref)	// 유도 클래스의 대입 연산자 정의
	{
		cout << "Seccond& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
	
};

int main(void)
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;
	scpy.ShowData();
	return 0;
}

주석처리 한 경우, 실행 결과
First& operator=()
111, 222
333, 444

주석을 해제한 경우, 실행 결과
Second& operator=()
0, 0
333, 444
// 유도 클래스의 대입 연산자 정의에서, 명시적으로 기초 클래스의 대입 연산자 호출문이 없음.
// 때문에, 기초 클래스의 대입 연산자는 호출되지 않아서, 
// 기초 클래스의 멤버변수는 멤버 대 멤버의 복사 대상에서 제외됨

// 따라서 위 예제의 Second 클래스의 대입 연산자는 다음의 형태로 정의되어야 함.
Second& operator=(const Second& ref)
	{
		cout << "Seccond& operator=()" << endl;
		First::operator=(ref);	// 기초 클래스의 대입 연산자 호출을 명령
								// First형 참조자는 First 객체 또는 First를 직접 혹은 간접적으로 상속하는 모든 객체를 참조할 수 있음.

		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
*/


// 대입 연산자와 복사 생성자를 모두 이해하면 이니셜라이저가 성능 향상에 도움을 주는 이유를 알 수 있음.
// 이니셜라이저를 이용하면 선언과 도잇에 초기화가 이뤄지기 때문.