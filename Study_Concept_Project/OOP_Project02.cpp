// �߰��� ����(Supplementary Contents) - Account Ŭ���� ����(ĸ��ȭ), ��ü ������ �迭 ���� , (+ this ������ Ȱ��)
// 

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
	Account(int _accID, int _money, char* _cusName)
		: accID(_accID), money(_money)
	{
		cusName = new char[strlen(_cusName) + 1];
		strcpy(cusName, _cusName);
	}

	int GetAccID(void)
	{
		return accID;
	}

	void Deposit(int _money)
	{
		money += money;
	}

	int Withdraw(int _money)
	{
		if (money < _money)
		{
			return 0;
		}

		money -= _money;
		return money;
	}

	/* this Ȱ��

	int GetMoney(void)
	{
		return money;
	}

	void SetAccID(int accID)
	{
		this->accID = accID;
	}

	void SetMoney(int money)
	{
		this->money = money;
	}
	*/

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

Account* accArr[100];	// ��ü ������ �迭
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

void DepositMoney(void)
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
	/* this Ȱ��
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == ID)
		{
			accArr[i]->SetMoney(accArr[i]->GetMoney() + plusMoney);
			cout << "�Ա� �Ϸ�" << '\n' << endl;
			return;
		}
	}
	*/
	cout << "�������� �ʴ� �����Դϴ�." << '\n' << endl;
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
	/* this Ȱ��
	for(int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == myID)
		{
			if (accArr[i]->GetMoney() < minusMoney)
			{
				cout << "�ܾ� ����" << '\n' << endl;
				return;
			}
			accArr[i]->SetMoney(accArr[i]->GetMoney() - minusMoney);
			cout << "��� �Ϸ�" << '\n' << endl;
		}
	}
	*/
	cout << "�������� �ʴ� �����Դϴ�." << '\n' << endl;
}

void ShowAccount(void)
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
