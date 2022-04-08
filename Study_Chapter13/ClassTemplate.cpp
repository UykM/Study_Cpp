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

이 클래스는 좌표정보를 정수로 표현하도록 정의되어 있음. 
따라서 실수의 형태로 좌표를 표현해야 하거나, 문자의 형태로 좌료를 표현 및 출력해야 하는 경우에는 별도의 클래스를 정의해야 함.
이런 번거로움을 없애기 위해 클래스 템플릿을 정의함!
*/

/*
// 클래스 템플릿
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
	Point<int> pos1(3, 4);		// 템플릿 함수를 호출할 때처럼 자료형 정보를 생략하는 것은 불가능!
								// 클래스 템플릿 기반의 객체생성에는 반드시 자료형 정보를 명시해야 함.
								// 템플릿 인수 T에 int형으로 디폴트 값을 선언한 경우엔,
								// Point<> obj1(n1, n2); 처럼 자료형 정보를 생략했을때 int형으로 인식함.
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');		// 좌표정보를 문자로 표시하는 상황의 표현
	pos3.ShowPosition();
	return 0;
}

★ Point!
클래스 템플릿은 완성된 클래스가 아니라 필요한 클래스들을 뽑아내기 위한 클래스의 틀이라고 기억하기

*/

// 클래스 템플릿을 대상으로 함수의 정의 분리
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

// 클래스 템플릿의 멤버함수를 외부에 정의
template <typename T>							// 클래스 템플릿의 정의와 함수의 정의는 완전히 별개이기 때문에 문자 T가 무엇을 의미하는지 알려주어야 함.
Point<T>::Point(T x, T y) : xpos(x), ypos(y)	// Point<T> : T에 대해 템플릿화 된 Point 클래스 템플릿이라는 의미
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