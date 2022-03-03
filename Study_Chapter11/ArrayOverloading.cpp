// �迭���� ���� �迭 Ŭ����
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
// a[6] : �߸��� �迭 ������ �־����� Ȯ���� �� �ִ� ����
// ���� ���� Ŭ���� ���Ǹ� ���ؼ� �迭������ �������� ������� �� ����.
*/

// ������ ���� ���� �����ڿ� ���� �����ڸ� private���� �����ؼ�, ���� �Ǵ� ������ ��õ������ ���� ���� �������� ���� �� ����.
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
	int operator[](int idx) const		// operator[] �Լ� �����ε� �߰�
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

void ShowAllData(const BoundCheckIntArray& ref)		// �Ű����� ref �� const�� ����
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;		// cout << ref.operator[](idx) << endl;
										// �̶� operator[] �Լ��� const �Լ��� �ƴϱ� ������ ������ ���� �߻�
										// �׷��ٰ� operator[] �Լ��� const ������ �߰��ϰ� �Ǹ� 
										// �迭�� ����� �����ϴ� ��쿣 ���� ��ü�� �Ұ������� �ٸ� �κп��� ������ ���� �߻� 
}

int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	
	ShowAllData(arr);
	return 0;
}

// ���� const �� ���������� �Լ� �����ε��� ���ǿ� �ش��Ѵٴ� ����� �� �� ����.


/* ��ü ����� �迭 Ŭ����
* ������ ����� ��ü�̳�, �ƴϸ� ��ü�� �ּ� ���̳Ŀ� ���̰� ����.

// Point ��ü�� �����ϴ� �迭 ����� Ŭ����
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

// Point ��ü�� �ּҸ� �����ϴ� �迭 ����� Ŭ����
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

typedef Point* POINT_PTR;	// Point ������ ���� �ǹ��ϴ� POINT_PTR�� ����

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
	arr[0] = new Point(3, 4);	// �̷��� ��ü�� �ּ� ���� ������ ���, ���� ����� ���� ����� �ϴ� ������ �Ű� X
	arr[1] = new Point(5, 6);	
	arr[2] = new Point(7, 8);

	for (int i = 0; i << arr.GetArrLen(); i++)
		cout << *(arr[i]);
	delete arr[0];
	delete arr[1];
	delete arr[2];

	return 0;
}
// �ּ� ���� �迭�� �����ϴ� ��찡 �� �����غ�������, ���� ����� ���� ���縦 ������ �ʾƵ� �Ǽ� �� ����� �� ���� ����.
*/
