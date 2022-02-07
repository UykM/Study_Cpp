#include <iostream>
using namespace std;

int main(void)
{
	int num1 = 1020;
	int& num2 = num1;          // num1 과 num2 는 동일한 메모리 공간을 참조하고 있다. 
	// int &num3 = num1; ...    참조자의 수에는 제한이 없다.
	// int &num4 = num2;        참조자를 대상으로도 참조자를 선언 가능.
	// int &ref = 20; (X)       참조자는 변수에 대해서만 선언이 가능.
	// int &ref       (X)       참조자는 선언됨과 동시에 반드시 누군가를 참조해야 한다.
	// int &ref = NULL  (X)     참조자를 선언하면서 NULL로 초기화하는 것도 불가능.
	num2 = 3047;
	cout << "VAL: " << num1 << endl;
	cout << "REF: " << num2 << endl;

	cout << "VAL: " << &num1 << endl;
	cout << "REF: " << &num2 << endl;
	return 0;
}

/*
	int main(void)
	{
		int arr[3] = {1, 3, 5};
		int &ref1 = arr[0];              // 배열요소는 배열이 아니라 변수로 간주되어 참조자의 선언이 가능.
		int &ref2 = arr[1];
		int &ref3 = arr[2];

		cout << ref1 << endl;
		cout << ref2 << endl;
		cout << ref3 << endl;
		return 0;
	}

	출력결과
	1
	3
	5
*/

/*
	int main(void)
	{
		int num = 12;
		int *ptr = &num;
		int **dptr = &ptr;

		int &ref = num;
		int *(&pref) = ptr;             // 포인터의 변수도 참조자의 선언이 가능.
		int **(&dpref) = dptr;

		cout << ref << endl;
		cout << *pref << endl;
		cout << **dpref << endl;
		return 0;
	}

	출력결과
	12
	12
	12
*/