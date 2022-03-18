// Ŭ���� ���ø��� Ư��ȭ�ϴ� ����
// : ���ø��� �����ϴ� ����Լ��� �Ϻ� �Ǵ� ���θ� �ٸ��� �ൿ�ϵ��� ������ �� ����.
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

// Ŭ���� ���ø� SimpleDataWrapper�� char*���� ���ؼ� Ư��ȭ��.
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

// ���ø� Ŭ������ Point<int>���� ���ؼ� Ư��ȭ�ϴ� ����� ����.
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
	SimpleDataWrapper<int> iwrap(170);	// �� ������ ������ �� �� ���ø� Ŭ������ SimpleDataWrapper<int>�� ���������, �� Ŭ������ ������� ��ü ����
	iwrap.ShowDataInfo();
	SimpleDataWrapper<char*> swrap("Class Template Specialization");	// ������ ���ø� Ŭ������ �������� �ʰ�, 37�࿡������ ���ǵ� ���ø� Ŭ������ ��ü�� ������
	swrap.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap(3, 7);	// ������ ���ø� Ŭ������ �������� �ʰ�, 57�࿡������ ���ǵ� ���ø� Ŭ������ ��ü�� ������
	poswrap.ShowDataInfo();
	return 0;
}

/* Ŭ���� ���ø��� �κ� Ư��ȭ
* ��ü Ư��ȭ�� �κ� Ư��ȭ���� �켱�õ�!

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
class MySimple<T1, double>		// T2�� double�� �κ� Ư��ȭ
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
	MySimple<int, double> obj3;		// �κ� Ư��ȭ�� ��ü Ư��ȭ�� �� ���� ��ο� �ش�Ǵ� ��ü���� �����̰�, 
									// ��ü Ư��ȭ�� Ŭ������ ������� ��ü�� ������.
	obj3.WhoAreYou();
	return 0;
}
*/

