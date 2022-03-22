#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "CreditAccount.h"
#include "String.h"

void AccountHandler::Menu(void) const
{
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ���� " << endl;
}


void AccountHandler::MakeAccount(void)
{
	int sel;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
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

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> ID;
	cout << "�� ��: "; cin >> cusName;
	cout << "�Աݾ�: "; cin >> money;
	cout << "������: "; cin >> interRate;
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

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> ID;
	cout << "�� ��: "; cin >> cusName;
	cout << "�Աݾ�: "; cin >> money;
	cout << "������: "; cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> creditLevel;
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

	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> ID;
	
	while (true)
	{
		cout << "�Աݾ�: ";
		cin >> plusMoney;
		
		try
		{
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->GetAccID() == ID)
				{
					accArr[i]->Deposit(plusMoney);
					cout << "�Ա� �Ϸ�" << '\n' << endl;
					return;
				}
			}
			cout << "�������� �ʴ� �����Դϴ�." << '\n' << endl;
			return;
		}
		catch (MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "�Աݾ׸� ���Է��ϼ���." << endl;
		}
	}
}

void AccountHandler::WithdrawMoney(void)
{
	int myID = 0;
	int minusMoney = 0;

	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> myID;
	

	while (true)
	{
		cout << "��ݾ�: ";
		cin >> minusMoney;

		try
		{
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->GetAccID() == myID)
				{
					if (accArr[i]->Withdraw(minusMoney) == 0)
					{
						cout << "�ܾ� ����" << '\n' << endl;
						return;
					}
					cout << "��� �Ϸ�" << '\n' << endl;
				}
			}
			cout << "�������� �ʴ� �����Դϴ�." << '\n' << endl;
			return;
		}
		catch (MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "��ݾ׸� ���Է��ϼ���." << endl;
		}
	}
	
	
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
		cout << "����� ���� ������ �����ϴ�." << "\n" << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];		// ���� �Ҵ��� �޸� ����
	}
}