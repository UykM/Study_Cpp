#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

/*
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num=" << num << ", ";
		cout << "address=" << this << endl;
	}

	void ShowSimpleData()
	{
		cout << num << endl;
	}

	SoSimple* GetThisPointer()
	{
		return this;
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();		// sim1 객체의 주소 값(ptr1) 저장 
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();					// -> 은 포인터를 통해 접근 <-> . 은 직접 접근

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();		// sim2 객체의 주소 값(ptr2) 저장
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();		
	return 0;
}

*/

// this : 객체를 참조하는 포인터 , this 는 지역변수(매개변수)가 아닌 멤버변수에 접근 가능

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1;		// this->num1 은 멤버변수 num1을 의미, num1 은 매개변수 num1을 의미
		this->num2 = num2;
	}
	/* 멤버 이니셜아이저에서는 this 포인터 사용 불가능
	TwoNumber(int num1, int num2)
		: num1(num1), num2(num2)
	{
	}
	*/
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;			// 일반적으로 이러한 경우엔 this 를 생략
		cout << this->num2 << endl;
	}
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}