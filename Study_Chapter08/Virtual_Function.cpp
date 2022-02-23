/*
���� Ŭ������ �����ͷ� ��ü�� ������ ���

class Base
{
public:
	void BaseFunc() { cout << "Base Function" << endl; }
};

class Derived : public Base
{
public:
	void DerivedFunc() { cout << "Derived Function" << endl; }
};

int main(void)
{
	Base* bptr = new Derived();		// ������ OK : Base�� ������ ������ Base Ŭ������ ��ӹ޴� Derived Ŭ������ ��ü�� ����Ŵ.
	bptr -> DerivedFunc();			// ������ Error! : C++ �����Ϸ��� ������ ������ ���ɼ� ���θ� �Ǵ��� ��, �������� �ڷ����� �������� �Ǵ���. (���� ����Ű�� ��ü�� �ڷ����� �������� �Ǵ� X)
	Derived* dptr = bptr;			// ������ Error! : �����Ϸ��� �ռ� bptr�� ������ ����Ű�� ��ü�� Derived ��ü��� ����� ������� ����.

	Derived* dptr = new Derived();	// ������ OK
	Base* dptr = dptr;				// ������ OK : dptr�� Derived Ŭ������ ������ �����̹Ƿ�,
									//            �� �����Ͱ� ����Ű�� ��ü�� Base Ŭ������ ���� Ȥ�� ���������� ����ϴ� Ŭ������ ��ü!
}
*/

/* Object_Pointer.cpp �� �������� �߻��ϴ� ���� �߻��� ������ �� �� �ִ� ����
class First
{
public:
	void FirstFunc() { ... };
};

class Second: public First
{
public:
	void SecondFunc() { ... };
};

class Third: public Second
{
public:
	void ThirdFunc() { ... };
};

int main(void)		// ������ ���� �ش��ϴ� Ŭ������ ���ǵ� ������� ���� ����!
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	tptr->FirstFunc();	(O)
	tptr->SecondFunc();	(O)
	tptr->ThirdFunc();	(O)

	sptr->FirstFunc();	(O)		// Second Ŭ������ First Ŭ������ ��ӹޱ� ������ ���� Ŭ������ ���ǵ� ����� ���� ����
	sptr->SecondFunc();	(O)
	sptr->ThirdFunc();	(X)		// Second Ŭ������ ���ǵ� ����� ���� ����

	fptr->FirstFunc();	(O)
	fptr->SecondFunc();	(X)
	fptr->ThirdFunc();	(X)
}
*/

/* ���� �Լ� : Virtual Function
* Object_Pointer.cpp �� �ּ��� �����ϴµ� �ʿ��� �ش�

#include <iostream>
using namespace std;

class First
{
public:
	void MyFunc() { cout << "FirstFunc" << endl; };		// MyFunc �Լ��� �������̵� �Ǿ���.
};

class Second: public First
{
public:
	void MyFunc() { cout << "SecondFunc" << endl; };
};

class Third: public Second
{
public:
	void MyFunc() { cout << "ThirdFunc" << endl; };
};

int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();		// FirstFunc	// MyFunc �Լ��� �������̵� �ߴٴ� ����, �ش� ��ü���� ȣ��Ǿ�� �ϴ� �Լ��� �ٲ۴ٴ� �ǹ��ε�,
	sptr->MyFunc();		// SecondFunc	// ������ ������ �ڷ����� ���� ȣ��Ǵ� �Լ��� ������ �޶����� ���� ������ �־��.
	tptr->MyFunc();		// ThirdFunc	// �̶� �����Լ��� �̿��ϴ� ��!
	delete tptr;
	return 0;
}

class First
{
public:
	virtual void MyFunc() { cout << "FirstFunc" << endl; };		// �̷��� virtual ������ ���ָ�, 
};																// �ش� �Լ�ȣ�� ��, ������ ������ ������ ����Ű�� ��ü�� �����Ͽ� ȣ���� ����� ����
																// �� �����Լ��� �������̵� �ϴ� �Լ��� �����Լ��� ��.

class Second: public First
{
public:
	virtual void MyFunc() { cout << "SecondFunc" << endl; };	// virtual �� �������� �ʾƵ� �����Լ��� ��.
};

class Third: public Second
{
public:
	virtual void MyFunc() { cout << "ThirdFunc" << endl; };		// virtual �� �������� �ʾƵ� �����Լ��� ��.
};

int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();		// ThirdFunc
	sptr->MyFunc();		// ThirdFunc 
	tptr->MyFunc();		// ThirdFunc
	delete tptr;
	return 0;
}
*/

// ���� �Լ� ���� + ���� �����Լ�!
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Employee		// �� Ŭ������ ���� Ŭ�����μ� �ǹ̸� ���� ��, ��ü�� ������ �������� ���ǵ� Ŭ������ �ƴ�.
{					// Employee* emp = new Employee("Shin Min Kyu"); �� ���� ������ ��������� ���� �Ǽ���.
private:						// ������ ���������δ� �ƹ��� ������ ���� ������, �����Ϸ��� ���ؼ� �߰ߵ��� ����. 
	char name[100];				// ���� �����Լ��� '���� �����Լ�'�� �����Ͽ� ��ü�� ������ ���������� ���� ���� ����.
public:	
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const			// ���� �Լ�
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const			// ���� �Լ�
	{ }
	/* ���� �����Լ�							// �̷��� ���� �����Լ��� �����ϰ� �Ǹ�, �ش� Ŭ������ ��ü������ �Ұ����� '�߻� Ŭ����'�� ��.
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
	*/
};

class PermanentWorker : public Employee
{
private:
	int salary;		// ���޿�
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money)
	{ }
	int GetPay() const		// ���� Ŭ����(Employee)�� �����Լ� GetPay �� �������̵� ��.
	{
		return salary;
	}
	void ShowSalaryInfo() const		// ���� Ŭ����(Employee)�� �����Լ� ShowSalaryInfo �� �������̵� ��.
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee		// �ӽ���
{
private:
	int workTime;		// �� �޿� ���� �ð��� �հ�
	int payPerHour;		// �ð��� �޿�
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time)		// ���� �ð��� �߰�
	{
		workTime += time;
	}
	int GetPay() const		// �� ���� �޿�		// ���� Ŭ������ GetPay �����Լ��� �������̵� ��.
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const		// ���� Ŭ������ ShowSalaryInfo() �����Լ��� �������̵� ��.
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker		// ������
{
private:
	int salesResult;	// �� �ǸŽ���
	double bonusRatio;	// �󿩱� ����
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const		// ���� Ŭ����(PermanentWorker)�� GetPay �����Լ��� �������̵� ��.
	{
		return PermanentWorker::GetPay()
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const			// ���� Ŭ����(PermanentWorker)�� ShowSalaryInfo �����Լ��� �������̵� ��.
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;		// SalesWorker�� GetPay �Լ��� ȣ���.
	}
};

class EmployeeHandler		
{
private:
	Employee* empList[50];	
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
		{
			empList[i] -> ShowSalaryInfo();		// ShowSalaryInfo �Լ��� �����Լ��̹Ƿ� ���� �������� �������̵��� ������ �Լ��� ȣ��
		}
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();		// GetPay �Լ��� �����Լ��̹Ƿ� ���� �������� �������̵��� ������ �Լ��� ȣ��
		}
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
		{
			delete empList[i];
		}
	}
};

int main(void)
{
	EmployeeHandler handler;		// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü ����

	// ������ ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// �ӽ��� ���
	TemporaryWorker* alba = new TemporaryWorker("JUN", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// ������ ���
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);		// �������� 7000
	handler.AddEmployee(seller);

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;
}


/* ������ - ������ ������ ����� �ٸ���.
class First
{
public:
	virtual void SimpoleFunc() { cout << "First" << endl; }
};

class Second
{
public:
	virtual void SimpoleFunc() { cout << "Second" << endl; }
};

int main(void)
{
	First* ptr = new First();
	ptr->SimpleFunc();			// First
	delete ptr;

	ptr = new Second();
	ptr->SimpleFunc();
	delete ptr;					// Second
	return 0;
*/