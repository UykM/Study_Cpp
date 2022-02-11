#include <iostream>
#include "Rectangle_Constructor.h"
using namespace std;

/*
bool Rectangle::InitMembers(const Point& ul, const Point& lr)
{
	if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
	{
		cout << "잘못된 위치정보 전달" << endl;
		return false;
	}
	upLeft = ul;
	lowRight = lr;
	return true;
}
*/
// 생성자를 활용하기 위해 짜는 코드라 벗어난 범위의 값에 대한 대처는 없음.

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
			:upLeft(x1, y1), lowRight(x2, y2)
{
	// Member Initializer 를 이용해서 Point 객체(upleft, lowRight)를 초기화 시킴.
	// empty
}

void Rectangle::ShowRecInfo() const
{
	cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
	cout << upLeft.GetY() << ']' << endl;
	cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
	cout << lowRight.GetY() << ']' << endl << endl;
}