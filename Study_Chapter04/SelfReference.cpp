#include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "객체 생성" << endl;
	}
	
	SelfRef& Adder(int n)		// 반환형이 참조형
	{
		num += n;
		return *this;			// 객체 생성시, 그 객체의 참조값을 반환함.
	}
	
	SelfRef& ShowTwoNumber()		// 반환형이 참조형
	{
		cout << num << endl;
		return *this;				// this는 자기 자신을 가리키는 키워드(주소값),  *this 는 자기 자신의 값
	}
};

int main(void)
{
	SelfRef obj(3);					// 객체 obj 생성 후, 3으로 초기화
	SelfRef& ref = obj.Adder(2);	// 참조자(&)로 받았기 때문에, 참조자 ref는 객체 obj를 참조하게 됨.
									// 따라서, 객체 obj와 객체 ref는 같은 메모리의 위치에 있음.

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	// obj. ShowTwoNumber();  =>  객체 obj와 객체 ref는 같은 메모리의 위치에 있기 때문에, 8을 출력

	return 0;
}