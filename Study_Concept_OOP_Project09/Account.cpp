#include "BankingCommonDecl.h"
#include "Account.h"
#include "AccountException.h"

Account::Account(int _accID, int _money, String _cusName)
	: accID(_accID), money(_money)
{
	// cusName = new char[strlen(_cusName) + 1];
	// strcpy(cusName, _cusName);
	cusName = _cusName;
}

/*
Account::Account(const Account& ref)
	: accID(ref.accID), money(ref.money)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

Account& Account::operator=(const Account& ref)
{
	accID = ref.accID;
	money = ref.money;

	delete[]cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
	return *this;
}
*/

int Account::GetAccID() const
{
	return accID;
}

void Account::Deposit(int _money)
{
	if (_money < 0)
		throw MinusException(_money);

	money += _money;
}

int Account::Withdraw(int _money)
{
	if (_money < 0)
		throw MinusException(_money);

	if (money < _money)
		throw InsuffException(money, _money);

	money -= _money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "°èÁÂID: " << accID << endl;
	cout << "ÀÌ ¸§: " << cusName << endl;
	cout << "ÀÜ ¾× :" << money << endl;
}

/*
Account::~Account()
{
	delete[]cusName;
}
*/
