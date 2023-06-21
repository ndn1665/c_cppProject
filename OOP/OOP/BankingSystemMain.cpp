//main함수의 정의
#include "BankingCommonDec1.h"
#include "AccountHandler.h"
int main()
{
	int choice;
	AccountHandler accountHandler;
	while (true)
	{
		accountHandler.ShowMenu();
		cout << "choice : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			accountHandler.AccountCreate();
			break;
		case 2:
			accountHandler.AccountDeposit();
			break;
		case 3:
			accountHandler.AccountWithdraw();
			break;
		case 4:
			accountHandler.ShowAll();
			break;
		case 5:
			return 0;
		default:
			cout << "illegal access" << endl;
		}

	}

	return 0;
}