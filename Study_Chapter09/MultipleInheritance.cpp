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
