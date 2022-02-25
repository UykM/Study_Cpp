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
#include <iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "Base Constructor" << endl; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne : virtual public Base
{
public:
	MiddleDerivedOne() : Base()		// 기초 클래스(Base)의 생성자 호출을 명시하지 않아도 되지만, 기초 클래스의 생성자가 호출됨을 강조하기 위해 명시
	{
		cout << "MIddleDerivedOne ConsTructor" << endl;
	}
	void MiddleFuncOne()
	{
		SimpleFunc();		// Base 클래스 멤버
		cout << "MiddleDerivedOne" << endl;
	}
};

class MiddleDerivedTwo : virtual public Base
{
public:
	MiddleDerivedTwo() : Base()		// 기초 클래스(Base)의 생성자 호출을 명시하지 않아도 되지만, 기초 클래스의 생성자가 호출됨을 강조하기 위해 명시
	{
		cout << "MiddleDerivedTwo Constructor" << endl;
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();		// Base 클래스 멤버
		cout << "MIddleDerivedTwo" << endl;
	}
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo	// virtual 선언이 되지 않은 상태에서 LastDerived 클래스의 객체가 생성되면, Base 클래스의 멤버를 두 번 포함하게 됨.
{																		// 즉, Base 클래스를 딱 한 번만 (간접)상속하게끔 하는 것이 'virtual inheritance' 임.
public:
	LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
	{
		cout << "LastDerivedConstructor" << endl;
	}
	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();		// MiddleDerivedOne 클래스와 MiddleDerivedTwo 클래스가 Base 클래스(기초 클래스)를 가상상속하지 않았다면,
	}						// ComplexFunc 함수 내에서 이름만 가지고 SimpleFunc 함수 호출 불가능
};							// MiddleDerivedOne::SimpleFunc()
							// MiddleDerivedTwo::SimpleFunc() 
							// 이런 식으로 어느 클래스를 통해서 간접 상속한 Base 클래스의 멤버함수를 호출할 것인지 명시해야 함.

int main(void)
{
	cout << "객체생성 전 ....." << endl;
	LastDerived ldr;						// LastDerived 객체 생성시 Base 클래스의 생성자가 한 번만 호출됨. virtual 선언과 관련이 있음.
	cout << "객체생성 후 ....." << endl;
	ldr.ComplexFunc();		 
	return 0;
}

/* 실행 결과
객체생성 전 .....
Base Constructor					// Base 클래스의 생성자가 한 번만 호출됨.	
MiddleDerivedOne Constructor
// Base Constructor		virtual 선언이 되지 않은 경우, Base 클래스의 생성자는 두 번 호출됨.
MiddleDerivedTwo Constructor
LastDerived Constructor
객체생성 후 .....
BaseOne
MiddleDerivedOne
BaseOne
MiddleDerivedTwo
BaseOne
*/