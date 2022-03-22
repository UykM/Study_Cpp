//	const_cast<T>(expr) : 포인터와 참조자의 const 성향을 제거하는 형 변환이 목적
//	하지만 const 선언의 '값의 변경을 허용하지 않는다'라는 의미를 반감시키기 때문에, 
//	다음 예제처럼 const_cast 연산자의 긍정적인 측면이 잘 드러나는 경우에만 제한적으로 사용해야 함.
#include <iostream>
using namespace std;

void ShowString(char* str)		// void ShowString(const char* str)
{
	cout << str << endl;
}

void ShowAddResult(int& n1, int& n2)
{
	cout << n1 + n2 << endl;
}

int main(void)
{
	const char* name = "Shin Min Kyu";		// char* name = "Shin Min Kyu";		이 경우엔 인자로 전달 가능함. 혼동 X
	ShowString(const_cast<char*>(name));		

	const int& num1 = 100;
	const int& num2 = 200;
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));
	return 0;
}