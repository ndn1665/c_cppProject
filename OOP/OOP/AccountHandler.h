#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundedArray.h"
typedef Account* Account_ptr;
class AccountHandler
{
private:
	BoundedArray<Account*> customers;
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



#endif

