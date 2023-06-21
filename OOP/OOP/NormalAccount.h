#pragma once
//NormalAccount 클래스의 선언과 정의
#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "BankingCommonDec1.h"
#include "Account.h"


class NormalAccount :public Account
{
private:
	int interest;
public:
	NormalAccount(int incdnum, char* inname, int inmoney, int ininter)
		:Account(incdnum, inname, inmoney), interest(ininter)
	{}
	virtual void Deposit(int depositMoney)
	{
		Account::Deposit(depositMoney + (int)(depositMoney * ((double)interest / 100)));
	}
	int GetInter()
	{
		return interest;
	}

};


#endif // !__NORMAL_ACCOUNT_H__

