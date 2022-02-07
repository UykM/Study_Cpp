#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref)					// int &ref = num1;	- ������ ���ް������� �Ͼ ��
{
	ref++;
	return ref;									// int &num2 = ref;  - �Լ��� ��ȯ�� ��ȯ ���� ���忡�� �Ͼ�� ��
}

int main(void)
{
	int num1 = 1;
	int& num2 = RefRetFuncOne(num1);

	num1++;
	num2++;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}

/*
int& RefRetFuncOne(int& ref)			// ���������� ��ȯ
{										// int &ref = num1;	- ������ ���ް������� �Ͼ ��
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = RefRetFuncOne(num1);      // ������, �����ڰ� �ƴ� �Ϲݺ��� num2�� �����ؼ� ��ȯ���� ����
										 // int num2 = ref; - �Լ��� ��ȯ�� ��ȯ ���� ���忡�� �Ͼ�� ��

										 num1++;
	num2+=100;                           // num1 �� num2 �� �ٸ� ����
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}
*/

// ���� �� ���� ����ó��, ��ȯ���� �������� ���, ��ȯ ���� �������� �����ϴ��Ŀ� ���� �ٸ� ����� ��Ÿ��.


/*
int RefRetFuncTwo(int& ref)				// �⺻�ڷ������� ��ȯ
{										// int &ref = num1;	- ������ ���ް������� �Ͼ ��
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = RefRetFuncTwo(num1);      // ������, �����ڰ� �ƴ� �Ϲݺ��� num2�� �����ؼ� ��ȯ���� ����
										 // int num2 = ref; - �Լ��� ��ȯ�� ��ȯ ���� ���忡�� �Ͼ�� ��
										 // int& num2 = RefRecFuncTwo(num1); (X)  -> ��ȯ���� ����̱⋚���� �Ұ���.
	num1++;

	num2+=100;                           // num1 �� num2 �� �ٸ� ����
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}
*/

/* ���������� ���������� ��ȯ�ؼ� �ȵȴ�.

int& RetuRefFunc(int n)			// ��ȯ���� ������
{
	int num = 20;
	num += n;
	return num;                 // ���������� ���������� ��ȯ
}

int main(void)
{
	...

	int &ref = RetuRefFunc(10);     // �̴� �� int &ref = num; �̱� ������, �������� num�� ref��� �� �ϳ��� �̸��� �ٰ� ��.
									// �Դٰ� �Լ��� ��ȯ�Ǹ� ���� �������� num�� �Ҹ�.
	...
}
*/


/* const�� Ȱ���� �����ڰ� ����� ����

	const int num = 20;			// ���� num �� ���ȭ
	// int &ref = num;  (X)    -> ���ȭ�� ���� num�� �����ϴ� ���� �Ұ���
	const int &ref = num;       // const int &ref = 50; �̿� ���� ����� ���� ����
	ref+=10;
	cout << num << endl;

	��°��
	30
*/