/*
* 함수 템플릿 정의

template <typename T>			// template <class T>	typename과 class는 같은 의미
T 함수이름(T num1, T num2)		// T는 자료형을 결정짓지 않겠다는 의미로 사용
{								// T라는 문자 대신에 다른 문자 사용 가능
	return num1+num2;
}

★ Point! 
함수 템플릿은 완성된 함수가 아니라 필요한 함수들을 뽑아내기 위한 함수의 틀이라고 기억하기
*/

/*
#include <iostream>
using namespace std;

template <typename T>			// 함수 템플릿 : 함수를 만드는데 사용되는 템플릿!
T Add(T num1, T num2)
{
	return num1 + num2;
}

int Add(int num1, int num2)		// 일반 함수
{
	cout << "Add(int num1, int num2)" << endl;
	return num1 + num2;
}

double Add(double num1, double num2)	// 일반 함수
{
	cout << "Add(double num1, double num2)" << endl;
	return num1 + num2;
}

int main(void)
{
	cout << Add(15, 20) << endl;				// 일반함수 호출
	cout << Add(2.9, 3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;			// 일반함수가 정의되었기 때문에, <int> 표시를 통해서 템프릿 함수의 호출을 명시
	cout << Add<double>(3.14, 2.75) << endl;	// 일반함수가 정의되어있지 않다면, <double> 표시 없이 템플릿 함수 호출 가능!
	return 0;
}

// 템플릿 함수	: 컴파일러가 만들어 내는 함수, 즉 템플릿을 기반으로 만들어지는 함수!
// int Add<int>(int num1, int num2)
// {
//		return num1+num2;
// }
// 함수 템플릿을 정의한 상황에서 일반함수까지 정의하는 것은 바람직하지 않음
// 단지 컴파일러에 의해서 만들어지는 템플릿 함수가 일반함수와 구분된다는 사실을 보여주기 위해 만든 것

*/


/* 둘 이상의 형(Type)에 대해 템플릿 선언하기
#include <iostream>
using namespace std;

template <class T1, class T2>
void ShowData(double num)			// 매개변수 형이 double로 선언되어있기 때문에, 전달되는 인자를 통해서는 T1, T2의 자료형을 결정짓지 못함.
{
cout << (T1)num << ", " << (T2)num << endl;
}

int main(void)
{
	ShowData<char, int>(65);		// 따라서, 이처럼 템플릿 함수의 호출형식을 완전히 갖춰서 호출해야함.
	ShowData<char, int>(67);		// ShowData(65);	이렇게 생략하여 호출 X
	ShowData<char, double>(68.9);	
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	return 0;
}
*/


// 함수 템플릿의 특수화
// 상황에 따라서 템플릿 함수의 구성방법에 예외를 둘 필요가 있음.
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template <>
char* Max(char* a, char* b)		// char* 형 템플릿 함수가 필요한 경우엔, 이 함수를 쓰도록 함. 
{
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template <>
const char* Max(const char* a, const char* b)		// const char* 형 템플릿 함수가 필요한 경우엔, 이 함수를 쓰도록 함.
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;				// char* Max(char*, char*) 템플릿 함수가 정의되어 있지 않다면, 올바른 결과 출력 X
	cout << Max(3.5, 7.5) << endl;	
	cout << Max("Simple", "Best") << endl;		// const char* Max(const char*, const char*) 템플릿 함수가 정의되어 있지 않다면, 올바른 결과 출력 X

	char str1[] = "Simeple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;
	return 0;
}