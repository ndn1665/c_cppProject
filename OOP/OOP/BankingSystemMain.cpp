#include "BankingCommonDecl.h"
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
		case MAKE:
			accountHandler.AccountCreate();
			break;
		case DEPOSIT:
			accountHandler.AccountDeposit();
			break;
		case WITHDRAW:
			accountHandler.AccountWithdraw();
			break;
		case INQUIRE:
			accountHandler.ShowAll();
			break;
		case EXIT:
			return 0;
		default:
			cout << "illegal access" << endl;
		}

	}

	return 0;
}