#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:		// 생성자의 오버로딩이 가능하다.
	SimpleClass()		// 객체 생성
	{					// SimpleClass sc1();	 소괄호 생략 불가 (X)  
		num1 = 0;		// -> 함수의 원형인지 객체의 생성인지 구분 불가
		num2 = 0;		// SimpleClass sc1;		(O)
						// SimpleClass *ptr1 = new SimpleClass;
						// SimpleClass *ptr1 = new SimpleClass();
	}
	
	SimpleClass(int n)		// 객체 생성
	{						// SImpleClass sc2(100);	- 전역 및 지역변수의 형태
		num1 = n;			// SimpleClass * ptr2 = new SimpleClass(100)	- 동적 할당의 형태
		num2 = 0;
	}
	
	SimpleClass(int n1, int n2)			
	{
		num1 = n1;
		num2 = n2;
	}

	/* 주석 해제시, 컴파일 에러
	
	SimpleClass sc2(100); 
	이처럼 객체를 생성하면 15행의 생성자와 30행의 생성자가 모두 호출 가능해서,
	호출할 생성자를 결정하지 못해서 컴파일 에러 발생.
	
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}
	*/

	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};



int main(void)
{
	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100, 200);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();

	return 0;
}

/* 소멸자(Destructor) : 디폴트 생성자(Default Constructor)와 마찬가지로, 직접 소멸자를 정의하지 않으면 자동으로 삽입됨.

class AAA
{
	// empty class
}

class AAA
{
public:
	AAA() {}
	~AAA() {}
};

위의 두 클래스 정의는 동일함.
이러한 소멸자(Destructor)는 대개 생성자에서 할당한 리소스의 소멸에 사용됨.
예를 들어 new 연산자를 이용해서 할당해 놓은 메모리 공간이 있다면,
소멸자에서는 delet 연산자를 이용해서 이 메모리 공간을 소멸함.

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("신 민 규", 22);
	man1.ShowPersonInfo();

	return 0;
}
*/