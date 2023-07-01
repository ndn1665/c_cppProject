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

	virtual void Deposit(int depositMoney);
	int Withdraw(int withdrawMoney);

	int GetCreditNum() const;
	int GetMoney() const;
	void showAll() const;

	~Account();

};
#endif // !__ACCOUNT_H__
