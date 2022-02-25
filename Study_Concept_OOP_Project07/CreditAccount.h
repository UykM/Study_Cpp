#pragma once
#include "NormalAccount.h"

class CreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	CreditAccount(int ID, int money, char* cusName, int rate, int special)
		: NormalAccount(ID, money, cusName, rate), specialRate(special)
	{ }

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);		// 원금과 이자추가
		Account::Deposit(money * (specialRate / 100.0));		// 특별이자추가
	}
};