#include <iostream>
using namespace std;

#define ID_LEN	20			// 매크로 상수
#define MAX_SPD	200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

/* 위 매크로 상수들은 구조체 Car에만 쓰이기 때문에, 열거형 enum을 이용해서 구조체 내에서만 유효한 상수를 정의.
struct Car
{
	enum
	{
		ID_LEN		20
		MAX_SPD		200
		FUEL_STEP	2
		ACC_STEP	10
		BRK_STEP	10
	};

	...
}
*/

/* namespace 를 이용해서 상수가 사용되는 영역을 명시하는 것도 가능. (Code_3)
(몇몇 구조체들 사이에서만 사용하는 상수를 선언할 때 특히 도움되며, 위에서 사용한 방법보다 가독성이 좋음)

*/

struct Car
{
	char gamerID[ID_LEN];	// 소유자ID
	int fuelGauge;			// 연료량
	int curSpeed;			// 현재속도

/* 구조체 안에 함수 삽입한 경우 - Code_2

	void ShowCarState()
	{
		cout << "소유자ID: " << gamerID << endl;
		cout << "연료량: " << fuelGauge << "%" << endl;
		cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
	}

	void Accel()
	{
		if (fuelGauge <= 0)
		{
			return;
		}
		else
		{
			car.fuelGauge -= FUEL_STEP;
		}

		if (curSpeed + ACC_STEP >= MAX_SPD)
		{
			curSpeed = MAX_SPD;
			return;
		}

		curSpeed += ACC_STEP;
	}

	void Break()
	{
		if(curSpeed < BRK_STEP)
		{
			curSpeed = 0;
			return;
		}

		car.curSpeed -= BRK_STEP;
	}

*/

};

/* (Code_2)

int main(void)
{
	Car run99 = { "run99", 100, 0 };
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();

	Car sped77 = { "sped77", 100, 0 };
	sped77.Accel();
	sped77.Accel();
	sped77.ShowCarState();
	return 0;
}

*/

void ShowCarState(const Car& car)
{
	cout << "소유자ID: " << car.gamerID << endl;
	cout << "연료량: " << car.fuelGauge << "%" << endl;
	cout << "현재속도: " << car.curSpeed << "km/s" << endl << endl;
}

void Accel(Car& car)
{
	if (car.fuelGauge <= 0)
	{
		return;
	}
	else
	{
		car.fuelGauge -= FUEL_STEP;
	}

	if (car.curSpeed + ACC_STEP >= MAX_SPD)
	{
		car.curSpeed = MAX_SPD;
		return;
	}

	car.curSpeed += ACC_STEP;
}

void Break(Car& car)
{
	if (car.curSpeed < BRK_STEP)
	{
		car.curSpeed = 0;
		return;
	}

	car.curSpeed -= BRK_STEP;
}

int main(void)
{
	Car run99 = { "run99", 100, 0 };
	Accel(run99);
	Accel(run99);
	ShowCarState(run99);
	Break(run99);
	ShowCarState(run99);

	Car sped77 = { "sped77", 100, 0 };
	Accel(sped77);
	Break(sped77);
	ShowCarState(sped77);
	return 0;
}

/* Code_3

namespace CAR_CONST
{
	enum
	{
		ID_LEN		20
		MAX_SPD		200
		FUEL_STEP	2
		ACC_STEP	10
		BRK_STEP	10
	};
}

struct Car
{
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState();		// 함수를 외부로 뺄 수 있음.
	void Accel();
	void Break();

	// 명시적으로 inline 처리 (함수를 외부로 뺀 후에도 inline 을 유지하려면 키워드 inline 을 이용해서 inline 처리)
	// inline void ShowCarState();
	// inline void Accel();
	// inline void Break();
};

void Car::ShowCarState()       // 함수를 외부로 뺀 경우 - 구조체 내에 정의한 함수가 많거나 그 길이가 긴 경우
{
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
}

void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
	Car run99 = { "run99", 100, 0 };
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}
*/
