// �߰��� ����(Supplementary Contents)
// NormalAccount Ŭ������ HighCreditAccount Ŭ���� �߰��� ����

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int Name_Lens = 20;             // �Է��� �̸��� �ִ� ���� 

// ���α׷� ������� ���� �޴�
enum {Make = 1, DEPOSIT, WITHDRAW, INFORM, EXIT};

// �ſ���
enum {LEVEL_A = 7, LEVEL_B  = 4, LEVEL_C = 2};

// ������ ����
enum {NORMAL = 1, CREDIT = 2};

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
	virtual void Deposit(int _money);		// ���� Ŭ������ NormalAccount, CreditClass ���� ȣ���ϱ� ������, �����Լ� ���� �ʿ�
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
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� �� :" << money << endl;
}

Account::~Account()
{
	delete[]cusName;
}

// �Ա� �ÿ� ���ڰ� ���ݿ� �������� ������ �����Ͽ� �ڵ� �ۼ���.

// ���뿹�ݰ���
class NormalAccount : public Account
{
private:
	int interRate;	// ������ %����
public:
	NormalAccount(int ID, int money, const char* cusName, int rate)
		: Account(ID, money, cusName), interRate(rate)
	{ }

	virtual void Deposit(int money)
	{
		Account::Deposit(money);	// �����߰�
		Account::Deposit(money * (interRate / 100.0));		// �����߰�
	}
};

// �ſ�ŷڰ���
class CreditAccount : public Account
{
private:
	int specialRate;
public:
	CreditAccount(int ID, int money, const char* cusName, int rate, int special)
		: NormalAccount(ID, money, cusName, rate), specialRate(special)
	{ }

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);		// ���ݰ� �����߰�
		Account::Deposit(money * (specialRate / 100.0));		// Ư�������߰�
	}
};

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
	int sel;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> sel;
	
	if (sel == NORMAL) MakeNormalAccount();
	else MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount();
{
	int ID;
	char name[Name_Lens];
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

void AccountHandler::MakeCreditAccount();
{
	int ID;
	char name[Name_Lens];
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
		accArr[accNum++] = new CreditAccount(ID, cusName, money, interRate, LEVEL_A);
	case 2:
		accArr[accNum++] = new CreditAccount(ID, cusName, money, interRate, LEVEL_B);
	case 3:
		accArr[accNum++] = new CreditAccount(ID, cusName, money, interRate, LEVEL_C);
	}
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