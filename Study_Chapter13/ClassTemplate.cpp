#include <iostream>
using namespace std;

/*
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

�� Ŭ������ ��ǥ������ ������ ǥ���ϵ��� ���ǵǾ� ����. 
���� �Ǽ��� ���·� ��ǥ�� ǥ���ؾ� �ϰų�, ������ ���·� �·Ḧ ǥ�� �� ����ؾ� �ϴ� ��쿡�� ������ Ŭ������ �����ؾ� ��.
�̷� ���ŷο��� ���ֱ� ���� Ŭ���� ���ø��� ������!
*/

/*
// Ŭ���� ���ø�
template <typename T>		// template <typename T = int>	 
class Point			
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main(void)
{
	Point<int> pos1(3, 4);		// ���ø� �Լ��� ȣ���� ��ó�� �ڷ��� ������ �����ϴ� ���� �Ұ���!
								// Ŭ���� ���ø� ����� ��ü�������� �ݵ�� �ڷ��� ������ ����ؾ� ��.
								// ���ø� �μ� T�� int������ ����Ʈ ���� ������ ��쿣,
								// Point<> obj1(n1, n2); ó�� �ڷ��� ������ ���������� int������ �ν���.
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');		// ��ǥ������ ���ڷ� ǥ���ϴ� ��Ȳ�� ǥ��
	pos3.ShowPosition();
	return 0;
}

�� Point!
Ŭ���� ���ø��� �ϼ��� Ŭ������ �ƴ϶� �ʿ��� Ŭ�������� �̾Ƴ��� ���� Ŭ������ Ʋ�̶�� ����ϱ�

*/

// Ŭ���� ���ø��� ������� �Լ��� ���� �и�
#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;
};

// Ŭ���� ���ø��� ����Լ��� �ܺο� ����
template <typename T>							// Ŭ���� ���ø��� ���ǿ� �Լ��� ���Ǵ� ������ �����̱� ������ ���� T�� ������ �ǹ��ϴ��� �˷��־�� ��.
Point<T>::Point(T x, T y) : xpos(x), ypos(y)	// Point<T> : T�� ���� ���ø�ȭ �� Point Ŭ���� ���ø��̶�� �ǹ�
{ }

template <typename T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

int main(void)
{
	Point<int> pos1(3, 4);		
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();
	return 0;
}