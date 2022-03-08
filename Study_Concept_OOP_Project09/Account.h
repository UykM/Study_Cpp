
#pragma once
#include "String.h"

class Account
{
private:
	int accID;		// ���¹�ȣ
	int money;		// �ܾ�
	String cusName;	// �� �̸�	// char* cusName;	
									// String Ŭ������ �����ߴٰ� �ؼ� char�� ������ ����� ���ڿ� ǥ���� ������ ������ �ʿ� X
public:
	Account(int ID, int money, String name);
	// Account(int _accID, int _money, char* _cusName);
	// Account(const Account& ref);					// ���� ������
	// Account& operator=(const Account& ref);		// ���� ������ �����ε�

	int GetAccID() const;
	virtual void Deposit(int _money);		// ���� Ŭ������ NormalAccount, CreditClass ���� ȣ���ϱ� ������, �����Լ� ���� �ʿ�
	int Withdraw(int _money);
	void ShowAccInfo() const;
	// ~Account();
};