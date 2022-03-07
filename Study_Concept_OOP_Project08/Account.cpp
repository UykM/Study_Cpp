#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int _accID, int _money, char* _cusName)
	: accID(_accID), money(_money)
{
	cusName = new char[strlen(_cusName) + 1];
	strcpy(cusName, _cusName);
}

Account::Account(const Account& ref)
	: accID(ref.accID), money(ref.money)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

Account& Account::operator=(const Account& ref)		// 추가된 정의
{
	accID = ref.accID;
	money = ref.money;

	delete[]cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
	return *this;
}

int Account::GetAccID() const
{
	return accID;
}

void Account::Deposit(int _money)
{
	money += _money;
}

int Account::Withdraw(int _money)
{
	if (money < _money)
	{
		return 0;
	}

	money -= _money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << accID << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액 :" << money << endl;
}

Account::~Account()
{
	delete[]cusName;
}
