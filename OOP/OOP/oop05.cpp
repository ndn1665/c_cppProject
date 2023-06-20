#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;


class Account
{
private:
	int creditNum;
	char* name;
	int money;
public:
	Account(int incdnum, char* inname, int inmoney)
		:creditNum(incdnum), money(inmoney)
	{
		name = new char[strlen(inname) + 1];
		strcpy(name, inname);
	}
	Account(const Account& copy)
		:creditNum(copy.creditNum), money(copy.money)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	void Deposit(int depositMoney);
	int Withdraw(int withdrawMoney);
	int GetCreditNum() const;
	int GetMoney() const;
	void showAll() const;

	~Account()
	{
		delete[]name;
	}

};

class NormalAccount :public Account
{
private:

public:

};

class AccountHandler
{
private:
	Account* customers[100];
	int customersCount;
public:
	AccountHandler()
		:customersCount(0)
	{}

	void ShowMenu() const;
	void AccountCreate();
	void AccountDeposit();
	void AccountWithdraw();
	void ShowAll() const;

	~AccountHandler() 
	{
		for (int i = 0; i < customersCount; i++)
		{
			delete customers[i];
		}
	}
};


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


int Account::GetCreditNum() const
{
	return creditNum;
}
int Account::GetMoney() const
{
	return money;
}
void Account::Deposit(int depositMoney)
{
	money += depositMoney;
}

int Account::Withdraw(int withdrawMoney)
{
	if (money - withdrawMoney < 0)
	{
		return 0;
	}
		
	money -= withdrawMoney;
	
}

void Account::showAll() const
{
	cout << creditNum << endl;
	cout << name << endl;
	cout << money << endl;
}

//AccountHandler ����Լ�

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
	cout << "[���°���]" << endl;
	cout << "���� ID : ";
	cin >> incredit;
	cout << "�̸� : ";
	cin >> inname;
	cout << "�Աݾ� : ";
	cin >> inmoney;

	customers[customersCount++] = new Account(incredit, inname, inmoney);//Customer ��ü ����
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