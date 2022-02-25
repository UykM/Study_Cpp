// ��ü�� �����Ǹ� ��������� ��ü ���� ����������,
// ����Լ�(member function)�� �޸��� �� ������ ������ ��ġ�ϰ�, �� �Լ��� ���ǵ� Ŭ������ ��� ��ü�� �̸� �����ϴ� ���¸� ����.

// �����Լ�(virtual function)�� ���ۿ���
#include <iostream>
using namespace std;

class AAA
{
private:
	int num1;	// �������� ����
public:
	virtual void Func1() { cout << "Func1" << endl; }
	virtual void Func2() { cout << "Func2" << endl; }
};

class BBB : public AAA
{
private:
	int num2;	// �������� ����
public:
	virtual void Func1() { cout << "BBB::Func1" << endl; }
	void Func3() { cout << "Func3" << endl; }
};

// �����Լ� ���̺��� ��ü�� ������ ������� �޸� ������ �Ҵ��.
int main(void)
{
	AAA* aptr = new AAA();		// AAA ��ü���� AAA Ŭ������ �����Լ� ���̺��� �ּ� ���� ����
	aptr->Func1();

	BBB* bptr = new BBB();		// BBB ��ü���� BBB Ŭ������ �����Լ� ���̺��� �ּ� ���� ����
	bptr->Func1();				// BBB Ŭ������ �����Լ� ���̺��� �����ǰ�, BBB Ŭ������ Func1 �Լ��� ����Ǵµ�, 
								// BBB Ŭ������ �����Լ� ���̺��� �������̵� �� AAA Ŭ������ Func1 �Լ��� ���� ���� X
	return 0;
}