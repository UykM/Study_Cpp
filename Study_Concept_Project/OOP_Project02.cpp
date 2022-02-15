#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

void Menu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAccount();

const int Name_Lens = 20;             // 입력할 이름의 최대 길이 

enum             // enum 열거형이름 { 값1, 값2, .. };  ->  가독성을 높혀줌 / 열거형이름 생략가능 !
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
	int accID;		// 계좌번호
	int money;		// 잔액
	char* cusName;	// 고객 이름
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

	int Withdraw(int _money)		// 출금액 반환, 잔액 부족 시 0 반환
	{
		if (money < _money)
		{
			return 0;

		}
		money -= _money;
	}

	void ShowAccInfo()
	{
		cout << "계좌ID: " << accID << endl;
		cout << "이 름: " << cusName << endl;
		cout << "잔 액 :" << money << endl;
	}
	~Account()
	{
		delete[]cusName;
	}
};

Account* accArr[100];
int accNum = 0;		// 저장된 account의 수

int main(void)
{
	int choice = 0;

	while (1)
	{
		Menu();
		cout << "선택: ";
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
				delete accArr[i];		// 동적 할당한 메모리 삭제
			}
			return 0;                   // 프로그램 종료
		default:
			cout << "다시 입력해주세요." << endl;
		}
	}
	return 0;
}

void Menu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료 " << endl;
}


void MakeAccount(void)
{
	int _accID;
	char _cusName[Name_Lens];
	int _money;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> _accID;
	cout << "이 름: ";
	cin >> _cusName;
	cout << "입금액: ";
	cin >> _money;
	cout << '\n';

	accArr[accNum++] = new Account(_accID, _money, _cusName);
}

void DepositMoney(void)
{
	int yourID;
	int plusMoney = 0;
	int n = 0;

	cout << "[입   금]" << endl;
	cout << "계좌ID: ";
	cin >> yourID;
	cout << "입금액: ";
	cin >> plusMoney;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == yourID)
		{
			accArr[i]->Deposit(plusMoney);
			cout << "입금 완료" << '\n' << endl;
			return;
		}
		cout << "존재하지 않는 계좌입니다." << '\n' << endl;
	}
}

void WithdrawMoney(void)
{
	int myID = 0;
	int minusMoney = 0;

	cout << "[출   금]" << endl;
	cout << "계좌ID: ";
	cin >> myID;
	cout << "입금액: ";
	cin >> minusMoney;

	for(int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == myID)
		{
			if (accArr[i]->Withdraw(minusMoney) == 0)
			{
				cout << "잔액 부족" << '\n' << endl;
			}
				cout << "출금 완료" << '\n' << endl;
		}
		cout << "존재하지 않는 계좌입니다." << '\n' << endl;
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
