#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);

	void* operator new(size_t size)		// ����Լ��� ��������� static���� ����� �Լ�
	{
		cout << "operater new :	" << size << endl;
		void* adr = new char[size];
		return adr;
	}
	void* operator new[](size_t size)	// operator new [] �Լ� : �迭�Ҵ� �� ȣ��Ǵ� �Լ�
	{
		cout << "operator new [] : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	void operator delete(void* adr)		// ����Լ��� ��������� static���� ����� �Լ�
	{
		cout << "operator delete ()" << endl;
		delete[] adr;
	}
	void operator delete[](void* adr)	// delete []arr �Լ� : �迭�Ҹ� �� ȣ��Ǵ� �Լ�
	{
		cout << "ooperator delete[] ()" << endl;
		delete[]adr;
	}
};

// operator new �Լ��� operator delete �Լ��� static �Լ���.
// �׷��� ��ü������ �������� ȣ���� �����ߴ� ��

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point* ptr = new Point(3, 4);	// ��ü ��������
	cout << *ptr;
	delete ptr;
	return 0;
}