// int�� ������ �Ҵ�				: int * ptr1 = new int;
// double�� ������ �Ҵ�				: double * ptr2 = new double;
// ���̰� 3�� int�� �迭�� �Ҵ�		: int * arr1 = new int[3];
// ���̰� 7�� double�� �迭�� �Ҵ�  : double * arr2 = new arr2[7];

// �ռ� �Ҵ��� int�� ������ �Ҹ�	: delet ptr1;
// �ռ� �Ҵ��� double�� ������ �Ҹ� : delet ptr2;
// �ռ� �Ҵ��� int�� �迭�� �Ҹ�	: delet []arr1;
// �ռ� �Ҵ��� double�� �迭�� �Ҹ� : delet []arr2;

#include <iostream>
#include <cstring>
#pragma warning(disable:4996) // C4996������ ����
using namespace std;

char* MakeStrAdr(int len)
{
	char* str = new char[len];
	return str;
}

int main(void)
{
	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");          // strlen  : ���ڿ��� ���� ���
	cout << str << endl;					// strcat  : ���ڿ��� �ڿ� �����̱�
	delete[]str;							// strcpy  : ���ڿ� ����
	return 0;								// strcmp  : ���ڿ��� ��				
}
