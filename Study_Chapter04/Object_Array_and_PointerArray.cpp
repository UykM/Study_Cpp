#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
		: age(myage)
	{
		name = new char[strlen(myname) + 1];	// 배열이 선언됨과 동시에 생성자가 호출됨.
		strcpy(name, myname);
	}

	Person()					// 따라서 "객체 배열의 경우"엔, 다른 매개변수 생성자가 있으면, 기본 생성자가 반드시 정의되어 있어야함!
								// 배열 선언 이후에 각각의 요소를 원하는 값으로 초기화
								// 객체 포인터 배열, 포인터 변수 등 포인터는 기본생성자가 존재하지 않는다.
		: name(NULL), age(0)	
	{
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char* myname, int myage)
	{
		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}

	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

// Array of Objects(객체 배열)

int main(void)
{
	Person parr[3];			// 선언과 함께 기본 생성자(Default Constructor) 호출
							// ClassName Object[n];  -  기본 생성자 n번 호출
							// 저장의 대상이 객체
	char namestr[100];
	char* strptr;
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;
		strptr = new char[strlen(namestr) + 1];		
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);		// 생성자가 호출됨.
	}
	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();
	return 0;
}


// Array of Objects Pointer (객체 포인터 배열)
/*
int main(void)
{
	Person* parr[3];		// 저장의 대상이 객체의 주소 값
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;
		parr[i] = new Person(namestr, age);			// 생성자인 Person::Person(const char*, int)만 호출
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();
	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}
*/
