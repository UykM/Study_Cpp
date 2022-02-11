#include <iostream>
#include "Point_Constructor.h"
using namespace std;

/*
bool Point::InitMembers(int xpos, int ypos)
{
	if (xpos < 0 || ypos < 0)
	{
		cout << "��� ������ �� ����" << endl;
		return false;			// if���� �Ÿ��� ��� false�� ��ȯ�ϰ� �Լ� ����
	}

	x = xpos;
	y = ypos;
	return true;
}
*/ 
// �����ڸ� Ȱ���ϱ� ���� ¥�� �ڵ�� ��� ������ ���� ���� ��ó�� ����.

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
		cout << "��� ������ �� ����" << endl;
		return false;
	}
	x = xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if (0 > ypos || ypos > 100)
	{
		cout << "��� ������ �� ����" << endl;
		return false;
	}
	y = ypos;
	return true;
}