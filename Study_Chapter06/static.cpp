/*
���������� ����� static �� �ǹ� 
-> ����� ���� �������� ������ ����ϰڴٴ� �ǹ�

�Լ� ���� ����� static �� �ǹ�
-> �ѹ��� �ʱ�ȭ�ǰ�, ���������� �޸� �Լ��� ���������� �Ҹ���� �ʴ´�.

#include <iostream>
using namespace std;

void Counter()
{
	static int cnt;				// static ������ ���������� ���������� �ʱ�ȭ���� ������ 0���� �ʱ�ȭ�ȴ�.
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for(int i = 0; i<10; i++)
		Counter();
	return 0;
}

���� ���				// static ���� cnt �� �ش� �Լ��� ȣ��� ������ ���Ӱ� �Ҵ�Ǵ� ���������� �ƴ϶� �Ҹ���� �ʴ´�.
Current cnt: 1
Current cnt: 2
Current cnt: 3
Current cnt: 4
...
*/


// ���������� �ʿ��� ��Ȳ - static �������(Ŭ���� ����)
#include <iostream>
using namespace std;

// �Ʒ��� �� ������ ���� Ŭ������ ��ü���� �����ϴ� �����̱⿡, �Ʒ�ó�� ���������� ����� �ÿ� ������ ����ų ������ �ſ� ����.
// int simObjCnt = 0;		// SoSimple ��ü���� �����ϴ� ����
// int cmxObjCnt = 0;		// SoComplex ��ü���� �����ϴ� ����
// ����, static ��������� �����Ѵٸ� ������ ����ų ������ ������ �� ����.

class SoSimple
{
private:
	static int simObjCnt;		 // static �������(Ŭ���� ����)�� ����
public:
	SoSimple()
	{
		// simObjCnt = 0;		�̷��� ������� static ��������� �ʱ�ȭ (X)
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};
int SoSimple::simObjCnt = 0;		// static ���� �ʱ�ȭ ��� - Ŭ���� �ܺο��� �ʱ�ȭ �ϴ� ������?
									// ���� simObjCnt �� ���� static ��������� ��ü�� ������ �� ���ÿ� �����Ǵ� ������ �ƴ϶�,
									// �̹� �޸� ������ �Ҵ��� �̷��� �����̱� ������ �ʱ�ȭ�� ������ ����Ǿ�� ��.

class SoComplex
{
public:
	static int cmxObjCnt;		// static ��������� ����
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;		// SoComplex com2(com1); - ��������� ȣ��
	SoComplex();
}


/* static ��������� ��� ��𼭵� ������ ������ ����!
#include <iostream>
using namespace std;

class SoSimple
{
public:						// private ���� ����� ��쿣, �ش� Ŭ������ ��ü�鸸 ������ ����.
	static int simObjCnt;	// ������, ��ó�� public���� ����� ��쿣, Ŭ������ �̸� �Ǵ� ��ü�� �̸��� ���ؼ� ��𼭵� ������ ����.
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;

int main(void)
{
	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;		// public static ����� ������ ������ �� ù ����ó�� Ŭ������ �̸��� �̿��ؼ� ����
	cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl;				// 2, 3��° ����ó�� �����ϸ� public static ����� �ƴ� ��������� �����ϴ� �Ͱ� ���� ���� �߻�!
	cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;
	return 0;
}

���� ���
0��° SoSimple ��ü
2��° SoSimple ��ü
2��° SoSimple ��ü
2��° SoSimple ��ü
*/

/* static ����Լ� - static ��������� Ư���� ����
- ����� Ŭ������ ��� ��ü�� ����
- pulbic ���� ����Ǹ�, Ŭ������ �̸��� �̿��ؼ� ȣ�� ����

�� ��ü�� ����� ���� X
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
		num1 += n;		// Complie error! - static ����Լ��� Adder ���� ����Լ��� num1 �� ��������. ( ��ü�� ����� �ƴѵ�, ��� ��������� ������ �ϰڴ°�? )
		num2 += n;							
	}
};
int SoSimple::num2 = 0;

// static ����Լ� �������� static ��������� static static ����Լ��� ȣ�� ����!

// �̷��� Ư���� ���� static ��������� static ����Լ��� Ȱ���Ѵٸ� ���������� �����Լ��� ��ü�� �� ����.
*/

/* const static ���
// Chapter04 ���� �����ߵ���, Ŭ���� ���� ����� const �������(���)�� �ʱ�ȸ�� Initializer �� ���ؼ��� ����.
// ������, ���� ����ó�� const static ���� ����Ǵ� �������(���)�� ����� ���ÿ� �ʱ�ȭ ����!

class CountryArea
{
public:
	const static int RUSSIA		=1707540;
	const static int CANADA		=998467;
	const static int CHINA		=957290;
	const static int SOUTH_KOREA	=9922;
};

*/

/* Ű���� mutable (const �� explicit Ű����� �޸� ������ ����� �󵵼��� ����� �ϴ� Ű����) 
- const �Լ� �������� ���� ������ ���������� ����Ѵٴ� �ǹ�

#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2;	// const �Լ��� ���� ���ܸ� �д�!
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
		// num2 �� ���� num1 �� ������ ��ȯ ( �ݴ�� num1 = num2 (X) )
		// ����, num1 = num2; �� ���� ���Կ����� �Ųٷ� �����ϴ� ��Ȳ�� ������ �� ����.
		// �̷��� ���鿡�� ���� mutable �� ���� ���� �� �ְ�����,
		// mutable �� ������ ����� C++�� �־ �� �߿伺�� �������� Ű������ const�� ������ �ǹ̾��� ��.
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

������
1, 2
1, 1


*/