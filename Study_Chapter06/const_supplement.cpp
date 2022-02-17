// 변수를 상수화 하는 const
// const int num = 10;

// 객체를 상수화 하는 const
// const SoSimple sim(20);

// 객체에 const 선언이 붙게 되면, "이 객체의 데이터 변경을 허용하지 않겠다."는 의미
// 따라서 이 객체를 대상으로는 값을 변경시킬 능력이 없는 const 멤버함수만 호출이 가능
/* 이러한 const 객체의 특성을 확인할 수 있는 예제
#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n);
	{ }
	SoSImple& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const
	{
		cout << "num: " << num << endl;
	}
};

int main(void)
{
	const SoSimple obj(7);
	// obj.AddNum(20);		// AddNum 멤버함수는 const 함수가 아니기 때문에 호출 불가능
	obj.ShowData();
	return 0;
*/

/* const와 함수 오버로딩
* 함수의 오버로딩이 성립하려면, 매개변수의 수나 자료형이 달라야 하는데
* 다음과 같이 const의 선언 유무도 함수 오버로딩의 조건이 될 수 있음.
void SimpleFunc() { ... }
void SImpleFunc() const { ... }

* 다음 예제를 통해서 두 함수가 어떤 경우에 호출되는지 확인
#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n);
	{ }
	void SimplFunc()
	{
		 cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const
	{	
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple &obj)		// 전달되는 인자를 const 참조자로 받고 있음.
{										
	obj.SimpleFunc();					// 따라서 const 멤버함수인 SimpleFunc() const 호출
}

int main(void)
{
	SoSimple obj1(2);
	const SoSImple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();			// 객체가 const 로 선언돼었기 때문에 const 멤버함수인 SimpleFunc() const 를 호출

	YourFunc(obj1);				// YourFunc 함수는 전달되는 인자를 const 참조자로 받고 있기 때문에
	YourFunc(obj2);				// 둘다 const 멤버함수인 SimpleFunc() const 를 호출
	return 0;
}

실행 결과
SimpleFunc: 2
const SimpleFunc: 7
const SimpleFunc: 2
const SimpleFUnc: 7
*/