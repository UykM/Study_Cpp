#include <iostream>
using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int gas)
		: gasolineGauge(gas)
	{ }
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int elec)
		: Car(gas), electricGauge(elec)
	{ }
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water)
		: HybridCar(gas, elec), waterGauge(water)
	{ }
	void ShowCurrentGauge()
	{
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGauge << endl;
	}
};

int main(void)
{
	HybridWaterCar wCar(79, 65, 35);
	wCar.ShowCurrentGauge();
	return 0;
}