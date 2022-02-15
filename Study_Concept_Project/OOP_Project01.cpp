#include <iostream>
#include <cstring>
using namespace std;

void Menu();
void OpenAccount();
void Deposit();
void Withdraw();
void ShowAccount();

const int Name_Lens = 20;             // 입력할 이름의 최대 길이 

enum             // enum 열거형이름 { 값1, 값2, .. };  ->  가독성을 높혀줌 / 열거형이름 생략가능 !
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
		cout << "선택: ";
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

typedef struct _Account
{
	int ID;
	char NAME[Name_Lens];
	int MONEY;
} Account;

Account allAccount[100];				// 계좌 저장소
int AccTime = 0;                        // 계좌 총 개수

void OpenAccount(void)
{
	int id;
	char name[Name_Lens];
	int money;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> money;
	cout << '\n';

	allAccount[AccTime].ID = id;
	strcpy_s(allAccount[AccTime].NAME, name);       //  strcpy(문자열1, 문자열2) : 문자열2 를 문자열1로 복사 / 오류시 strcpy_s 
	allAccount[AccTime].MONEY = money;
	AccTime++;
}

void Deposit(void)
{
	int yourID;
	int plusCharge = 0;
	int n = 0;

	cout << "[입   금]" << endl;
	cout << "계좌ID: ";
	cin >> yourID;
	cout << "입금액: ";
	cin >> plusCharge;

	for (int i = 0; i < AccTime; i++)
	{
		if (allAccount[n].ID == yourID)
		{
			allAccount[n].MONEY += plusCharge;
			cout << "입금 완료" << '\n' << endl;
		}
		else
		{
			cout << "존재하지 않는 계좌입니다." << '\n' << endl;
			break;
		}
	}
}

void Withdraw(void)
{
	int myID = 0;
	int minusCharge = 0;
	int n = 0;

	cout << "[출   금]" << endl;
	cout << "계좌ID: ";
	cin >> myID;
	cout << "입금액: ";
	cin >> minusCharge;

	while (1)
	{
		if (allAccount[n].ID == myID)
		{
			allAccount[n].MONEY -= minusCharge;
			if (allAccount[n].MONEY > 0)
			{
				cout << "출금 완료" << '\n' << endl;
			}
			else
			{

				cout << "잔액이 부족합니다." << '\n' << endl;
			}
			break;
		}
		else if (n == AccTime)
		{
			cout << "존재하지 않는 계좌입니다." << '\n' << endl;
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
		cout << "계좌ID: " << allAccount[i].ID << endl;
		cout << "이 름: " << allAccount[i].NAME << endl;
		cout << "잔 액 :" << allAccount[i].MONEY << endl;
		cout << '\n';
	}
}
