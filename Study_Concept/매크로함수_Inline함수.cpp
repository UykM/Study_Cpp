#include <iostream>
using namespace std;

/* #define SQUARE(x) ((x)*(x))    // -> ��ũ���Լ� / (x) : ��ȣ�� �ݵ�� �������


int main(void)
{
	cout << SQUARE(5) << endl;
	cout << SQUARE(3.15) << endl;   // ��ũ�� �Լ� : �ڷ����� �������̴� ����
	return 0;
}
*/

inline int SQUARE(int x)         // �ڷ����� ������
{                                // Template <typname T> : ���ø��� �̿��ϸ� �ڷ����� �������� �ʾƵ� ��
	return x * x;				 // inline T Square(T x)
}								 // {
								 //		return x*x;
								 // }

int main(void)
{
	cout << SQUARE(5) << endl;
	cout << SQUARE(12) << endl;
	return 0;
}