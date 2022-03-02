// Point operator*(int times)
// {
//		Point pos(xpos*times, ypos*times);
//		return pos;
//  }
// 이처럼 오버로딩된 경우  
// cpy = pos * 3;
// cpy = 3 * pos;	// 3.operator*(pos)로는 해석 불가능
// 따라서, 교환법칙이 성립하도록 오버로딩
// 두 형태의 문장이 동일한 결과를 보이도록 함.
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0)	: xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref)		// 교환법칙의 성립을 목적으로 함수를 추가로 정의
{
	return ref * times;
}

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy = 3 * pos;
	cpy.ShowPosition();

	cpy = 2 * pos * 3;
	cpy.ShowPosition();
	return 0;
}