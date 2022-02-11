#include <iostream>
#include "Point_Constructor.h"
using namespace std;

/*
bool Point::InitMembers(int xpos, int ypos)
{
	if (xpos < 0 || ypos < 0)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;			// if문에 거릴는 경우 false를 반환하고 함수 종료
	}

	x = xpos;
	y = ypos;
	return true;
}
*/ 
// 생성자를 활용하기 위해 짜는 코드라 벗어난 범위의 값에 대한 대처는 없음.

Point::Point(const int& xpos, const int& ypos)
{
	x = xpos;
	y = ypos;
}

int Point::GetX() const
{
	return x;
}

int Point::GetY() const
{
	return y;
}

bool Point::SetX(int xpos)
{
	if (0 > xpos || xpos > 100)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (0 > ypos || ypos > 100)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}
	y = ypos;
	return true;
}