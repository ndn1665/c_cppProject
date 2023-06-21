//Account 클래스의 정의
#include "BankingCommonDec1.h"
#include "Account.h"

Account::Account(int incdnum, char* inname, int inmoney)
	:creditNum(incdnum), money(inmoney)
{
	name = new char[strlen(inname) + 1];
	strcpy(name, inname);
}

void Account::AddRate(int inrate) {}

Account::Account(const Account& copy)
	:creditNum(copy.creditNum), money(copy.money)
{
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
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

Account::~Account()
{
	delete[]name;
}
