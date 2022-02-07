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

/* �ζ��� �Լ�(Inline Fuction)
* ���� - �Լ� ���Ǻΰ� ���� �ڵ带 ��ü�ϹǷ�, ���� �� ������带 ���� �� ����.
* ���� - ������ �Լ��� ������������ �ζ��̴��ϸ� ������ ���� ���ϸ� ����Ŵ.

Inline void Car::ShowCarState()
{
	cout << "������ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
}
*/

