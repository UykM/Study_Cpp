// 추가된 내용(Supplementary Contents) - Account 클래스 정의(캡슐화), 객체 포인터 배열 적용 , (+ this 포인터 활용)
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

const int Name_Lens = 20;             // 입력할 이름의 최대 길이 

enum 
{
	Make = 1, DEPOSIT, WITHDRAW, INFORM, EXIT
};

class Account
{
private:
	int accID;		// 계좌번호
	int money;		// 잔액
	char* cusName;	// 고객 이름
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

	/* this 활용

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
		cout << "계좌ID: " << accID << endl;
		cout << "이 름: " << cusName << endl;
		cout << "잔 액 :" << money << endl;
	}
	~Account()
	{
		delete[]cusName;
	}
};

Account* accArr[100];	// 객체 포인터 배열
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
	int ID;
	char cusName[Name_Lens];
	int money;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> ID;
	cout << "이 름: ";
	cin >> cusName;
	cout << "입금액: ";
	cin >> money;
	cout << '\n';

	accArr[accNum] = new Account(ID, money, cusName);
	accNum++;
}

void DepositMoney(void)
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
	/* this 활용
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == ID)
		{
			accArr[i]->SetMoney(accArr[i]->GetMoney() + plusMoney);
			cout << "입금 완료" << '\n' << endl;
			return;
		}
	}
	*/
	cout << "존재하지 않는 계좌입니다." << '\n' << endl;
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
	/* this 활용
	for(int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == myID)
		{
			if (accArr[i]->GetMoney() < minusMoney)
			{
				cout << "잔액 부족" << '\n' << endl;
				return;
			}
			accArr[i]->SetMoney(accArr[i]->GetMoney() - minusMoney);
			cout << "출금 완료" << '\n' << endl;
		}
	}
	*/
	cout << "존재하지 않는 계좌입니다." << '\n' << endl;
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
		cout << "저장된 계좌 정보가 없습니다." << "\n" << endl;
	}
}
