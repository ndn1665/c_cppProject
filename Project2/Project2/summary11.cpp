//예외처리

#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

//예외클래스 디자인

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
		cout << "[예외 메시지 : " << reqDep << "은 입금 불가" << endl;
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
		cout << "[예외 메시지 : " << balance << ", 잔액부족" << endl;
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
	void Deposit(int money) throw (AccountException) // 예외처리하는 데이터형을 명시해주는 throw문
	{
		if (money < 0)
		{
			DepositException expn(money); //예외객체의 생성
			throw expn;//예외객체의 전달 // main함수로 전달됨
		}
		balance += money;
	}

	void Withdraw(int money) throw (AccountException)
	{
		if (money > balance)
		{
			throw WithdrawException(money);//예외처리는 이렇게 임시객체를 사용하는게 일반적
		}
		balance -= money;
	}
	void ShowMoney() const
	{
		cout << "총 잔액 : " << balance << endl;
	}
};

int main(void)
{
	//try , throw, catch 로 구성

	Account acc("7102-1665", 10000);
	try
	{
		acc.Deposit(1000);
		acc.Deposit(-100);
	}
	catch (AccountException &expn)//굳이 복사할 필요없이 참조자로 직접처리하는것이 데이터측면에서 효과적 
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
	catch (...) // 전달되는 모든 예외를 다 받아주는 선언
	{
	}

	cout << endl;
	return 0;
}