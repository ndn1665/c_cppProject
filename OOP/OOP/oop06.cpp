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

//------------------------------AccountHandler ����Լ�----------------------//

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
		customers[customersCount++] = new NormalAccount(incredit, inname, inmoney,interest);

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