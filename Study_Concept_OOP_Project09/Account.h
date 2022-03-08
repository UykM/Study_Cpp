
#pragma once
#include "String.h"

class Account
{
private:
	int accID;		// 계좌번호
	int money;		// 잔액
	String cusName;	// 고객 이름	// char* cusName;	
									// String 클래스를 적용했다고 해서 char형 포인터 기반의 문자열 표현을 억지로 제한할 필요 X
public:
	Account(int ID, int money, String name);
	// Account(int _accID, int _money, char* _cusName);
	// Account(const Account& ref);					// 복사 생성자
	// Account& operator=(const Account& ref);		// 대입 연산자 오버로딩

	int GetAccID() const;
	virtual void Deposit(int _money);		// 유도 클래스인 NormalAccount, CreditClass 에서 호출하기 때문에, 가상함수 선언 필요
	int Withdraw(int _money);
	void ShowAccInfo() const;
	// ~Account();
};