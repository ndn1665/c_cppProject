#pragma once
//Account 클래스의 선언
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int creditNum;
	char* name;
	int money;

public:
	Account(int incdnum, char* inname, int inmoney);
	Account(const Account& copy);
	virtual void AddRate(int inrate);
	virtual void Deposit(int depositMoney);
	int Withdraw(int withdrawMoney);
	int GetCreditNum() const;
	int GetMoney() const;
	void showAll() const;
	~Account();
};


#endif 
