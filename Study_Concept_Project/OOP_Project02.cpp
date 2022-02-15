#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

void Menu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAccount();

const int Name_Lens = 20;             // �Է��� �̸��� �ִ� ���� 

enum             // enum �������̸� { ��1, ��2, .. };  ->  �������� ������ / �������̸� �������� !
{
	Make = 1,
	DEPOSIT,
	WITHDRAW,
	INFORM,
	EXIT
};

class Account
{
private:
	int accID;		// ���¹�ȣ
	int money;		// �ܾ�
	char* cusName;	// �� �̸�
public:
	Account(int _accID, int _money, const char* _cusName)
		: accID(_accID), money(_money)
	{
		cusName = new char[strlen(_cusName) + 1];
		strcpy(cusName, _cusName);
	}

	int GetAccID()
	{
		return accID;
	}

	void Deposit(int _money)
	{
		money += _money;
	}

	int Withdraw(int _money)		// ��ݾ� ��ȯ, �ܾ� ���� �� 0 ��ȯ
	{
		if (money < _money)
		{
			return 0;

		}
		money -= _money;
	}

	void ShowAccInfo()
	{
		cout << "����ID: " << accID << endl;
		cout << "�� ��: " << cusName << endl;
		cout << "�� �� :" << money << endl;
	}
	~Account()
	{
		delete[]cusName;
	}
};

Account* accArr[100];
int accNum = 0;		// ����� account�� ��

int main(void)
{
	int choice = 0;

	while (1)
	{
		Menu();
		cout << "����: ";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case Make:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INFORM:
			ShowAccount();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
			{
				delete accArr[i];		// ���� �Ҵ��� �޸� ����
			}
			return 0;                   // ���α׷� ����
		default:
			cout << "�ٽ� �Է����ּ���." << endl;
		}
	}
	return 0;
}

void Menu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ���� " << endl;
}


void MakeAccount(void)
{
	int _accID;
	char _cusName[Name_Lens];
	int _money;
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> _accID;
	cout << "�� ��: ";
	cin >> _cusName;
	cout << "�Աݾ�: ";
	cin >> _money;
	cout << '\n';

	accArr[accNum++] = new Account(_accID, _money, _cusName);
}

void DepositMoney(void)
{
	int yourID;
	int plusMoney = 0;
	int n = 0;

	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> yourID;
	cout << "�Աݾ�: ";
	cin >> plusMoney;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == yourID)
		{
			accArr[i]->Deposit(plusMoney);
			cout << "�Ա� �Ϸ�" << '\n' << endl;
			return;
		}
		cout << "�������� �ʴ� �����Դϴ�." << '\n' << endl;
	}
}

void WithdrawMoney(void)
{
	int myID = 0;
	int minusMoney = 0;

	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> myID;
	cout << "�Աݾ�: ";
	cin >> minusMoney;

	for(int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == myID)
		{
			if (accArr[i]->Withdraw(minusMoney) == 0)
			{
				cout << "�ܾ� ����" << '\n' << endl;
			}
				cout << "��� �Ϸ�" << '\n' << endl;
		}
		cout << "�������� �ʴ� �����Դϴ�." << '\n' << endl;
		}
}

void ShowAccount(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}
