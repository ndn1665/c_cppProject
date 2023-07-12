#include "BankingCommonDecl.h"

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

#include "AccountHandler.h"

AccountHandler::AccountHandler() : customersCount(0) {}

void AccountHandler::ShowMenu() const
{
	cout << "-----MENU-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::AccountCreate()
{
	char inname[100];
	int incredit;
	int inmoney;
	int interest;
	int type;
	int special = 0;
	cout << "[계좌개설 종류 선택]" << endl;
	cout << "1. 보통예금계좌 2.신용신뢰계좌" << endl;
	cin >> type;
	if (type == 1)
	{
		cout << "[보통예금계좌 개설]" << endl;
		cout << "계좌 ID : ";
		cin >> incredit;
		cout << "이름 : ";
		cin >> inname;
		cout << "입금액 : ";
		cin >> inmoney;
		cout << "이자율 : ";
		cin >> interest;
		customers[customersCount++] = new NormalAccount(incredit, inname, inmoney, interest);

	}
	else if (type == 2)
	{
		cout << "[신용신뢰계좌 개설]" << endl;
		cout << "계좌 ID : ";
		cin >> incredit;
		cout << "이름 : ";
		cin >> inname;
		cout << "입금액 : ";
		cin >> inmoney;
		cout << "이자율 : ";
		cin >> interest;
		cout << "신용등급 : ";
		cin >> special;
		customers[customersCount++] = new HighCreditAccount(incredit, inname, inmoney, interest,special);
	}
	else
	{
		cout << "wrong type" << endl;
		return;
	}

	cout << endl;
}

void AccountHandler::AccountDeposit()
{
	int id;
	int depositMoney;

	cout << "[입 금]" << endl;
	cout << "계좌 ID : ";
	cin >> id;
	cout << "입금액 : ";
	cin >> depositMoney;

	for (int i = 0; i < customersCount; i++)
	{
		if (customers[i]->GetCreditNum() == id)
		{
			customers[i]->Deposit(depositMoney);
			cout << "입금완료" << endl<<endl;
			return;
		}
	}
	cout << "wrong id" << endl<<endl;
}

void AccountHandler::AccountWithdraw()
{
	int id;
	int withdrawMoney;

	cout << "[출 금]" << endl;
	cout << "계좌 ID : ";
	cin >> id;
	cout << "출금액 : ";
	cin >> withdrawMoney;

	for (int i = 0; i < customersCount; i++)
	{
		if (customers[i]->GetCreditNum() == id)
		{
			if (customers[i]->Withdraw(withdrawMoney) == 0)
			{
				cout << "over withdrawed." << endl;
			}
			return;

		}
	}
	cout << "wrong id" << endl << endl;
}

void AccountHandler::ShowAll() const
{
	for (int i = 0; i < customersCount; i++)
	{
		customers[i]->showAll();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() 
{
	for (int i = 0; i < customersCount; i++)
	{
		delete customers[i];
	}
}