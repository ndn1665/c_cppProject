#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;


class Customer
{
private:
	int creditNum;
	char* name;
	int money;
public:
	Customer(int incdnum, char* inname, int inmoney)
		:creditNum(incdnum), money(inmoney)
	{
		name = new char[strlen(inname) + 1];
		strcpy(name, inname);
	}
	Customer(const Customer& copy)
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


	~Customer()
	{
		delete[]name;
	}

};


class AccountHandler
{
private:
	Customer* customers[100];
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


int Customer::GetCreditNum() const
{
	return creditNum;
}
int Customer::GetMoney() const
{
	return money;
}
void Customer::Deposit(int depositMoney)
{
	money += depositMoney;
}

int Customer::Withdraw(int withdrawMoney)
{
	if (money - withdrawMoney < 0)
	{
		return 0;
	}
		
	money -= withdrawMoney;
	
}

void Customer::showAll() const
{
	cout << creditNum << endl;
	cout << name << endl;
	cout << money << endl;
}

//AccountHander 멤버함수

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
	cout << "[계좌개설]" << endl;
	cout << "계좌 ID : ";
	cin >> incredit;
	cout << "이름 : ";
	cin >> inname;
	cout << "입금액 : ";
	cin >> inmoney;

	customers[customersCount++] = new Customer(incredit, inname, inmoney);//Customer 객체 생성
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