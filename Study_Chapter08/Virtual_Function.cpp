/*
기초 클래스의 포인터로 객체를 참조한 경우

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
	Base* bptr = new Derived();		// 컴파일 OK : Base형 포인터 변수는 Base 클래스를 상속받는 Derived 클래스의 객체를 가리킴.
	bptr -> DerivedFunc();			// 컴파일 Error! : C++ 컴파일러는 포인터 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단함. (실제 가리키는 객체의 자료형을 기준으로 판단 X)
	Derived* dptr = bptr;			// 컴파일 Error! : 컴파일러는 앞서 bptr이 실제로 가리키는 객체가 Derived 객체라는 사실을 기억하지 않음.

	Derived* dptr = new Derived();	// 컴파일 OK
	Base* dptr = dptr;				// 컴파일 OK : dptr은 Derived 클래스의 포인터 변수이므로,
									//            이 포인터가 가리키는 객체는 Base 클래스를 직접 혹은 간접적으로 상속하는 클래스의 객체!
}
*/

/* Object_Pointer.cpp 의 예제에서 발생하는 오류 발생의 이유를 알 수 있는 예제
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

int main(void)		// 포인터 형에 해당하는 클래스에 정의된 멤버에만 접근 가능!
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	tptr->FirstFunc();	(O)
	tptr->SecondFunc();	(O)
	tptr->ThirdFunc();	(O)

	sptr->FirstFunc();	(O)		// Second 클래스는 First 클래스를 상속받기 때문에 기초 클래스에 정의된 멤버도 접근 가능
	sptr->SecondFunc();	(O)
	sptr->ThirdFunc();	(X)		// Second 클래스에 정의된 멤버만 접근 가능

	fptr->FirstFunc();	(O)
	fptr->SecondFunc();	(X)
	fptr->ThirdFunc();	(X)
}
*/

/* 가상 함수 : Virtual Function
* Object_Pointer.cpp 의 주석을 해제하는데 필요한 해답

#include <iostream>
using namespace std;

class First
{
public:
	void MyFunc() { cout << "FirstFunc" << endl; };		// MyFunc 함수가 오버라이딩 되었음.
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

	fptr->MyFunc();		// FirstFunc	// MyFunc 함수를 오버라이딩 했다는 것은, 해당 객체에서 호출되어야 하는 함수를 바꾼다는 의미인데,
	sptr->MyFunc();		// SecondFunc	// 포인터 변수의 자료형에 따라서 호출되는 함수의 종류가 달라지는 것은 문제가 있어보임.
	tptr->MyFunc();		// ThirdFunc	// 이때 가상함수를 이용하는 것!
	delete tptr;
	return 0;
}

class First
{
public:
	virtual void MyFunc() { cout << "FirstFunc" << endl; };		// 이렇게 virtual 선언을 해주면, 
};																// 해당 함수호출 시, 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정
																// 이 가상함수를 오버라이딩 하는 함수도 가상함수가 됨.

class Second: public First
{
public:
	virtual void MyFunc() { cout << "SecondFunc" << endl; };	// virtual 로 선언하지 않아도 가상함수가 됨.
};

class Third: public Second
{
public:
	virtual void MyFunc() { cout << "ThirdFunc" << endl; };		// virtual 로 선언하지 않아도 가상함수가 됨.
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

// 가상 함수 적용 + 순수 가상함수!
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Employee		// 이 클래스는 기초 클래스로서 의미를 가질 뿐, 객체의 생성을 목적으로 정의된 클래스는 아님.
{					// Employee* emp = new Employee("Shin Min Kyu"); 와 같은 문장이 만들어지는 것은 실수임.
private:						// 하지만 문법적으로는 아무런 문제가 없기 때문에, 컴파일러에 의해서 발견되지 않음. 
	char name[100];				// 따라서 가상함수를 '순수 가상함수'로 선언하여 객체의 생성을 문법적으로 막는 것이 좋음.
public:	
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const			// 가상 함수
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const			// 가상 함수
	{ }
	/* 순수 가상함수							// 이렇게 순수 가상함수를 선언하게 되면, 해당 클래스는 객체생성이 불가능한 '추상 클래스'가 됨.
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
	*/
};

class PermanentWorker : public Employee
{
private:
	int salary;		// 월급여
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money)
	{ }
	int GetPay() const		// 기초 클래스(Employee)의 가상함수 GetPay 를 오버라이딩 함.
	{
		return salary;
	}
	void ShowSalaryInfo() const		// 기초 클래스(Employee)의 가상함수 ShowSalaryInfo 를 오버라이딩 함.
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
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time)		// 일한 시간의 추가
	{
		workTime += time;
	}
	int GetPay() const		// 이 달의 급여		// 기초 클래스의 GetPay 가상함수를 오버라이딩 함.
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const		// 기초 클래스의 ShowSalaryInfo() 가상함수를 오버라이딩 함.
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
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const		// 기초 클래스(PermanentWorker)의 GetPay 가상함수를 오버라이딩 함.
	{
		return PermanentWorker::GetPay()
			+ (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const			// 기초 클래스(PermanentWorker)의 ShowSalaryInfo 가상함수를 오버라이딩 함.
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;		// SalesWorker의 GetPay 함수가 호출됨.
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
			empList[i] -> ShowSalaryInfo();		// ShowSalaryInfo 함수는 가상함수이므로 가장 마지막에 오버라이딩을 진행한 함수가 호출
		}
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();		// GetPay 함수는 가상함수이므로 가장 마지막에 오버라이딩을 진행한 함수가 호출
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
	EmployeeHandler handler;		// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성

	// 정규직 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// 임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("JUN", 700);
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


/* 다형성 - 문장은 같은데 결과가 다르다.
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