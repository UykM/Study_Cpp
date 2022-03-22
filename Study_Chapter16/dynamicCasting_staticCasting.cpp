#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel)
	{ }
	void ShowCarState() { cout << "잔여 연료량: " << fuelGauge << endl; }
};

class Truck : public Car
{
private:
	int freightWeight;

public:
	Truck(int fuel, int weight)
		: Car(fuel), freightWeight(weight)
	{}
	void ShowTruckState()
	{
		ShowCarState();
		cout << "화물이 무게: " << freightWeight << endl;
	}
};

int main(void)
{
	/*
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = (Truck*)pcar1;		// 기초 클래스의 포인터 형을 유도 클래스의 포인터 형으로 형 변환하는 것은 일반적인 경우의 형 변환이 아님.
										// 하지만 포인터 변수 pcar1이 가리키는 대상이 실제로는 Truck 객체이기 떄문에 문제가 되지 않을 수 있음.
										// 그래서 이것이 프로그래머의 의도인지, 아니면 실수인지 알 방법 X
										// 이 때, static_cast 형 변환 연산자를 사용하여 의도적으로 진행한다는 것을 명시해야 함.
	*/
	Car* pcar2 = new Car(120);
	Truck* ptruck2 = (Truck*)pcar2;		// 컴파일은 가능하지만, 포인터 변수 pcar2가 가리키는 대상이 Car 객체이기 때문에 형 변환 연산에 문제가 있음.
										// 따라서 이러한 형 변환은 어떤 형 변환 연산자를 쓰더라도 절대 불가능 !

	//	dynamic_cast: 상속관계에서의 안전한 형 변환
	//	dynamic_cast<T>(expr) 
	//	안정성을 높여줄 수 있는 형 변환 연산자
	Truck* ptruck3 = new Truck(70, 150);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3);		// 상속관계에 있는 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환하겠다는 의미

	//	static_cast: A 타임에서 B 타입으로
	//	static_cast<변환하고자 하는 자료형의 이름: 객체의 포인터 또는 참조형>(변환의 대상) 
	//	기초 클래스의 포인터 및 참조형 데이터도 유도 클래스의 포인터 및 참조형 데이터로 아무런 조건 없이 형 변환시킴
	//	하지만, 보다 많은 형 변환을 허용하는 형 변환 연산자인 만큼, 정말 책임질 수 있는 상황에서만 사용해야 함!
	//	예를 들어, pcasr2를 형 변환을 하게 되면 책임질 수 없게 됨.
	//	static_cast 연산자가 dynamic_cast 연산자보다 빠르긴 함.
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = static_cast<Truck*>(pcar1);
	ptruck1->ShowTruckState();

	return 0;
}