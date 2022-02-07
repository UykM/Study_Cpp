#include <iostream>
using namespace std;

void SwapPointer(int* (&pref1), int* (&pref2))
{
	int* ptr = pref1;
	pref1 = pref2;
	pref2 = ptr;
}

int main(void)
{
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;

	SwapPointer(ptr1, ptr2);              // pref1 : 포인터 변수 ptr1 의 참조자, pref2 : 포인터 변수 ptr2의 참조자
	cout << "ptr1: " << *ptr1 << endl;
	cout << "ptr2: " << *ptr2 << endl;
}