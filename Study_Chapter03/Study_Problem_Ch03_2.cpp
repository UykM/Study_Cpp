#include <iostream>
using namespace std;

class Calculator
{
private:
	int numOfAdd;			// 멤버변수를 여기서 초기화하는 것도 가능 / ex. int numOfAdd = 0;
	int numOfMin;			// 혹은 생성자로 초기화
	int numOfMul;			// 혹은 생성자에서 초기화 리스트로 초기화
	int numOfDiv;
public:
	void init();
	double Add(double num1, double num2);
	double Min(double num1, double num2);
	double Mul(double num1, double num2);
	double Div(double num1, double num2);
	void ShowOpCount();
};


void Calculator::init()			// 멤버변수 초기화 함수
{
	numOfAdd = 0;
	numOfMin = 0;
	numOfMul = 0;
	numOfDiv = 0;
}
double Calculator::Add(double num1, double num2)
{
	numOfAdd++;
	return num1 + num2;
}

double Calculator::Min(double num1, double num2)
{
	numOfMin++;
	return num1 - num2;
}

double Calculator::Mul(double num1, double num2)
{
	numOfMul++;
	return num1 * num2;
}

double Calculator::Div(double num1, double num2)
{
	numOfDiv++;
	return num1 / num2;
}

void Calculator::ShowOpCount()
{
	cout << "덧셈: " << numOfAdd << " 뺄셈: " << numOfMin << " 곱셈: " << numOfMul << " 나눗셈: " << numOfDiv;
}

int main(void)
{
	Calculator cal;
	cal.init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}