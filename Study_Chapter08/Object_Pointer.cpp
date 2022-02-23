/* 객체 포인터는 유도 클래스의 객체까지 가리킬 수 있음.(IS - A 관계의 성립으로 인해)
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
	Person* ptr1 = new Student();				// 33~35행이 무리 없이 컴파일되고 실행되었다는 사실이 중요!
	Person* ptr2 = new PartTimeStudent();		// PartTimeStudent는 Person을 간접 상속하므로, Person형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있는 것.
	Student* ptr3 = new PartTimeStudent();		// PartTimeStudent는 Student를 상속하므로, Student형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있는 것.
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
	int salary;		// 월급여
public:
	PermanentWorker(const char *name, int money)
		: Employee(name), salary(money)
	{ }
	int GetPay() const		// 오버라이딩 됨.
	{
		return salary;
	}
	void ShowSalaryInfo() const		// 오버라이딩 됨.
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee		// 임시직
{
private:
	int workTime;		// 이 달에 일한 시간의 합계
	int payPerHour;		// 시간당 급여
public:
	TemporaryWorker(const char *name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time)		// 일한 시간의 추가
	{
		workTime += time;
	}
	int GetPay() const		// 이 달의 급여
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const	
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker		// 영업직
{
private:
	int salesResult;	// 월 판매실적
	double bonusRatio;	// 상여금 비율
public:
	SalesWorker(const char * name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const		// 함수 오버라이딩(function overriding) : 함수 오버로딩과 다른 개념
							// 오버라이딩된 기초 클래스(PermanentWorker)의 함수는 오버라이딩을 한 유도 클래스의 함수에 가려짐.
							// 따라서 SalesWorker(유도 클래스) 클래스 내에서 GetPay 함수를 호출하면, SalesWorker 클래스에 정의된 이 GetPay 함수가 호출됨.
	{
		return PermanentWorker::GetPay()		// PermanentWorker 의 GetPay 함수 호출 - 이런 식으로 클래스의 이름을 명시함으로써 기초 클래스의 오버라이딩 된 함수를 호출
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const		// 기초 클래스(PermanentWorker)의 ShowSalaryInfo 함수를 오버라이딩 함.
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;		// SalesWorker의 GetPay 함수가 호출됨.
	}
};

class EmployeeHandler		// EmployeeHandler 클래스의 몸체는 TemporaryWorker, SalesWorker 클래스가 추가되기 전과 변함이 없다는 점이 중요!
{
private:
	Employee* empList[50];		// 이 부분이 핵심!
								// Employee 클래스를 상속하는 클래스(PermanentWorker)의 객체도 이 배열에 함께 저장 가능.
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
		/* 이 부분에서 컴파일 에러가 발생하는 이유 -> Virtual_Function.cpp
		* 배열을 구성하는 empList[50] 포인터 변수가 Employee형 포인터 변수이므로, Employee 클래스의 멤버가 아닌 GetPay, ShowSalaryInfo 함수의 호출부분에서 컴파일 에러 발생
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
	EmployeeHandler handler;		// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성

	// 정규직 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	
	// 임시직 등록
	TemporaryWorker * alba = new TemporaryWorker("JUN", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// 영업직 등록
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);		// 영업실적 7000
	handler.AddEmployee(seller);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}



