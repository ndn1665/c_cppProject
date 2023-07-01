#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__
#
#include "NormalAccount.h"

class HighCreditAccount :public NormalAccount
{
private:
	int rate;
public:
	HighCreditAccount(int incdnum, char* inname, int inmoney, int ininter, int special)
		:NormalAccount(incdnum, inname, inmoney, ininter),rate(special)
	{}
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

#endif // !__HIGHCREDIT_ACCOUNT_H__

