#pragma once
#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler	// 컨트롤 클래스
{
private:
	BoundCheckArray<Account*> accArr;	// 변경된 문장
	int accNum;				// 저장된 account의 수
public:
	AccountHandler();
	void Menu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAccount(void) const;
	~AccountHandler();
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};