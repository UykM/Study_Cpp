#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);

	void* operator new(size_t size)		// 멤버함수로 선언됐지만 static으로 선언된 함수
	{
		cout << "operater new :	" << size << endl;
		void* adr = new char[size];
		return adr;
	}
	void* operator new[](size_t size)	// operator new [] 함수 : 배열할당 시 호출되는 함수
	{
		cout << "operator new [] : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	void operator delete(void* adr)		// 멤버함수로 선언됐지만 static으로 선언된 함수
	{
		cout << "operator delete ()" << endl;
		delete[] adr;
	}
	void operator delete[](void* adr)	// delete []arr 함수 : 배열소멸 시 호출되는 함수
	{
		cout << "ooperator delete[] ()" << endl;
		delete[]adr;
	}
};

// operator new 함수와 operator delete 함수는 static 함수임.
// 그래서 객체생성의 과정에서 호출이 가능했던 것

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point* ptr = new Point(3, 4);	// 객체 생성과정
	cout << *ptr;
	delete ptr;
	return 0;
}