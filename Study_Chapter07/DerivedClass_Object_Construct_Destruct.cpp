/*
#include <iostream>
using namespace std;

// ���� Ŭ������ ��ü �������������� �����ڰ� �� �� ȣ���

class SoBase	// ����(base) Ŭ����
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

class SoDerived : public SoBase		// ����(derived) Ŭ����
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30)			// ���� Ŭ������ ������ ȣ�� ��� X
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) : derivNum(n)		// ���� Ŭ������ ������ ȣ�� ��� X
	{
		cout << "SoDerived(int n)" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)	// n1 �� ���ڷ� �޴� ���� Ŭ������ ������ ȣ�� ���
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
	SoDerived dr1;				// ���� Ŭ������ void ������ ȣ��
								// ���� Ŭ������ ������ ȣ�⿡ ���ؼ� �ƹ��� ���� ��� X -> ����(base) Ŭ������ void �����ڸ� ��� ȣ��
	dr1.ShowDerivData();
	cout << "---------------------" << endl;
	cout << "case2..... " << endl;
	SoDerived dr2(12);			// ���� Ŭ������ ������ SoDerived(int n) ȣ��
								// ���� Ŭ������ ������ ȣ�⿡ ���ؼ� �ƹ��� ���� ��� X -> ����(base) Ŭ������ void �����ڸ� ��� ȣ��
	dr2.ShowDerivData();
	cout << "---------------------" << endl;
	cout << "case3..... " << endl;
	SoDerived dr3(23, 24);		// ���� Ŭ������ ������ SoDerived(int n1, int n2) ȣ��
								// ���� Ŭ������ ������ ȣ���� ���� �̴ϼȶ������� ���캸�� SoBase(n1)�� ����.
								// �Ű����� n1 ���� ���޵� ���� ���ڷ� ���޹��� �� �ִ� SoBase Ŭ����(���� Ŭ��)�� ������ ȣ��
	dr3.ShowDerivData();
	
	return 0;
}
*/

/* �����ڰ� �� �� ȣ��ǵ��� ���� Ŭ������ ��ü �Ҹ���������� �Ҹ��ڰ� �� �� ȣ���.

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

���� ���
SoBase() : 15
SoDerived() : 15
SoBase() : 27
SoDerived() : 27
~SoDerived() : 27     // ���� Ŭ����(SoDerived)�� �Ҹ��ڰ� ���� ����� �Ŀ�, ���� Ŭ����(SoBase)�� �Ҹ��ڰ� �����.
~SoBase() : 27
~SoDerived() : 15
~SoBase() : 15
*/


// ���� Ŭ������ ������ �� �Ҹ��� ������ ���� ����
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