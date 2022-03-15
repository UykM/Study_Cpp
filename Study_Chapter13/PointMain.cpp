#include <iostream>
#include "PointTemplate.h"
#include "PointTemplate.cpp"	// 컴파일은 파일단위로 이루어짐. 
								// 따라서, "PointTemplate.cpp"과 "PointMain.cpp"는 서로 다른 소스파일이기 때문에, 
								// 한 소스파일을 컴파일 할때, 참조 선언이 돼있지 않은 다른 소스파일은 참조하지 않음.
using namespace std;

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