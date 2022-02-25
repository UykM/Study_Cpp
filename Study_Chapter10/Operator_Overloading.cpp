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