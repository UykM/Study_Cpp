// 클래스 템플릿을 특수화하는 이유
// : 템플릿을 구성하는 멤버함수의 일부 또는 전부를 다르게 행동하도록 정의할 수 있음.
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x=0, T y=0): xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template <typename T>
class SimpleDataWrapper
{
private:
	T mdata;
public:
	SimpleDataWrapper(T data) : mdata(data)
	{ }
	void ShowDataInfo(void)
	{
		cout << "Data: " << mdata << endl;
	}
};

// 클래스 템플릿 SimpleDataWrapper를 char*형에 대해서 특수화함.
template <>							
class SimpleDataWrapper <char*>
{
private:
	char* mdata;
public:
	SimpleDataWrapper(const char* data)
	{
		mdata = new char[strlen(data) + 1];
		strcpy(mdata, data);
	}
	void ShowDataInfo(void)
	{
		cout << "String: " << mdata << endl;
		cout << "Length: " << strlen(mdata) << endl;
	}
	~SimpleDataWrapper() { delete[]mdata; }
};

// 템플릿 클래스인 Point<int>형에 대해서 특수화하는 방법을 보임.
template <>
class SimpleDataWrapper <Point<int>>
{
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) : mdata(x, y)
	{ }
	void ShowDataInfo(void)
	{
		mdata.ShowPosition();
	}
};

int main(void)
{
	SimpleDataWrapper<int> iwrap(170);	// 이 문장이 컴파일 될 때 템플릿 클래스인 SimpleDataWrapper<int>가 만들어지고, 이 클래스를 기반으로 객체 생성
	iwrap.ShowDataInfo();
	SimpleDataWrapper<char*> swrap("Class Template Specialization");	// 별도의 템플릿 클래스가 생성되지 않고, 37행에서부터 정의된 템플릿 클래스의 객체가 생성됨
	swrap.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap(3, 7);	// 별도의 템플릿 클래스가 생성되지 않고, 57행에서부터 정의된 템플릿 클래스의 객체가 생성됨
	poswrap.ShowDataInfo();
	return 0;
}

/* 클래스 템플릿의 부분 특수화
* 전체 특수화가 부분 특수화보다 우선시됨!

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class MySimple
{
public:
	void WhoAreYou()
	{
		cout << "size of T1: " << sizeof(T1) << endl;
		cout << "size of T2: " << sizeof(T2) << endl;
		cout << "<typename T1, typenameT2>" << endl;
	}
};

template <>
class MySimple<int, double>
{
public:
	void WhoAreYou()
	{
		cout << "size of int: " << sizeof(int) << endl;
		cout << "size of double: " << sizeof(double) << endl;
		cout << "<int, double>" << endl;
	}
};

template <typename T1>
class MySimple<T1, double>		// T2를 double로 부분 특수화
{
public:
	void WhoAreYou()
	{
		cout << "size of T1: " << sizeof(T1) << endl;
		cout << "size of double: " << sizeof(double) << endl;
		cout << "<T1, double>" << endl;
	}
};

int main(void)
{
	MySimple<char, double> obj1;
	obj1.WhoAreYou();
	MySimple<int, long> obj2;
	obj2.WhoAreYou();
	MySimple<int, double> obj3;		// 부분 특수화와 전체 특수화의 두 가지 모두에 해당되는 객체생성 문장이고, 
									// 전체 특수화된 클래스를 대상으로 객체가 생성됨.
	obj3.WhoAreYou();
	return 0;
}
*/

