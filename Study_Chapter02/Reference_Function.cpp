#include <iostream>
using namespace std;

/*
void SwapByValue(int num1, int num2)     // Call-by-value의 형태로 정의된 함수
{										   : 함수의 내부에서 함수외부에 선언된 변수에 접근이 불가능.
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

출력결과          // val1 과 val2 에 저장된 값이 바뀌지 않음
10
20
*/

void SwapByValue(int* num1, int* num2)		// Call-by-reference 형태로 정의된 함수
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
void SwapByValue(int &num1, int &num2)          // 참조자는 선언과 동시에 변수로 초기화되어야 하지 않나?
{                                               // -> 함수호출 시 전달되는 인자로 초기화를 하겠다는 의미의 선언
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

// 참조자의 단점 
// - 최소한 함수의 원형을 확인해야 하고, 
// 확인결과 참조자가 매개변수의 선언에 와있으면 함수의 몸체까지 확인해서 참조자를 통한 값의 변경이 일어나는지 확인.
// 바로 위의 예제가 참조자를 통한 값의 변경이 일어나는 예제
// 이를 보완하기 위해 참조자를 const로 선언 -> 함수의 원형만 봐도 값의 변경이 이뤄지지 않음을 알 수 있다.
// void HappyFunc(const int &ref) { ... }  :  참조자 ref를 통한 값의 변경 X


/*
int &RefRetFuncOne(int &ref)           // 반환형이 참조형(Refrence Type)인 경우
{
	ref++;
	return ref;
}

int RefRetFucnONe(int &ref)            // 참조자를 반환해도 반환형은 참조형이 아닌 경우
{
	ref++;
	return ref;
}
*/
