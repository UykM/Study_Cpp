#include <iostream>
using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "empty object" << endl;
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA& ref;
	const int& num;			// const 변수와 마찬가지로 참조자(reference)도 선언과 동시에 초기화가 이루어져야 함.
							// 따라서 참조자(reference)도 Initializer 를 이용하면 멤버변수로 선언될 수 있음.
public:
	BBB(AAA& r, const int& n)
		: ref(r), num(n)
	{
	}

	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num " << num << endl;
	}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
	return 0;
}