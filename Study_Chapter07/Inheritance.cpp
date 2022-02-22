#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

/*
Person				<->			UnivStudent
���� Ŭ����						����Ŭ����		
����(base) Ŭ����				����(derived) Ŭ����
����(super) Ŭ����				����(sub) Ŭ����
�θ� Ŭ����						�ڽ� Ŭ����
*/

class Person		
{
private:
	int age;		// ����
	char name[50];	// �̸�
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

class UnivStudent : public Person		// Person Ŭ������ ����� �ǹ�.
{
private:
	char major[50];		// ����
public:
	UnivStudent(const char* myname, int myage, const char* mymajor)		// UnivStudent ��ü�� �����Ǹ�, �� ��ü �ȿ��� Person �� �������(age, name), UnivStudent �� �������(major) ��� �����ϰ� ��.
		: Person(myage, myname)								// ���� ����� �޴� Ŭ����(UnivStudent Ŭ����) �� �����ڴ� �ڽ��� ����� Ŭ����(Person Ŭ����)�� ���(age, name) ���� �ʱ�ȭ�ؾ� �� �ǹ��� ����.
															// �ʱ�ȭ�� ��, ����� �ʱ�ȭ�� �������� ���ǵ� �����ڸ� ���ؼ� �ʱ�ȭ�ϴ� ���� ���� ������!
	{
		WhatYourName();			// �� �Լ� ��� Person Ŭ������ ����߱� ������ ��� ����.
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
