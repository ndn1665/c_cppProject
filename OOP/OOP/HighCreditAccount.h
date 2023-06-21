#pragma once
//HighCreditAccount의 선언과 정의
#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "BankingCommonDec1.h"
#include "Account.h"
#include "NormalAccount.h"
class HighCreditAccount :public NormalAccount
{
private:
	int rate;
public:
	HighCreditAccount(int incdnum, char* inname, int inmoney, int ininter)
		:NormalAccount(incdnum, inname, inmoney, ininter), rate(0)
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

		Account::Deposit(depositMoney + (int)(depositMoney * ((double)(GetInter() + calRate) / 100)));
	}
};
#endif // !__HIGH_CREDIT_ACCOUNT_H__
