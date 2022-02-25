#pragma once

class Account
{
private:
	int accID;		// 계좌번호
	int money;		// 잔액
	char* cusName;	// 고객 이름
public:
	Account(int _accID, int _money, char* _cusName);
	Account(const Account& ref);

	int GetAccID() const;
	virtual void Deposit(int _money);		// 유도 클래스인 NormalAccount, CreditClass 에서 호출하기 때문에, 가상함수 선언 필요
	int Withdraw(int _money);
	void ShowAccInfo() const;
	~Account();
};
