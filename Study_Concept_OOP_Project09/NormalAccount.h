#pragma once
#include "Account.h"
#include "String.h"

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
		Account::Deposit(money);	// �����߰�
		Account::Deposit(money * (interRate / 100.0));		// �����߰�
	}
};
