// 배열보다 나은 배열 클래스
/*
#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out ouf bound exception" << endl;
		}
		return arr[idx];
	}
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	for (int i = 0; i < 6; i++)
		cout << arr[i] << endl;
	return 0;
}
// a[6] : 잘못된 배열 접근이 있었음을 확인할 수 있는 예제
// 위와 같은 클래스 정의를 통해서 배열접근의 안정성을 보장받을 수 있음.
*/

// 다음과 같이 복사 생성자와 대입 연산자를 private으로 선언해서, 복사 또는 대입을 원천적으로 막아 좀더 안전성을 높일 수 있음.
/*
class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }
public:
	......
}
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out ouf bound exception" << endl;
		}
		return arr[idx];
	}
	int operator[](int idx) const		// operator[] 함수 오버로딩 추가
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray() { delete[]arr; }
};

void ShowAllData(const BoundCheckIntArray& ref)		// 매개변수 ref 가 const로 선언
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;		// cout << ref.operator[](idx) << endl;
										// 이때 operator[] 함수는 const 함수가 아니기 떄문에 컴파일 에러 발생
										// 그렇다고 operator[] 함수에 const 선언을 추가하게 되면 
										// 배열을 멤버로 선언하는 경우엔 저장 자체가 불가능해져 다른 부분에서 컴파일 에러 발생 
}

int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	
	ShowAllData(arr);
	return 0;
}

// 따라서 const 의 선언유무도 함수 오버로딩의 조건에 해당한다는 사실을 알 수 있음.


/* 객체 대상의 배열 클래스
* 저장의 대상이 객체이냐, 아니면 객체의 주소 값이냐에 차이가 있음.

// Point 객체를 저장하는 배열 기반의 클래스
#include <iostream>
#include <cstdlib>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0)	: xpos(x), ypos(y) { }
	friend ostream& operator << (ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class BoundCheckIntArray
{
private:
	Point* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new Point[len];
	}
	Point& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out ouf bound exception" << endl;
		}
		return arr[idx];
	}
	Point operator[](int idx) const	
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray() { delete[]arr; }
};

int main(void)
{
	BoundCheckIntArray arr(3);
	arr[0] = Point(3, 4);
	arr[1]= Point(5, 6);
	arr[2] = Point(7, 8);

	for (int i = 0; i << arr.GetArrLen(); i++)
		cout << arr[i];

	return 0;
}

-------------------------------------------------------------------------------------------------------

// Point 객체의 주소를 저장하는 배열 기반의 클래스
#include <iostream>
#include <cstdlib>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0)	: xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

typedef Point* POINT_PTR;	// Point 포인터 형을 의미하는 POINT_PTR을 정의

class BoundCheckIntArray
{
private:
	POINT_PTR* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out ouf bound exception" << endl;
		}
		return arr[idx];
	}
	POINT_PTR operator[](int idx) const	
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray() { delete[]arr; }
};

int main(void)
{
	BoundCheckIntArray arr(3);
	arr[0] = new Point(3, 4);	// 이렇게 객체의 주소 값을 저장할 경우, 깊은 복사냐 얕은 복사냐 하는 문제는 신경 X
	arr[1] = new Point(5, 6);	
	arr[2] = new Point(7, 8);

	for (int i = 0; i << arr.GetArrLen(); i++)
		cout << *(arr[i]);
	delete arr[0];
	delete arr[1];
	delete arr[2];

	return 0;
}
// 주소 값을 배열에 저장하는 경우가 더 복잡해보이지만, 깊은 복사와 얕은 복사를 따지지 않아도 되서 이 방법이 더 많이 사용됨.
*/
