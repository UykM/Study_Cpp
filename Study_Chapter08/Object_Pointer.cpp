/* ��ü �����ʹ� ���� Ŭ������ ��ü���� ����ų �� ����.(IS - A ������ �������� ����)
#include <iostream>
using namespace std;

class Person
{
public:
	void Sleep()
	{
		cout << "Sleep" << endl;
	}
};

class Student : public Person
{
public:
	void Study()
	{
		cout << "Study" << endl;
	}
};

class PartTimeStudent : public Student
{
public:
	void Work()
	{
		cout << "Work" << endl;
	}
};

int main(void)
{
	Person* ptr1 = new Student();				// 33~35���� ���� ���� �����ϵǰ� ����Ǿ��ٴ� ����� �߿�!
	Person* ptr2 = new PartTimeStudent();		// PartTimeStudent�� Person�� ���� ����ϹǷ�, Person�� ������ ������ PartTimeStudent ��ü�� ����ų �� �ִ� ��.
	Student* ptr3 = new PartTimeStudent();		// PartTimeStudent�� Student�� ����ϹǷ�, Student�� ������ ������ PartTimeStudent ��ü�� ����ų �� �ִ� ��.
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1;
	delete ptr2;
	delete ptr3;
	return 0;
}
*/

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;		// ���޿�
public:
	PermanentWorker(const char *name, int money)
		: Employee(name), salary(money)
	{ }
	int GetPay() const		// �������̵� ��.
	{
		return salary;
	}
	void ShowSalaryInfo() const		// �������̵� ��.
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
	TemporaryWorker(const char *name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time)		// ���� �ð��� �߰�
	{
		workTime += time;
	}
	int GetPay() const		// �� ���� �޿�
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const	
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
	SalesWorker(const char * name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const		// �Լ� �������̵�(function overriding) : �Լ� �����ε��� �ٸ� ����
							// �������̵��� ���� Ŭ����(PermanentWorker)�� �Լ��� �������̵��� �� ���� Ŭ������ �Լ��� ������.
							// ���� SalesWorker(���� Ŭ����) Ŭ���� ������ GetPay �Լ��� ȣ���ϸ�, SalesWorker Ŭ������ ���ǵ� �� GetPay �Լ��� ȣ���.
	{
		return PermanentWorker::GetPay()		// PermanentWorker �� GetPay �Լ� ȣ�� - �̷� ������ Ŭ������ �̸��� ��������ν� ���� Ŭ������ �������̵� �� �Լ��� ȣ��
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const		// ���� Ŭ����(PermanentWorker)�� ShowSalaryInfo �Լ��� �������̵� ��.
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;		// SalesWorker�� GetPay �Լ��� ȣ���.
	}
};

class EmployeeHandler		// EmployeeHandler Ŭ������ ��ü�� TemporaryWorker, SalesWorker Ŭ������ �߰��Ǳ� ���� ������ ���ٴ� ���� �߿�!
{
private:
	Employee* empList[50];		// �� �κ��� �ٽ�!
								// Employee Ŭ������ ����ϴ� Ŭ����(PermanentWorker)�� ��ü�� �� �迭�� �Բ� ���� ����.
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
		/* �� �κп��� ������ ������ �߻��ϴ� ���� -> Virtual_Function.cpp
		* �迭�� �����ϴ� empList[50] ������ ������ Employee�� ������ �����̹Ƿ�, Employee Ŭ������ ����� �ƴ� GetPay, ShowSalaryInfo �Լ��� ȣ��κп��� ������ ���� �߻�
		for (int i = 0; i < empNum; i++)
		{
			empList[i] -> ShowSalaryInfo();
		}
		*/
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		*/
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
	TemporaryWorker * alba = new TemporaryWorker("JUN", 700);
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



