#include <iostream>
using namespace std;

template <typename T>
class SimpleStaticMem
{
private:
	static T mem;		// 클래스 템플릿 내에 지역변수 num이 static으로 선언됨.
public:
	void AddMem(T num) { mem += num; }
	void ShowMem() { cout << mem << endl; }
};

// 위의 클래스 템플릿을 기반으로 컴파일러는 다음과 같이 '템플릿 함수'들을 만들어냄.
/*
class SimpleStaticMem<int>
{
private:
	static int mem;
public:
	void AddMem(int num) { mem += num; }
	void ShowMem() { cout << mem << endl; }
}; 

class SimpleStaticMem<double>
{
	...
}
*/

template <typename T>
T SimpleStaticMem<T>::mem = 0;		// static 멤버의 초기화

int main(void)
{
	// static 지역변수는 템플릿 함수 별로 각각 존재함.
	SimpleStaticMem<int> obj1;
	SimpleStaticMem<int> obj2;
	obj1.AddMem(2);
	obj2.AddMem(3);
	obj1.ShowMem();
	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;
	obj3.AddMem(100);
	obj4.ShowMem();
	return 0;
}