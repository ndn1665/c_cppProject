#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

//-------------Account class--------------------------------//
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
	virtual void AddRate(int inrate) {};
	virtual void Deposit(int depositMoney);
	int Withdraw(int withdrawMoney);
	int GetCreditNum() const;
	int GetMoney() const;
	void showAll() const;

	~Account()
	{
		delete[]name;
	}

};
//-------------------Normal class---------------------------//
class NormalAccount :public Account
{
private:
	int interest;
public:
	NormalAccount(int incdnum, char* inname, int inmoney,int ininter)
		:Account(incdnum,inname,inmoney),interest(ininter)
	{}
	virtual void Deposit(int depositMoney)
	{
		Account::Deposit(depositMoney + (int)(depositMoney * ((double)interest/100)));
	}
	int GetInter()
	{
		return interest;
	}

};
//-------------HighCredit class--------------------------------//
class HighCreditAccount :public NormalAccount
{
private:
	int rate;
public:
	HighCreditAccount(int incdnum, char* inname, int inmoney, int ininter)
		:NormalAccount(incdnum, inname, inmoney,ininter), rate(0)
	{}
	virtual void AddRate(int inrate)
	{
		if (rate > 3)
		{
			rate = 0;
			cout << "wrong rate" << endl;
			return;
		}
		else rate = inrate;
	}
	virtual void Deposit(int depositMoney)
	{
		int calRate;
		if (rate == 1)
		{
			calRate = 7;
		}
		else if (rate == 2)
		{
			calRate = 4;
		}
		else
		{
			calRate = 2;
		}

		Account::Deposit(depositMoney + (int)(depositMoney * ((double)(GetInter()+calRate)/100)));
	}
};
//-------------Accounthandler class--------------------------------//
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
	cout << GetMoney() << endl;
}

//------------------------------AccountHandler 멤버함수----------------------//

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
	int rate = 0;
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
		customers[customersCount++] = new NormalAccount(incredit, inname, inmoney,interest);

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