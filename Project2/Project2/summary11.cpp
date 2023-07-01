//����ó��

#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

//����Ŭ���� ������

class AccountException
{
public:
	virtual void Show() const = 0;
};

class DepositException : public AccountException
{
private:
	int reqDep;
public:
	DepositException(int money) :reqDep(money)
	{}
	virtual void Show() const
	{
		cout << "[���� �޽��� : " << reqDep << "�� �Ա� �Ұ�" << endl;
	}
};

class WithdrawException : public AccountException
{
private:
	int balance;
public:
	WithdrawException(int money) : balance(money)
	{}
	virtual void Show() const
	{
		cout << "[���� �޽��� : " << balance << ", �ܾ׺���" << endl;
	}

};

class Account
{
private:
	char accNum[50];
	int balance;
public:
	Account(const char* num, int money)
		:balance(money)
	{
		strcpy(accNum, num);
	}
	void Deposit(int money) throw (AccountException) // ����ó���ϴ� ���������� ������ִ� throw��
	{
		if (money < 0)
		{
			DepositException expn(money); //���ܰ�ü�� ����
			throw expn;//���ܰ�ü�� ���� // main�Լ��� ���޵�
		}
		balance += money;
	}

	void Withdraw(int money) throw (AccountException)
	{
		if (money > balance)
		{
			throw WithdrawException(money);//����ó���� �̷��� �ӽð�ü�� ����ϴ°� �Ϲ���
		}
		balance -= money;
	}
	void ShowMoney() const
	{
		cout << "�� �ܾ� : " << balance << endl;
	}
};

int main(void)
{
	//try , throw, catch �� ����

	Account acc("7102-1665", 10000);
	try
	{
		acc.Deposit(1000);
		acc.Deposit(-100);
	}
	catch (AccountException &expn)//���� ������ �ʿ���� �����ڷ� ����ó���ϴ°��� ���������鿡�� ȿ���� 
	{
		expn.Show();
	}
	try
	{
		acc.Withdraw(5000);
		acc.Withdraw(50000);
	}
	catch (AccountException &expn)
	{
		expn.Show();
	}
	catch (...) // ���޵Ǵ� ��� ���ܸ� �� �޾��ִ� ����
	{
	}

	cout << endl;
	return 0;
}