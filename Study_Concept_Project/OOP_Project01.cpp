#include <iostream>
#include <cstring>
using namespace std;

void Menu();
void OpenAccount();
void Deposit();
void Withdraw();
void ShowAccount();

const int Name_Lens = 20;             // �Է��� �̸��� �ִ� ���� 

enum             // enum �������̸� { ��1, ��2, .. };  ->  �������� ������ / �������̸� �������� !
{
	Make = 1,
	moneyIn,
	moneyOut,
	inform,
	finish
};

int main()
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
			OpenAccount();
			break;
		case moneyIn:
			Deposit();
			break;
		case moneyOut:
			Withdraw();
			break;
		case inform:
			ShowAccount();
			break;
		case finish:
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

typedef struct _Account
{
	int ID;
	char NAME[Name_Lens];
	int MONEY;
} Account;

Account allAccount[100];				// ���� �����
int AccTime = 0;                        // ���� �� ����

void OpenAccount(void)
{
	int id;
	char name[Name_Lens];
	int money;
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> money;
	cout << '\n';

	allAccount[AccTime].ID = id;
	strcpy_s(allAccount[AccTime].NAME, name);       //  strcpy(���ڿ�1, ���ڿ�2) : ���ڿ�2 �� ���ڿ�1�� ���� / ������ strcpy_s 
	allAccount[AccTime].MONEY = money;
	AccTime++;
}

void Deposit(void)
{
	int yourID;
	int plusCharge = 0;
	int n = 0;

	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> yourID;
	cout << "�Աݾ�: ";
	cin >> plusCharge;

	for (int i = 0; i < AccTime; i++)
	{
		if (allAccount[n].ID == yourID)
		{
			allAccount[n].MONEY += plusCharge;
			cout << "�Ա� �Ϸ�" << '\n' << endl;
		}
		else
		{
			cout << "�������� �ʴ� �����Դϴ�." << '\n' << endl;
			break;
		}
	}
}

void Withdraw(void)
{
	int myID = 0;
	int minusCharge = 0;
	int n = 0;

	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> myID;
	cout << "�Աݾ�: ";
	cin >> minusCharge;

	while (1)
	{
		if (allAccount[n].ID == myID)
		{
			allAccount[n].MONEY -= minusCharge;
			if (allAccount[n].MONEY > 0)
			{
				cout << "��� �Ϸ�" << '\n' << endl;
			}
			else
			{

				cout << "�ܾ��� �����մϴ�." << '\n' << endl;
			}
			break;
		}
		else if (n == AccTime)
		{
			cout << "�������� �ʴ� �����Դϴ�." << '\n' << endl;
			break;
		}
		else
		{
			n++;
		}
	}

}

void ShowAccount(void)
{
	for (int i = 0; i < AccTime; i++)
	{
		cout << "����ID: " << allAccount[i].ID << endl;
		cout << "�� ��: " << allAccount[i].NAME << endl;
		cout << "�� �� :" << allAccount[i].MONEY << endl;
		cout << '\n';
	}
}
