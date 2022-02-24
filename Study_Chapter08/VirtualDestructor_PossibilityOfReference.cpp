// 가상 소멸자(Virtual Destructor)
// 가상 소멸자가 호출되면, 상속의 계층구조상 맨 아래에 존재하는 유도 클래스(derived class)의 소멸자가 대신 호출되면서,
// 기초 클래스(base class)의 소멸자가 순차적으로 호출됨.
#include <iostream>
using namespace std;

class First
{
private:
	char* strOne;
public:
	First(const char* str)
	{
		strOne = new char[strlen(str) + 1];
	}
	//~First()
	virtual ~First()		// 가상 소멸자
	{
		cout << "~First()" << endl;
		delete[]strOne;
	}
};

class Second : public First
{
private:
	char* strTwo;
public:
	Second(const char* str1, const char* str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	~Second()		// 소멸자도 상속의 계층구조상 맨 위에 존재하는 기초(base) 클래스의 소멸자만 virtual로 선언하면, 
	{				// 이를 상속하는 유도 클래스의 소멸자들은 모두 '가상 소멸자)로 선언됨.
		cout << "~Second()" << endl;
		delete[]strTwo;
	}
};

int main(void)
{
	First* ptr = new Second("simple", "complex");
	delete ptr;		// First 클래스의 소멸자와 Second 클래스의 소멸자가 동시에 호출되어야 함.
					// 하지만, 객체의 소멸을 First형 포인터로 명령하여, First 클래스의 소멸자만 호출
					// 이러한 경우엔 메모리의 누수(leak)가 발생.
					// 따라서 객체의 소멸과정에선 delete 연산자에 사용된 포인터 변수의 자료형에 상관없이 모든 소멸자가 호출돼야 함.
					// 이를 위해서 소멸자에 virtual 선언을 추가해주는 것!
	return 0;
}


/* 참조자의 참조 가능성
"AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다.(객체의 주소 값 저장 가능)"
이러한 특성이 참조자에도 적용됨.
→ AAA형 참조자는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 참조 가능!

#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj;	// obj는 Second 클래스를 직접 상속하는 Third 클래스의 객체이므로, Second형 참조자로 참조 가능함.
						// Third 클래스에 정의된 ThirdFunc 함수는 호출 불가능
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();	// SimpleFunc은 가상함수이므로, Third 클래스에 정의된 SimpleFunc 함수가 호출됨.

	First& fref = obj;	// obj는 First 클래스를 간접 상속하는 Third 클래스의 객체이므로, First형 참조자로 참조 가능함.
						// Second 클래스에 정의된 SecondFunc 함수와 Third 클래스에 정의된 ThirdFunc 함수는 호출 불가능
	fref.FirstFunc();
	fref.SimpleFunc();	// SimpleFunc은 가상함수이므로, Third 클래스에 정의된 SimpleFunc 함수가 호출됨.
	return 0;
}


다음과 같이 정의된 함수를 보게 되면,
void GoddFunction(const First &ref) { .... }

1) First 객체 또는 First를 직접 혹은 간접적으로 상속하는 클래스의 객체가 인자의 대상이 된다는 사실을 고려
2) 인자로 전달되는 객체의 실제 자료형에 상관없이 함수 내에서는 First 클래스에 정의된 함수만 호출할 수 있다는 사실을 고려
*/