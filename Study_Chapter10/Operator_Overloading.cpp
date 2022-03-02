// ������ �����ε�
// ����Լ��� ���� ������ �����ε��� ��
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
	Point operator+(const Point& ref) const		// operator+ ��� �̸��� �Լ�, �����ڸ� �����ε��� �Լ��� const�� ������ ������.
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
	// Point pos3 = pos2.operator+(pos1);	pos2 ��ü�� ����Լ��� ȣ���ϴ� ���·� ���� �����ص� ����� ����.
	// Point pos3 = pos1 + pos2;	������ ���� : Point pos3 = pos1.operator+(pos2)�� �ؼ��Ǿ ������ ��.

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
}

// �����Լ��� ���� ������ �����ε��� ��
// Ư���� ��찡 �ƴϸ� ����Լ��� ������� �����ڸ� �����ε� �ϴ� �� ����.
// ���� �����Լ��� �����ڸ� �����ε� �ؾ߸� �ϴ� ��Ȳ�� ����.
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
	friend Point operator+(const Point& pos1, const Point& pos2);		// operator+ �Լ��� ���� private ������ ������ ���
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

// �����ε��� �Ұ����� �����ڵ� ����

// ����Լ��θ� �����ε��� ������ ������
/* 
* =		���� ������
* ()	�Լ� ȣ�� ������
* []	�迭 ���� ������(�ε��� ������)
* ->	��� ������ ���� ������ ������
* 
* ��ü�� ������� �����ؾ� �ǹ̰� ���ϴ� �������̱� ������.
*/

/* ������ �����ε� ���ǻ���
1) ������ �ǵ��� ��� ������ ������ �����ε� X
2) �������� �켱������ ���ռ��� ���� X
3) �Ű������� ����Ʈ �� ������ �Ұ���
4) �������� ���� ��ɱ��� ������ �� ����
*/


// ���� �������� �����ε�
// ��ǥ������, ���� ������(++)�� ���� ������(--)�� ����.
// ���� �����ڿ��� ū �������� �ǿ������� ����
/* �߰� - ��������, ���������� ������ �����ε�
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
	Point& operator++()		// ����Լ��� ���·� �����ε�
	{
		xpos += 1;
		ypos += 1;
		return *this;		// ��ȯ���� �������̱� ������, ��ü �ڽ��� ������ �� �ִ� '���� ��'�� ��ȯ��.
	}
	const Point operator++(int)		// �������� - ��ȯ���� const
	{
		const Point retobj(xpos, ypos);		// const Point retobj(*this);	
											// ��ȯ�� ����� �Ǵ� �� ��ü�� const ���������� ��ü�� ��ȯ�� �ƹ��� ���� X
											// �Լ� ������ �ӽð�ü retobj�� ������ ���ڴٴ� �ǹ�
											// '��ȯ���� const ����'���� ���� ������ ������� �ʴ� const ��ü(��� ��ü)
		xpos+=1;
		ypos+=1;
		return retobj;
	}
	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref)		// �����Լ��� ���·� �����ε�
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point operator--(Point &ref, int)		// �������� - ��ȯ���� const
{
	const Point retobj(ref);	// �Լ� ������ �ӽð�ü retobj�� ������ ���ڴٴ� �ǹ�
								// ��ȯ�� ����� �Ǵ� �� ��ü�� const ���������� ��ü�� ��ȯ�� �ƹ��� ���� X
								// '��ȯ���� const ����'���� ���� ������ ������� �ʴ� const ��ü(��� ��ü)
	ref.xpos-=1;
	ref.ypos-=1;
	return retobj;
}

int main(void)
{
	Point pos(3, 5);
	++pos;		// pos.operator++(); �� �ؼ�
	pos.ShowPosition();
	--pos;		// operator--(pos); �� �ؼ�
	pos.ShowPosition();

	Point cpy;
	cpy = pos--;
	cpy.ShowPosition();		// [3, 5]
	pos.ShowPosition();		// [2, 4]

	cpy = pos++;
	cpy.ShowPosition();		// [2, 4]
	pos.ShowPosition();		// [3, 5]

	++(++pos);			// ++(pos.operator++());
						// ++(pos�� ���� ��);
						// (pos�� ���� ��).operator++();
	pos.ShowPosition();
	--(--pos);			// --(operator--(pos));
						// --(pos�� ���� ��);
						// operator--(pos�� ���� ��);
	pos.ShowPosition();
	return 0;
}


// �� const �Լ��� �ӽ� ��ü�� ������δ� const�� ������� ���� ����Լ��� ȣ���� �Ұ���!
int main(void)
{
	Point pos(3, 5);
	(pos++)++;		// ������ Error!	// (Point�� const �ӽð�ü)++;
										// (Point�� const �ӽð�ü).operator++();	: operator++(int)�� ȣ��
										// operator++ ����Լ��� const�� ����� �Լ��� �ƴ�.

	(pos--)--;		// ������ Error!	// (Point�� const �ӽð�ü)--;
										// operator--(Point�� const �ӽð�ü);	   : operator--(Point &ref, int)�� ȣ��
										// �����Լ� operator--(Point &ref, int) ���� �Ű������� ����� ������ &ref�� const�� ������� ����.
	...
}

// C++ ����Ư��
int main(void)
{
	int num = 100;
	++(++num);		// ������ OK!
	(num++)++;		// ������ Error!
}
*/
