// 다중상속(Multiple Inheritance)
// 다중상속의 문법 설명을 목적으로 하는 예제
/*
#include <iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFunc() { cout << "BaseOne" << endl; }	
};

class BaseTwo
{
public:
	void SimpleFunc() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void ComplexFunc()
	{
		BaseOne::SimpleFunc();		// BaseOne 클래스에도, BaseTwo 클래스에도 SimpleFunc라는 이름의 멤버함수가 존재하기 때문에,
		BaseTwo::SimpleFunc();		// 이 둘을 상속하는 유도 클래스에서 SImpleFunc 함수를 호출할 때에는, 이렇게 어느 클래스에 정의된 함수의 호출을 원하는지 명시!
	}
};

int main(void)
{
	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}
*/

// 가상 상속(Virtual Inheritance)
