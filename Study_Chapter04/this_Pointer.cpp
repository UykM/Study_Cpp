#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

/*
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num=" << num << ", ";
		cout << "address=" << this << endl;
	}

	void ShowSimpleData()
	{
		cout << num << endl;
	}

	SoSimple* GetThisPointer()
	{
		return this;
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();		// sim1 ��ü�� �ּ� ��(ptr1) ���� 
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();					// -> �� �����͸� ���� ���� <-> . �� ���� ����

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();		// sim2 ��ü�� �ּ� ��(ptr2) ����
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();		
	return 0;
}

*/

// this : ��ü�� �����ϴ� ������ , this �� ��������(�Ű�����)�� �ƴ� ��������� ���� ����

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1;		// this->num1 �� ������� num1�� �ǹ�, num1 �� �Ű����� num1�� �ǹ�
		this->num2 = num2;
	}
	/* ��� �̴ϼȾ����������� this ������ ��� �Ұ���
	TwoNumber(int num1, int num2)
		: num1(num1), num2(num2)
	{
	}
	*/
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;			// �Ϲ������� �̷��� ��쿣 this �� ����
		cout << this->num2 << endl;
	}
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}