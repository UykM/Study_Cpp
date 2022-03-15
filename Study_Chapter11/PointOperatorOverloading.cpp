/*
#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n) : num(n) {}
	void ShowData() { cout << num << endl; }

	Number* operator->()
	{
		return this;	// 객체자신의 주소 값 반환
	}

	Number& operator*()
	{
		return *this;	// 객체자신을 참조의 형태로 반환
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();
	
	(*num) = 30;
	num->ShowData();		// num.operator->() -> ShowData(); 로 해석
	(*num).ShowData();
	return 0;
}
*/

// Smart Pointer	
// - 포인터의 역할을 하는 객체
// Smart Pointer 를 직접 구현
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point 객체 생성" << endl;
	}
	~Point()
	{
		cout << "Point 객체 소멸" << endl;
	}
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	friend ostream& operator<<(ostream& os, const Point& pos);
};
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class SmartPtr
{
private:
	Point* posptr;
public:
	SmartPtr(Point *ptr) : posptr(ptr)
	{ }

	Point& operator*() const	// Smart Pointer 의 가장 기본이 되는 정의
	{
		return *posptr;
	}
	Point* operator->() const	// Smart Pointer 의 가장 기본이 되는 정의
	{
		return posptr;
	}
	~SmartPtr()
	{
		delete posptr;
	}
};

int main(void)
{
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(3, 4));
	SmartPtr sptr3(new Point(4, 5));
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;
	return 0;
}


/* () 연산자의 오버로딩과 Functor
객체의 이름 - adder, 이 객체에 () 연산자가 멤버함수로 오버로딩 되어 있는 경우
adder(2, 4); 
-> adder.operator()(2,4);


*/

/*
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	Point operator+(const Point& pos) const
	{
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class Adder		// 이 Adder 클래스를 '펑터(Functor)'라고 함. 그리고 '함수 오브젝트(Function Object)'라고도 불림.
{				// 이처럼 함수처럼 동작하는 클래스를 'Functor'라고 함.
public:
	int operator()(const int& n1, const double& n2)
	{
		return n1 + n2;
	}
	double operator()(const double& e1, const double& e2)
	{
		return e1 + e2;
	}
	Point operator()(const Point& pos1, const Point& pos2)
	{
		return pos1 + pos2;
	}
};

int main(void)
{
	Adder adder;
	cout << adder(1, 3) << endl;
	cout << adder(1.5, 3.7) << endl;
	cout << adder(Point(3, 4), Point(7, 9));
	return 0;
}
*/