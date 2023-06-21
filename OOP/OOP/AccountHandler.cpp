//AccountHandler�� ����
#include "BankingCommonDec1.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler()
	:customersCount(0)
{}

void AccountHandler::ShowMenu() const
{
	cout << "-----MENU-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::AccountCreate()
{
	char inname[100];
	int incredit;
	int inmoney;
	int interest;
	int type;
	int rate = 0;
	cout << "[���°��� ���� ����]" << endl;
	cout << "1. ���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cin >> type;
	if (type == 1)
	{
		cout << "[���뿹�ݰ��� ����]" << endl;
		cout << "���� ID : ";
		cin >> incredit;
		cout << "�̸� : ";
		cin >> inname;
		cout << "�Աݾ� : ";
		cin >> inmoney;
		cout << "������ : ";
		cin >> interest;
		customers[customersCount++] = new NormalAccount(incredit, inname, inmoney, interest);

	}
	else if (type == 2)
	{
		cout << "[�ſ�ŷڰ��� ����]" << endl;
		cout << "���� ID : ";
		cin >> incredit;
		cout << "�̸� : ";
		cin >> inname;
		cout << "�Աݾ� : ";
		cin >> inmoney;
		cout << "������ : ";
		cin >> interest;
		cout << "�ſ��� : ";
		cin >> rate;
		customers[customersCount++] = new HighCreditAccount(incredit, inname, inmoney, interest);
		customers[customersCount - 1]->AddRate(rate);
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

	cout << "[�� ��]" << endl;
	cout << "���� ID : ";
	cin >> id;
	cout << "�Աݾ� : ";
	cin >> depositMoney;

	for (int i = 0; i < customersCount; i++)
	{
		if (customers[i]->GetCreditNum() == id)
		{
			customers[i]->Deposit(depositMoney);
			return;
		}
	}
	cout << "wrong id" << endl;
	cout << endl;
}

void AccountHandler::AccountWithdraw()
{
	int id;
	int withdrawMoney;

	cout << "[�� ��]" << endl;
	cout << "���� ID : ";
	cin >> id;
	cout << "��ݾ� : ";
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
	cout << "wrong id" << endl;
	cout << endl;
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