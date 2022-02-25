// ���߻��(Multiple Inheritance)
// ���߻���� ���� ������ �������� �ϴ� ����
/*
#include <iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFunc() { cout << "BaseOne" << endl; }	
};

class BaseTwo
{
public:
	void SimpleFunc() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void ComplexFunc()
	{
		BaseOne::SimpleFunc();		// BaseOne Ŭ��������, BaseTwo Ŭ�������� SimpleFunc��� �̸��� ����Լ��� �����ϱ� ������,
		BaseTwo::SimpleFunc();		// �� ���� ����ϴ� ���� Ŭ�������� SImpleFunc �Լ��� ȣ���� ������, �̷��� ��� Ŭ������ ���ǵ� �Լ��� ȣ���� ���ϴ��� ���!
	}
};

int main(void)
{
	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}
*/

// ���� ���(Virtual Inheritance)
#include <iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "Base Constructor" << endl; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne : virtual public Base
{
public:
	MiddleDerivedOne() : Base()		// ���� Ŭ����(Base)�� ������ ȣ���� ������� �ʾƵ� ������, ���� Ŭ������ �����ڰ� ȣ����� �����ϱ� ���� ���
	{
		cout << "MIddleDerivedOne ConsTructor" << endl;
	}
	void MiddleFuncOne()
	{
		SimpleFunc();		// Base Ŭ���� ���
		cout << "MiddleDerivedOne" << endl;
	}
};

class MiddleDerivedTwo : virtual public Base
{
public:
	MiddleDerivedTwo() : Base()		// ���� Ŭ����(Base)�� ������ ȣ���� ������� �ʾƵ� ������, ���� Ŭ������ �����ڰ� ȣ����� �����ϱ� ���� ���
	{
		cout << "MiddleDerivedTwo Constructor" << endl;
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();		// Base Ŭ���� ���
		cout << "MIddleDerivedTwo" << endl;
	}
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo	// virtual ������ ���� ���� ���¿��� LastDerived Ŭ������ ��ü�� �����Ǹ�, Base Ŭ������ ����� �� �� �����ϰ� ��.
{																		// ��, Base Ŭ������ �� �� ���� (����)����ϰԲ� �ϴ� ���� 'virtual inheritance' ��.
public:
	LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
	{
		cout << "LastDerivedConstructor" << endl;
	}
	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();		// MiddleDerivedOne Ŭ������ MiddleDerivedTwo Ŭ������ Base Ŭ����(���� Ŭ����)�� ���������� �ʾҴٸ�,
	}						// ComplexFunc �Լ� ������ �̸��� ������ SimpleFunc �Լ� ȣ�� �Ұ���
};							// MiddleDerivedOne::SimpleFunc()
							// MiddleDerivedTwo::SimpleFunc() 
							// �̷� ������ ��� Ŭ������ ���ؼ� ���� ����� Base Ŭ������ ����Լ��� ȣ���� ������ ����ؾ� ��.

int main(void)
{
	cout << "��ü���� �� ....." << endl;
	LastDerived ldr;						// LastDerived ��ü ������ Base Ŭ������ �����ڰ� �� ���� ȣ���. virtual ����� ������ ����.
	cout << "��ü���� �� ....." << endl;
	ldr.ComplexFunc();		 
	return 0;
}

/* ���� ���
��ü���� �� .....
Base Constructor					// Base Ŭ������ �����ڰ� �� ���� ȣ���.	
MiddleDerivedOne Constructor
// Base Constructor		virtual ������ ���� ���� ���, Base Ŭ������ �����ڴ� �� �� ȣ���.
MiddleDerivedTwo Constructor
LastDerived Constructor
��ü���� �� .....
BaseOne
MiddleDerivedOne
BaseOne
MiddleDerivedTwo
BaseOne
*/