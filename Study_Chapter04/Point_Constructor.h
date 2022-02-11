#pragma once

class Point
{
private:
	int x;
	int y;

public:
	Point(const int& xpos, const int& ypos);
	int GetX() const;				// const 선언된 함수
	int GetY() const;				// const 선언된 함수
	bool SetX(int xpos);
	bool SetY(int ypos);
};