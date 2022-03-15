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
		return this;	// ��ü�ڽ��� �ּ� �� ��ȯ
	}

	Number& operator*()
	{
		return *this;	// ��ü�ڽ��� ������ ���·� ��ȯ
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();
	
	(*num) = 30;
	num->ShowData();		// num.operator->() -> ShowData(); �� �ؼ�
	(*num).ShowData();
	return 0;
}
*/

// Smart Pointer	
// - �������� ������ �ϴ� ��ü
// Smart Pointer �� ���� ����
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point ��ü ����" << endl;
	}
	~Point()
	{
		cout << "Point ��ü �Ҹ�" << endl;
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

	Point& operator*() const	// Smart Pointer �� ���� �⺻�� �Ǵ� ����
	{
		return *posptr;
	}
	Point* operator->() const	// Smart Pointer �� ���� �⺻�� �Ǵ� ����
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


/* () �������� �����ε��� Functor
��ü�� �̸� - adder, �� ��ü�� () �����ڰ� ����Լ��� �����ε� �Ǿ� �ִ� ���
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

class Adder		// �� Adder Ŭ������ '����(Functor)'��� ��. �׸��� '�Լ� ������Ʈ(Function Object)'��� �Ҹ�.
{				// ��ó�� �Լ�ó�� �����ϴ� Ŭ������ 'Functor'��� ��.
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