#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref)					// int &ref = num1;	- 인자의 전달과정에서 일어난 일
{
	ref++;
	return ref;									// int &num2 = ref;  - 함수의 반환과 반환 값의 저장에서 일어나는 일
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
int& RefRetFuncOne(int& ref)			// 참조형으로 반환
{										// int &ref = num1;	- 인자의 전달과정에서 일어난 일
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = RefRetFuncOne(num1);      // 하지만, 참조자가 아닌 일반변수 num2를 선언해서 반환값을 저장
										 // int num2 = ref; - 함수의 반환과 반환 값의 저장에서 일어나는 일

										 num1++;
	num2+=100;                           // num1 과 num2 는 다른 변수
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}
*/

// 위에 두 개의 예제처럼, 반환형이 참조형인 경우, 반환 값을 무엇으로 저장하느냐에 따라서 다른 결과가 나타남.


/*
int RefRetFuncTwo(int& ref)				// 기본자료형으로 반환
{										// int &ref = num1;	- 인자의 전달과정에서 일어난 일
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = RefRetFuncTwo(num1);      // 하지만, 참조자가 아닌 일반변수 num2를 선언해서 반환값을 저장
										 // int num2 = ref; - 함수의 반환과 반환 값의 저장에서 일어나는 일
										 // int& num2 = RefRecFuncTwo(num1); (X)  -> 반환값이 상수이기떄문에 불가능.
	num1++;

	num2+=100;                           // num1 과 num2 는 다른 변수
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}
*/

/* 지역변수를 참조형으로 반환해선 안된다.

int& RetuRefFunc(int n)			// 반환형이 참조형
{
	int num = 20;
	num += n;
	return num;                 // 지역변수를 참조형으로 반환
}

int main(void)
{
	...

	int &ref = RetuRefFunc(10);     // 이는 곧 int &ref = num; 이기 때문에, 지역변수 num에 ref라는 또 하나의 이름이 붙게 됨.
									// 게다가 함수가 반환되면 정작 지역변수 num은 소멸.
	...
}
*/


/* const를 활용해 참조자가 상수를 참조

	const int num = 20;			// 변수 num 을 상수화
	// int &ref = num;  (X)    -> 상수화한 변수 num을 참조하는 것은 불가능
	const int &ref = num;       // const int &ref = 50; 이와 같이 상수도 참조 가능
	ref+=10;
	cout << num << endl;

	출력결과
	30
*/