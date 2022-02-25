// 연산자 오버로딩
// 멤버함수에 의한 연산자 오버로딩의 예
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ', ' << ypos << ']' << endl;
	}
	Point operator+(const Point& ref) const		// operator+ 라는 이름의 함수, 연산자를 오버로딩한 함수도 const로 선언이 가능함.
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return xpos;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);
	// Point pos3 = pos2.operator+(pos1);	pos2 객체의 멤버함수를 호출하는 형태로 문장 구성해도 결과는 같음.
	// Point pos3 = pos1 + pos2;	동일한 문장 : Point pos3 = pos1.operator+(pos2)로 해석되어서 컴파일 됨.

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
}

// 전역함수에 의한 연산자 오버로딩의 예
// 특별한 경우가 아니면 멤버함수를 기반으로 연산자를 오버로딩 하는 게 나음.
// 물론 전역함수로 연산자를 오버로딩 해야만 하는 상황도 존재.
/*
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << 'y' << endl;
	}
	friend Point operator+(const Point& pos1, const Point& pos2);		// operator+ 함수에 대해 private 영역의 접근을 허용
};

Point operator+(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
}
*/

// 오버로딩이 불가능한 연산자도 존재

// 멤버함수로만 오버로딩이 가능한 연산자
/* 
* =		대입 연산자
* ()	함수 호출 연산자
* []	배열 접근 연산자(인덱스 연산자)
* ->	멤버 접근을 위한 포인터 연산자
* 
* 객체를 대상으로 진행해야 의미가 통하는 연산자이기 때문임.
*/

/* 연산자 오버로딩 주의사항
1) 본래의 의도를 벗어난 형태의 연산자 오버로딩 X
2) 연산자의 우선순위와 결합성은 변함 X
3) 매개변수의 디폴트 값 설정이 불가능
4) 연산자의 순수 기능까지 뺴앗을 수 없음
*/