#pragma once

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
		ACC_STEP = 10, BRK_STEP = 10
	};
}

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(const char* ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

/* 인라인 함수(Inline Fuction)
* 장점 - 함수 정의부가 실행 코드를 대체하므로, 실행 상 오버헤드를 줄일 수 있음.
* 단점 - 복잡한 함수를 여러군데에서 인라이닝하면 오히려 성능 저하를 일으킴.

Inline void Car::ShowCarState()
{
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}
*/

