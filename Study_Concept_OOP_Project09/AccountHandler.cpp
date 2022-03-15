#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "CreditAccount.h"
#include "String.h"

void AccountHandler::Menu(void) const
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료 " << endl;
}


void AccountHandler::MakeAccount(void)
{
	int sel;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> sel;

	if (sel == NORMAL) MakeNormalAccount();
	else MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount()
{
	int ID;
	String cusName;
	// char cusName[Name_Lens];		
	int money;
	int interRate;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> ID;
	cout << "이 름: "; cin >> cusName;
	cout << "입금액: "; cin >> money;
	cout << "이자율: "; cin >> interRate;
	cout << '\n';

	accArr[accNum++] = new NormalAccount(ID, money, cusName, interRate);
}

void AccountHandler::MakeCreditAccount()
{
	int ID;
	String cusName;
	// char cusName[Name_Lens];
	int money;
	int interRate;
	int creditLevel;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> ID;
	cout << "이 름: "; cin >> cusName;
	cout << "입금액: "; cin >> money;
	cout << "이자율: "; cin >> interRate;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditLevel;
	cout << '\n';

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new CreditAccount(ID, money, cusName, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new CreditAccount(ID, money, cusName, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new CreditAccount(ID, money, cusName, interRate, LEVEL_C);
		break;
	}
}

void AccountHandler::DepositMoney(void)
{
	int ID;
	int plusMoney = 0;

	cout << "[입   금]" << endl;
	cout << "계좌ID: ";
	cin >> ID;
	cout << "입금액: ";
	cin >> plusMoney;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == ID)
		{
			accArr[i]->Deposit(plusMoney);
			cout << "입금 완료" << '\n' << endl;
			return;
		}
	}
	cout << "존재하지 않는 계좌입니다." << '\n' << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int myID = 0;
	int minusMoney = 0;

	cout << "[출   금]" << endl;
	cout << "계좌ID: ";
	cin >> myID;
	cout << "출금액: ";
	cin >> minusMoney;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == myID)
		{
			if (accArr[i]->Withdraw(minusMoney) == 0)
			{
				cout << "잔액 부족" << '\n' << endl;
				return;
			}
			cout << "출금 완료" << '\n' << endl;
		}
	}
	cout << "존재하지 않는 계좌입니다." << '\n' << endl;
}

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowAccount(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}

	if (accNum == 0)
	{
		cout << "저장된 계좌 정보가 없습니다." << "\n" << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];		// 동적 할당한 메모리 삭제
	}
}