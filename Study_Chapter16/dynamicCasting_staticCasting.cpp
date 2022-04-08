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

/*	dynamic_cast �����ڵ� ���� Ŭ������ ������ �� ������ �����͸� ���� Ŭ������ ������ �� ������������ �� ��ȯ�� ����ϴ� ���
* ->  ���� Ŭ������ 'Polymorphic Ŭ����' �� ��� : Polymorphic Ŭ������, �ϳ� �̻��� �����ռ��� ���ϴ� Ŭ����
*/

#include <iostream>
using namespace std;

class SoSimple		// Polymorphic Ŭ����
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
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);	// ��ó�� ���� Ŭ������ SoSimple�� Polymorphic Ŭ�����̹Ƿ�, 
															// dynamic_cast �����ڷ� ���� Ŭ������ SoSimple�� ������ ���� simPtr�� ���� Ŭ������ SoComplex�� �����ͷ� �� ��ȯ ����
															
															// dynamic_cast �����ڿ� static_cast �������� �������� �巯���� �κ�
															// ����, Sosimple�� ������ ������ ������ ����Ű�� ��ü�� SoComplex ��ü��.
															// ��, ������ ���� simPtr�� ����Ű�� ��ü�� SoComplex�� ������ ���� comPtr�� �Բ� �����ѵ� �������� ������ dynamic_cast�� �� ��ȯ�� ������ ��!
	comPtr->ShowSimpleInfo();
	return 0;														
}

// ���� Ŭ������ ������ �� ������������ �� ��ȯ�� �õ��� ��, ����� �� �ִ� �� ������
// dynamic_cast
// static_cast
// �� �������� �������� ����� ����.
/*
#include <iostream>
using namespace std;

class SoSimple		// Polymorphic Ŭ����
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
	SoSimple* simPtr = new SoSimple;						// �� ������ �޸� SoSimple�� ������ ���� simPtr�� ������ ����Ű�� ��ü�� SoSimple ��ü��.
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);	// ����, ������ ���� simPtr�� ����Ű�� ����� SoComplex�� ������ ���� comPtr�� ����ų �� ���� ��Ȳ��. 
	if(comPtr == NULL)										// �̷��� ��쿣 �� ��ȯ ����� NULL �����Ͱ� ��ȯ��.
		cout << "�� ��ȯ ����" << endl;		
	else
		comPtr->ShowSimpleInfo();
	return 0;
}

//	�̷��� ������ ���� �� �� �ִ� ���
->	dynamic_cast �����ڴ� �������� �� ��ȯ�� ����!
->	�׷��� ������, ����ӵ��� �ʾ�������, �׸�ŭ �������� �� ��ȯ�� ������.

�ݴ�� static_cast �����ڴ� �������� ���� X!
*/

/*	bast_cast ���� : dynamic_cast �����ڸ� �̿��� �� ��ȯ�� �������� �߻��� �� �ִ� ����
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
	SoSimple& ref = simObj;		// ������ ref�� ���� �����ϴ� ��� => SoSimple ��ü

	try
	{
		SoComplex& comRef = dynamic_cast<SoComplex&>(ref);		// ���� SoComplex ������������ �� ��ȯ�� ���� X, �׸��� �����ڸ� ������δ� NULL ��ȯ�� X
																// �̷��� ��Ȳ���� bad_cast ���� �߻�
																// ��ó�� �������� ������� dynamic_cast ������ ������ ��쿣 
																// bad_cast ���ܰ� �߻��� �� �ֱ� ������ �ݵ�� �̿� ���� ����ó���� �ؾ���!
		comRef.ShowSimpleInfo();
	}
	catch (bad_cast expt)
	{
		cout << expt.what() << endl;		// what �Լ� : ������ ������ ���ڿ��� ���·� ��ȯ
	}
	return 0;
}
*/

