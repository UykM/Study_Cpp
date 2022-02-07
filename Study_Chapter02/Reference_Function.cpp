#include <iostream>
using namespace std;

/*
void SwapByValue(int num1, int num2)     // Call-by-value�� ���·� ���ǵ� �Լ�
{										   : �Լ��� ���ο��� �Լ��ܺο� ����� ������ ������ �Ұ���.
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main(void)
{
	int val1 = 10;
	int val2 = 20;
	SwapByValue(val1, val2);
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;
}

��°��          // val1 �� val2 �� ����� ���� �ٲ��� ����
10
20
*/

void SwapByValue(int* num1, int* num2)		// Call-by-reference ���·� ���ǵ� �Լ�
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main(void)
{
	int val1 = 10;
	int val2 = 20;
	SwapByValue(&val1, &val2);
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;
	return 0;
}

/*
void SwapByValue(int &num1, int &num2)          // �����ڴ� ����� ���ÿ� ������ �ʱ�ȭ�Ǿ�� ���� �ʳ�?
{                                               // -> �Լ�ȣ�� �� ���޵Ǵ� ���ڷ� �ʱ�ȭ�� �ϰڴٴ� �ǹ��� ����
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main(void)
{
	int val1 = 10;
	int val2 = 20;
	SwapByValue(val1, val2);
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;
	return 0;
}
*/

// �������� ���� 
// - �ּ��� �Լ��� ������ Ȯ���ؾ� �ϰ�, 
// Ȯ�ΰ�� �����ڰ� �Ű������� ���� �������� �Լ��� ��ü���� Ȯ���ؼ� �����ڸ� ���� ���� ������ �Ͼ���� Ȯ��.
// �ٷ� ���� ������ �����ڸ� ���� ���� ������ �Ͼ�� ����
// �̸� �����ϱ� ���� �����ڸ� const�� ���� -> �Լ��� ������ ���� ���� ������ �̷����� ������ �� �� �ִ�.
// void HappyFunc(const int &ref) { ... }  :  ������ ref�� ���� ���� ���� X


/*
int &RefRetFuncOne(int &ref)           // ��ȯ���� ������(Refrence Type)�� ���
{
	ref++;
	return ref;
}

int RefRetFucnONe(int &ref)            // �����ڸ� ��ȯ�ص� ��ȯ���� �������� �ƴ� ���
{
	ref++;
	return ref;
}
*/
