#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Printer
{
private:
	char str[30];			// 동적 할당을 하지 않고 이미 메모리 공간을 확보함.
public:
	void SetString(const char* s);
	void ShowString();
};

void Printer::SetString(const char* s)
{
	strcpy(str, s);
}

void Printer::ShowString()
{
	cout << str << endl;
}

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}

