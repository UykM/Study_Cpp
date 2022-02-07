#include <iostream>
#include <cstring>
#include "Car.h"
#pragma warning(disable:4996)
using namespace std;

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState()
{
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}

/* Inline Function 은 클래스(ex. Class Car)의 선언과 동일한 파일에 저장되어야 함. 

Inline void Car::ShowCarState()
{
	...
}

멤버함수 ShowCarState 가 Inline Function 이라면,
이러한 함수(ShowCarState) 몸체 부분은
Class Car 가 선언된 헤더파일인 Car.h 에 저장되어야 함.

*/ 

void Car::Accel()
{
	if (fuelGauge <= 0)
	{
		return;
	}
	else
	{
		fuelGauge -= CAR_CONST::FUEL_STEP;
	}

	if ((curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD))
	{
		curSpeed = CAR_CONST::ACC_STEP;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
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