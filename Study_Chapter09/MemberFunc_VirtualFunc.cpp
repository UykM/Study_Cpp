// 객체가 생성되면 멤버변수는 객체 내에 존재하지만,
// 멤버함수(member function)는 메모리의 한 공간에 별도로 위치하고선, 이 함수가 정의된 클래스의 모든 객체가 이를 공유하는 형태를 취함.

// 가상함수(virtual function)의 동작원리
#include <iostream>
using namespace std;

class AAA
{
private:
	int num1;	// 형식적인 선언
public:
	virtual void Func1() { cout << "Func1" << endl; }
	virtual void Func2() { cout << "Func2" << endl; }
};

class BBB : public AAA
{
private:
	int num2;	// 형식적인 선언
public:
	virtual void Func1() { cout << "BBB::Func1" << endl; }
	void Func3() { cout << "Func3" << endl; }
};

// 가상함수 테이블은 객체의 생성과 상관없이 메모리 공간에 할당됨.
int main(void)
{
	AAA* aptr = new AAA();		// AAA 객체에는 AAA 클래스의 가상함수 테이블의 주소 값이 저장
	aptr->Func1();

	BBB* bptr = new BBB();		// BBB 객체에는 BBB 클래스의 가상함수 테이블의 주소 값이 저장
	bptr->Func1();				// BBB 클래스의 가상함수 테이블이 참조되고, BBB 클래스의 Func1 함수가 실행되는데, 
								// BBB 클래스의 가상함수 테이블에는 오버라이딩 된 AAA 클래스의 Func1 함수에 대한 정보 X
	return 0;
}