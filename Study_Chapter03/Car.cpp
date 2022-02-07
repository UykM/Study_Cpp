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
	cout << "������ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
}

/* Inline Function �� Ŭ����(ex. Class Car)�� ����� ������ ���Ͽ� ����Ǿ�� ��. 

Inline void Car::ShowCarState()
{
	...
}

����Լ� ShowCarState �� Inline Function �̶��,
�̷��� �Լ�(ShowCarState) ��ü �κ���
Class Car �� ����� ��������� Car.h �� ����Ǿ�� ��.

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