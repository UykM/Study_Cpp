#include <iostream>
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


Simple()
{
	cout << "..." << endl;
}

Simple* ptr = new Simple;