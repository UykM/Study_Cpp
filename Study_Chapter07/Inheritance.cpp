#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

/*
Person				<->			UnivStudent
상위 클래스						하위클래스		
기초(base) 클래스				유도(derived) 클래스
슈퍼(super) 클래스				서브(sub) 클래스
부모 클래스						자식 클래스
*/

class Person		
{
private:
	int age;		// 나이
	char name[50];	// 이름
public:
	Person(int myage, const char* myname) : age(myage)
	{
		strcpy(name, myname);
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old" << endl;
	}
};

class UnivStudent : public Person		// Person 클래스의 상속을 의미.
{
private:
	char major[50];		// 전공
public:
	UnivStudent(const char* myname, int myage, const char* mymajor)		// UnivStudent 객체가 생성되면, 그 객체 안에는 Person 의 멤버변수(age, name), UnivStudent 의 멤버변수(major) 모두 존재하게 됨.
		: Person(myage, myname)								// 따라서 상속을 받는 클래스(UnivStudent 클래스) 의 생성자는 자신이 상속한 클래스(Person 클래스)의 멤버(age, name) 까지 초기화해야 할 의무가 있음.
															// 초기화할 땐, 멤버의 초기화를 목적으로 정의된 생성자를 통해서 초기화하는 것이 가장 안정적!
	{
		WhatYourName();			// 두 함수 모두 Person 클래스를 상속했기 때문에 사용 가능.
		HowOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.HowOldAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.HowOldAreYou();
	return 0;
}
