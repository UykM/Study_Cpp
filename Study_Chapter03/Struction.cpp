#include <iostream>
using namespace std;

#define ID_LEN	20			// ��ũ�� ���
#define MAX_SPD	200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

/* �� ��ũ�� ������� ����ü Car���� ���̱� ������, ������ enum�� �̿��ؼ� ����ü �������� ��ȿ�� ����� ����.
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

/* namespace �� �̿��ؼ� ����� ���Ǵ� ������ ����ϴ� �͵� ����. (Code_3)
(��� ����ü�� ���̿����� ����ϴ� ����� ������ �� Ư�� ����Ǹ�, ������ ����� ������� �������� ����)

*/

struct Car
{
	char gamerID[ID_LEN];	// ������ID
	int fuelGauge;			// ���ᷮ
	int curSpeed;			// ����ӵ�

/* ����ü �ȿ� �Լ� ������ ��� - Code_2

	void ShowCarState()
	{
		cout << "������ID: " << gamerID << endl;
		cout << "���ᷮ: " << fuelGauge << "%" << endl;
		cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
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
	cout << "������ID: " << car.gamerID << endl;
	cout << "���ᷮ: " << car.fuelGauge << "%" << endl;
	cout << "����ӵ�: " << car.curSpeed << "km/s" << endl << endl;
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

	void ShowCarState();		// �Լ��� �ܺη� �� �� ����.
	void Accel();
	void Break();

	// ��������� inline ó�� (�Լ��� �ܺη� �� �Ŀ��� inline �� �����Ϸ��� Ű���� inline �� �̿��ؼ� inline ó��)
	// inline void ShowCarState();
	// inline void Accel();
	// inline void Break();
};

void Car::ShowCarState()       // �Լ��� �ܺη� �� ��� - ����ü ���� ������ �Լ��� ���ų� �� ���̰� �� ���
{
	cout << "������ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
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
