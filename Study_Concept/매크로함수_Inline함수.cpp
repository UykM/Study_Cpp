#include <iostream>
using namespace std;

/* #define SQUARE(x) ((x)*(x))    // -> 매크로함수 / (x) : 괄호는 반드시 써줘야함


int main(void)
{
	cout << SQUARE(5) << endl;
	cout << SQUARE(3.15) << endl;   // 매크로 함수 : 자료형에 의존적이니 않음
	return 0;
}
*/

inline int SQUARE(int x)         // 자료형에 의존적
{                                // Template <typname T> : 템플릿을 이용하면 자료형에 의존하지 않아도 됨
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