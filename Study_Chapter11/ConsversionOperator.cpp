// 형 병환 연산자의 오버로딩
#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)	// 생성자
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	operator int()		// 형 변환 연산자의 오버로딩
						// 그리고 형 변환 연산자는 반환형을 명시 X
						// 호출 시점은, 
						// operator+ 이면, + 연산자가 등장했을 때 호출되는 것과 유사하게
						// int형으로 형 변환해야 하는 상황에서 호출된다고 이해!
	{
		return num;
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num1;
	num1 = 30;		// num=Number(30);				// 임시객체의 생성
					// num.operator=(Number(30));	// 임시객체를 대상으로 하는 대입 연산자의 호출
	
	// Number형 객체가 와야 할 위치에 int형 데이터가 와서, int형 데이터를 인자로 전달받는 Number 클래스의 생성자 호출을 통해서 Number형 임시객체를 생성
	// 그리고 두 Number 객체를 대상으로 대입연산 진행
	num1.ShowNumber();

	// 반대로 객체를 기본 자료형 데이터로 형 변환도 가능함.
	// Number 클래스를 대상으로 다음와 같은 덧셈연산이 가능하려면, 
	// Number 클래스가 + 연산자를 오버로딩 하고 있거나, num1이 int형 데이터로 변환 되어야 함.

	Number num2 = num1 + 20;	// num1 객체의 operator int 함수가 호출되어, 이 때 반환되는 값 30과 20의 덧셈연산이 진행되며,
								// 이 연산의 결과로 Number 클래스의 생성자가 호출되고 num2 객체가 생성됨.
	num2.ShowNumber();
	
	return 0;
}