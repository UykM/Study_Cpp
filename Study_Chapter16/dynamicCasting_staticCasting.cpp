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

/*	dynamic_cast 연산자도 기초 클래스의 포인터 및 참조형 데이터를 유도 클래스의 포인터 및 참조형으로의 형 변환을 허용하는 경우
* ->  기초 클래스가 'Polymorphic 클래스' 인 경우 : Polymorphic 클래스란, 하나 이상의 가상합수를 지니는 클래스
*/

#include <iostream>
using namespace std;

class SoSimple		// Polymorphic 클래스
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple
{
public:
	void ShowSimpleInfo()
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void)
{
	SoSimple* simPtr = new SoComplex;		// 
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);	// 이처럼 기초 클래스인 SoSimple이 Polymorphic 클래스이므로, 
															// dynamic_cast 연산자로 기초 클래스인 SoSimple형 포인터 변수 simPtr을 유도 클래스인 SoComplex형 포인터로 형 변환 가능
															
															// dynamic_cast 연산자와 static_cast 연산자의 차이점이 드러나는 부분
															// 또한, Sosimple형 포인터 변수가 실제로 가리키는 객체는 SoComplex 객체임.
															// 즉, 포인터 변수 simPtr이 가리키는 객체를 SoComplex형 포인터 변수 comPtr이 함께 가리켜도 문제없기 떄문에 dynamic_cast로 형 변환이 가능한 것!
	comPtr->ShowSimpleInfo();
	return 0;														
}

// 유도 클래스의 포인터 및 참조형으로의 형 변환을 시도할 때, 사용할 수 있는 두 연산자
// dynamic_cast
// static_cast
// 두 연산자의 차이점은 결과에 있음.
/*
#include <iostream>
using namespace std;

class SoSimple		// Polymorphic 클래스
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple
{
public:
	void ShowSimpleInfo()
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void)
{
	SoSimple* simPtr = new SoSimple;						// 전 예제와 달리 SoSimple형 포인터 변수 simPtr이 실제로 가리키는 객체가 SoSimple 객체임.
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);	// 따라서, 포인터 변수 simPtr이 가리키는 대상을 SoComplex형 포인터 변수 comPtr이 가리킬 수 없는 상황임. 
	if(comPtr == NULL)										// 이러한 경우엔 형 변환 결과로 NULL 포인터가 반환됨.
		cout << "형 변환 실패" << endl;		
	else
		comPtr->ShowSimpleInfo();
	return 0;
}

//	이러한 예제를 통해 알 수 있는 사실
->	dynamic_cast 연산자는 안정적인 형 변환을 보장!
->	그렇기 떄문에, 실행속도는 늦어지지만, 그만큼 안정적인 형 변환이 가능함.

반대로 static_cast 연산자는 안정성을 보장 X!
*/

/*	bast_cast 예외 : dynamic_cast 연산자를 이용한 형 변환의 과정에서 발생할 수 있는 예외
class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple
{
public:
	void SHowSimpleInfo()
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void)
{
	SoSimple simObj;
	SoSimple& ref = simObj;		// 참조자 ref가 실제 참조하는 대상 => SoSimple 객체

	try
	{
		SoComplex& comRef = dynamic_cast<SoComplex&>(ref);		// 따라서 SoComplex 참조형으로의 형 변환은 안전 X, 그리고 참조자를 대상으로는 NULL 반환도 X
																// 이러한 상황에선 bad_cast 예외 발생
																// 이처럼 참조형을 대상으로 dynamic_cast 연산을 진행할 경우엔 
																// bad_cast 예외가 발생할 수 있기 때문에 반드시 이에 대한 예외처리를 해야함!
		comRef.ShowSimpleInfo();
	}
	catch (bad_cast expt)
	{
		cout << expt.what() << endl;		// what 함수 : 예외의 원인을 문자열의 형태로 반환
	}
	return 0;
}
*/

