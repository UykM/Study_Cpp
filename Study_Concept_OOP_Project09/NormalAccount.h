#pragma once
#include "Account.h"
#include "String.h"
#include "AccountException.h"

class NormalAccount : public Account
{
private:
	int interRate;	// ������ %����
public:
	NormalAccount(int ID, int money, String cusName, int rate)
		: Account(ID, money, cusName), interRate(rate)
	{ }
	virtual void Deposit(int money)
	{
		if (money < 0)
			throw MinusException(money);

		Account::Deposit(money);	// �����߰�
		Account::Deposit(money * (interRate / 100.0));		// �����߰�
	}
};
