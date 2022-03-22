#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel)
	{ }
	void ShowCarState() { cout << "�ܿ� ���ᷮ: " << fuelGauge << endl; }
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
		cout << "ȭ���� ����: " << freightWeight << endl;
	}
};

int main(void)
{
	/*
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = (Truck*)pcar1;		// ���� Ŭ������ ������ ���� ���� Ŭ������ ������ ������ �� ��ȯ�ϴ� ���� �Ϲ����� ����� �� ��ȯ�� �ƴ�.
										// ������ ������ ���� pcar1�� ����Ű�� ����� �����δ� Truck ��ü�̱� ������ ������ ���� ���� �� ����.
										// �׷��� �̰��� ���α׷����� �ǵ�����, �ƴϸ� �Ǽ����� �� ��� X
										// �� ��, static_cast �� ��ȯ �����ڸ� ����Ͽ� �ǵ������� �����Ѵٴ� ���� ����ؾ� ��.
	*/
	Car* pcar2 = new Car(120);
	Truck* ptruck2 = (Truck*)pcar2;		// �������� ����������, ������ ���� pcar2�� ����Ű�� ����� Car ��ü�̱� ������ �� ��ȯ ���꿡 ������ ����.
										// ���� �̷��� �� ��ȯ�� � �� ��ȯ �����ڸ� ������ ���� �Ұ��� !

	//	dynamic_cast: ��Ӱ��迡���� ������ �� ��ȯ
	//	dynamic_cast<T>(expr) 
	//	�������� ������ �� �ִ� �� ��ȯ ������
	Truck* ptruck3 = new Truck(70, 150);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3);		// ��Ӱ��迡 �ִ� ���� Ŭ������ ������ �� ������ �����͸� ���� Ŭ������ ������ �� ������ �����ͷ� �� ��ȯ�ϰڴٴ� �ǹ�

	//	static_cast: A Ÿ�ӿ��� B Ÿ������
	//	static_cast<��ȯ�ϰ��� �ϴ� �ڷ����� �̸�: ��ü�� ������ �Ǵ� ������>(��ȯ�� ���) 
	//	���� Ŭ������ ������ �� ������ �����͵� ���� Ŭ������ ������ �� ������ �����ͷ� �ƹ��� ���� ���� �� ��ȯ��Ŵ
	//	������, ���� ���� �� ��ȯ�� ����ϴ� �� ��ȯ �������� ��ŭ, ���� å���� �� �ִ� ��Ȳ������ ����ؾ� ��!
	//	���� ���, pcasr2�� �� ��ȯ�� �ϰ� �Ǹ� å���� �� ���� ��.
	//	static_cast �����ڰ� dynamic_cast �����ں��� ������ ��.
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = static_cast<Truck*>(pcar1);
	ptruck1->ShowTruckState();

	return 0;
}