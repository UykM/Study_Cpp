#include <iostream>
using namespace std;


int BoxVolume(int length, int width, int height)
{
	return length * width * height;
}
int BoxVolume(int length, int width)
{
	return length * width * 1;
}

int BoxVolume(int length)
{
	return length * 1 * 1;
}

int main()
{
	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << "[7, D, D] : " << BoxVolume(7) << endl;
	//	cout << "[D, D, D] : " << BoxVolume() << endl;  - 컴파일 오류!
	return 0;
}