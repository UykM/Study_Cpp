/*
#include <iostream>
using namespace std;

// 유도 클래스의 객체 생성과정에서는 생성자가 두 번 호출됨

class SoBase	// 기초(base) 클래스
{
private:
	int baseNum;
public:
	SoBase() : baseNum(20)
	{
		cout << "SoBase()" << endl;
	}
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
};

class SoDerived : public SoBase		// 유도(derived) 클래스
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30)			// 기초 클래스의 생성자 호출 언급 X
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) : derivNum(n)		// 기초 클래스의 생성자 호출 언급 X
	{
		cout << "SoDerived(int n)" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)	// n1 을 인자로 받는 기초 클래스의 생성자 호출 명시
	{
		cout << "SoDerived(int n1, int n2)" << endl;

	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};

int main(void)
{
	cout << "case1..... " << endl;
	SoDerived dr1;				// 유도 클래스의 void 생성자 호출
								// 기초 클래스의 생성자 호출에 대해서 아무런 내용 명시 X -> 기초(base) 클래스의 void 생성자를 대신 호출
	dr1.ShowDerivData();
	cout << "---------------------" << endl;
	cout << "case2..... " << endl;
	SoDerived dr2(12);			// 유도 클래스의 생성자 SoDerived(int n) 호출
								// 기초 클래스의 생성자 호출에 대해서 아무런 내용 명시 X -> 기초(base) 클래스의 void 생성자를 대신 호출
	dr2.ShowDerivData();
	cout << "---------------------" << endl;
	cout << "case3..... " << endl;
	SoDerived dr3(23, 24);		// 유도 클래스의 생성자 SoDerived(int n1, int n2) 호출
								// 기초 클래스의 생성자 호출을 위해 이니셜라이저를 살펴보면 SoBase(n1)이 있음.
								// 매개변수 n1 으로 전달된 값을 인자로 전달받을 수 있는 SoBase 클래스(기초 클래)의 생성자 호출
	dr3.ShowDerivData();
	
	return 0;
}
*/

/* 생성자가 두 번 호출되듯이 유도 클래스의 객체 소멸과정에서도 소멸자가 두 번 호출됨.

#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase() : " << baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived(int n) : SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << endl;
	}
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
};

int main(void)
{
	SoDerived drv1(15);		
	SoDerived drv2(27);
	return 0;
}

실행 결과
SoBase() : 15
SoDerived() : 15
SoBase() : 27
SoDerived() : 27
~SoDerived() : 27     // 유도 클래스(SoDerived)의 소멸자가 먼저 진행된 후에, 기초 클래스(SoBase)의 소멸자가 진행됨.
~SoBase() : 27
~SoDerived() : 15
~SoBase() : 15
*/


// 유도 클래스의 생성자 및 소멸자 정의의 모델인 예제
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Person
{
private:
	char* name;
public:
	Person(const char* myname)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	~Person()
	{
		delete[]name;
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
};

class UnivStudent : public Person
{
private:
	char* major;
public:
	UnivStudent(const char* myname, const char* mymajor)
		: Person(myname)
	{
		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}
	~UnivStudent()
	{
		delete[]major;
	}
	void WhoAreYou() const
	{
		WhatYourName();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent st1("Kim", "Mathmatics");
	st1.WhoAreYou();
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();
	return 0;
}