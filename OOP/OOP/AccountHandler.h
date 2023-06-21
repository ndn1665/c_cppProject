#pragma once
//AccountHandlerÀÇ ¼±¾ð
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "BankingCommonDec1.h"
#include "Account.h"

class AccountHandler
{
private:
	Account* customers[100];
	int customersCount;
public:
	AccountHandler();
	void ShowMenu() const;
	void AccountCreate();
	void AccountDeposit();
	void AccountWithdraw();
	void ShowAll() const;
	~AccountHandler();
};

#endif // !__ACCOUNT_HANDLER_H__
