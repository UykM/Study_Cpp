// int형 변수의 할당				: int * ptr1 = new int;
// double형 변수의 할당				: double * ptr2 = new double;
// 길이가 3인 int형 배열의 할당		: int * arr1 = new int[3];
// 길이가 7인 double형 배열의 할당  : double * arr2 = new arr2[7];

// 앞서 할당한 int형 변수의 소멸	: delet ptr1;
// 앞서 할당한 double형 변수의 소멸 : delet ptr2;
// 앞서 할당한 int형 배열의 소멸	: delet []arr1;
// 앞서 할당한 double형 배열의 소멸 : delet []arr2;

/* new 는 메모리 할당뿐만 아니라, 생성자를 호출하고 객체까지 생성
Class Simple
{
public:
	Simple()		// 생성자 - 멤버함수의 일종
	{
		cout << "..." << endl;
	}
};

int main(void)
{
	Simple * sp1 = new Simple;		// Simple * sp1 = new Simple();
}									- 생성자에 전달받을 인자가 없기 때문에 소괄호 생략 가능.
*/

#include <iostream>
#include <cstring>
#pragma warning(disable:4996) // C4996에러를 무시
using namespace std;

char* MakeStrAdr(int len)
{
	char* str = new char[len];		
	return str;
}

int main(void)
{
	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");          // strlen  : 문자열의 길이 계산
	cout << str << endl;					// strcat  : 문자열의 뒤에 덧붙이기
	delete[]str;							// strcpy  : 문자열 복사
	return 0;								// strcmp  : 문자열의 비교				
}
