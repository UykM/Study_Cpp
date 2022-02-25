#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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