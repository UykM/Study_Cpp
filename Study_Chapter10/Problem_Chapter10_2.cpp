#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	/*
	Point& operator-(Point& ref)
	{
		xpos = -ref.xpos;
		ypos = -ref.ypos;
		return *this;
	}
	*/
	Point operator- ()
	{
		Point pos(-xpos, -ypos);
		return pos;
	}
	friend Point operator~ (const Point&);
};

Point operator~ (const Point& ref)
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main(void)
{
	Point pos1(9, -7);
	pos1.ShowPosition();
	Point pos2 = -pos1;
	pos2.ShowPosition();
	/* Point &operator-(Point &ref) 로 오버로딩한 경우
	Point pos2;
	pos1.ShowPosition();
	(pos2 - pos1).ShowPosition();
	*/
	(~pos2).ShowPosition();
	pos2.ShowPosition();
	return 0;
}