// 추가된 내용(Supplementary Contents)
// NormalAccount 클래스와 HighCreditAccount 클래스 추가로 정의

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int Name_Lens = 20;             // 입력할 이름의 최대 길이 

// 프로그램 사용자의 선택 메뉴
enum {Make = 1, DEPOSIT, WITHDRAW, INFORM, EXIT};

// 신용등급
enum {LEVEL_A = 7, LEVEL_B  = 4, LEVEL_C = 2};

// 계좌의 종류
enum {NORMAL = 1, CREDIT = 2};

class Account
{
private:
	int accID;		// 계좌번호
	int money;		// 잔액
	char* cusName;	// 고객 이름
public:
	Account(int _accID, int _money, char* _cusName);
	Account(const Account& ref);

	int GetAccID() const;
	virtual void Deposit(int _money);		// 유도 클래스인 NormalAccount, CreditClass 에서 호출하기 때문에, 가상함수 선언 필요
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
	cout << "계좌ID: " << accID << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액 :" << money << endl;
}

Account::~Account()
{
	delete[]cusName;
}

// 입금 시에 이자가 원금에 더해지는 것으로 간주하여 코드 작성함.

// 보통예금계좌
class NormalAccount : public Account
{
private:
	int interRate;	// 이자율 %단위
public:
	NormalAccount(int ID, int money, const char* cusName, int rate)
		: Account(ID, money, cusName), interRate(rate)
	{ }

	virtual void Deposit(int money)
	{
		Account::Deposit(money);	// 원금추가
		Account::Deposit(money * (interRate / 100.0));		// 이자추가
	}
};

// 신용신뢰계좌
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
		NormalAccount::Deposit(money);		// 원금과 이자추가
		Account::Deposit(money * (specialRate / 100.0));		// 특별이자추가
	}
};

class AccountHandler	// 컨트롤 클래스
{
private:
	Account* accArr[100];	// 객체 포인터 배열
	int accNum;				// 저장된 account의 수
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

void AccountHandler::MakeNormalAccount();
{
	int ID;
	char name[Name_Lens];
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

void AccountHandler::MakeCreditAccount();
{
	int ID;
	char name[Name_Lens];
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

int main(void)
{
	AccountHandler manager;
	int choice = 0;

	while (1)
	{
		manager.Menu();
		cout << "선택: ";
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
			return 0;                   // 프로그램 종료
		default:
			cout << "다시 입력해주세요." << endl;
		}
	}
	return 0;
}