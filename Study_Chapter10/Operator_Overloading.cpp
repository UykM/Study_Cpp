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


// 단항 연산자의 오버로딩
// 대표적으로, 증가 연산자(++)와 감소 연산자(--)가 있음.
// 이항 연산자와의 큰 차이점은 피연산자의 개수
/* 추가 - 후위증가, 후위감소의 형태의 오버로딩
#include <iotream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++()		// 멤버함수의 형태로 오버로딩
	{
		xpos += 1;
		ypos += 1;
		return *this;		// 반환형이 참조형이기 때문에, 객체 자신을 참조할 수 있는 '참조 값'이 반환됨.
	}
	const Point operator++(int)		// 후위증가 - 반환형이 const
	{
		const Point retobj(xpos, ypos);		// const Point retobj(*this);	
											// 반환의 대상이 되는 이 객체의 const 선언유무는 객체의 반환에 아무런 영향 X
											// 함수 내에서 임시객체 retobj의 변경을 막겠다는 의미
											// '반환형의 const 선언'으로 값의 변경을 허용하지 않는 const 객체(상수 객체)
		xpos+=1;
		ypos+=1;
		return retobj;
	}
	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref)		// 전역함수의 형태로 오버로딩
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point operator--(Point &ref, int)		// 후위감소 - 반환형이 const
{
	const Point retobj(ref);	// 함수 내에서 임시객체 retobj의 변경을 막겠다는 의미
								// 반환의 대상이 되는 이 객체의 const 선언유무는 객체의 반환에 아무런 영향 X
								// '반환형의 const 선언'으로 값의 변경을 허용하지 않는 const 객체(상수 객체)
	ref.xpos-=1;
	ref.ypos-=1;
	return retobj;
}

int main(void)
{
	Point pos(3, 5);
	++pos;		// pos.operator++(); 로 해석
	pos.ShowPosition();
	--pos;		// operator--(pos); 로 해석
	pos.ShowPosition();

	Point cpy;
	cpy = pos--;
	cpy.ShowPosition();		// [3, 5]
	pos.ShowPosition();		// [2, 4]

	cpy = pos++;
	cpy.ShowPosition();		// [2, 4]
	pos.ShowPosition();		// [3, 5]

	++(++pos);			// ++(pos.operator++());
						// ++(pos의 참조 값);
						// (pos의 참조 값).operator++();
	pos.ShowPosition();
	--(--pos);			// --(operator--(pos));
						// --(pos의 참조 값);
						// operator--(pos의 참조 값);
	pos.ShowPosition();
	return 0;
}


// 두 const 함수의 임시 객체를 대상으로는 const로 선언되지 않은 멤버함수의 호출이 불가능!
int main(void)
{
	Point pos(3, 5);
	(pos++)++;		// 컴파일 Error!	// (Point형 const 임시객체)++;
										// (Point형 const 임시객체).operator++();	: operator++(int)의 호출
										// operator++ 멤버함수는 const로 선언된 함수가 아님.

	(pos--)--;		// 컴파일 Error!	// (Point형 const 임시객체)--;
										// operator--(Point형 const 임시객체);	   : operator--(Point &ref, int)의 호출
										// 전역함수 operator--(Point &ref, int) 에서 매개변수로 선언된 참조자 &ref가 const로 선언되지 않음.
	...
}

// C++ 연산특성
int main(void)
{
	int num = 100;
	++(++num);		// 컴파일 OK!
	(num++)++;		// 컴파일 Error!
}
*/
