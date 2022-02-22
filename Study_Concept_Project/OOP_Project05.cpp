// AccountHandler ��� �̸��� ��Ʈ�� Ŭ���� ����
// Ŭ���� �������� ����Լ��� ���� �ΰ�, ���Ǵ� Ŭ���� �ܺη� �� ���� �������� ����.

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int Name_Lens = 20;             // �Է��� �̸��� �ִ� ���� 

enum
{
	Make = 1, DEPOSIT, WITHDRAW, INFORM, EXIT
};

class Account
{
private:
	int accID;		// ���¹�ȣ
	int money;		// �ܾ�
	char* cusName;	// �� �̸�
public:
	Account(int _accID, int _money, char* _cusName);
	Account(const Account& ref);

	int GetAccID() const;
	void Deposit(int _money);
	int Withdraw(int _money);
	void ShowAccInfo() const;
	~Account();
};

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

int Account::GetAccID() const
{
	return accID;
}

void Account::Deposit(int _money)
{
	money += money;
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
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� �� :" << money << endl;
}

Account::~Account()
{
	delete[]cusName;
}

class AccountHandler	// ��Ʈ�� Ŭ����
{
private:
	Account* accArr[100];	// ��ü ������ �迭
	int accNum;				// ����� account�� ��
public:
	AccountHandler();
	void Menu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAccount(void) const;
	~AccountHandler();
};

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
	int ID;
	char cusName[Name_Lens];
	int money;
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> ID;
	cout << "�� ��: ";
	cin >> cusName;
	cout << "�Աݾ�: ";
	cin >> money;
	cout << '\n';

	accArr[accNum] = new Account(ID, money, cusName);
	accNum++;
}

void AccountHandler::DepositMoney(void)
{
	int ID;
	int plusMoney = 0;

	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> ID;
	cout << "�Աݾ�: ";
	cin >> plusMoney;

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
}

void AccountHandler::WithdrawMoney(void)
{
	int myID = 0;
	int minusMoney = 0;

	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> myID;
	cout << "��ݾ�: ";
	cin >> minusMoney;

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
}

AccountHandler::AccountHandler() : accNum(0)
{ }

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

int main(void)
{
	AccountHandler manager;
	int choice = 0;

	while (1)
	{
		manager.Menu();
		cout << "����: ";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case Make:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INFORM:
			manager.ShowAccount();
			break;
		case EXIT:
			return 0;                   // ���α׷� ����
		default:
			cout << "�ٽ� �Է����ּ���." << endl;
		}
	}
	return 0;
}