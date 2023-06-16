#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Customer
{
private:
	int creditNum;
	char* name;
	int money;
public:
	Customer(){}
	void AccountCreate();
	void Deposit(int depositMoney);
	void Withdraw(int withdrawMoney);
	int get_creditNum() const;
	void showAll() const;
};


int main(void) {
	Customer* customers[10];


	cout << "-----MENU-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	int choice;
	cout << "선택 : ";
	cin >> choice;
	int customerNum = 0;


	while (true) {

		if (choice == 1) {
			customers[customerNum] = new Customer;
			customers[customerNum]->AccountCreate();
			customerNum += 1;
		}
		if (choice == 2) {
			int id;
			int depositMoney;

			cout << "[입 금]" << endl;
			cout << "계좌 ID : ";
			cin >> id;
			cout << "입금액 : ";
			cin >> depositMoney;
			
			for (int i = 0; i < customerNum; i++) 
			{
				if (customers[i]->get_creditNum() == id) 
				{
					customers[i]->Deposit(depositMoney);
				}
			}
		}
		if (choice == 3) {
			int id;
			int withdrawMoney;

			cout << "[출 금]" << endl;
			cout << "계좌 ID : ";
			cin >> id;
			cout << "출금액 : ";
			cin >> withdrawMoney;

			for (int i = 0; i < customerNum; i++) 
			{
				if (customers[i]->get_creditNum() == id) 
				{
					customers[i]->Withdraw(withdrawMoney);
				}
			}
		}
		if (choice == 4) {
			for (int i = 0; i < customerNum; i++) 
			{
				customers[i]->showAll();
			}
		}

		if (choice == 5) {
			for (int i = 0; i < customerNum; i++)
			{
				delete customers[i];
			}

			break;
		}

		cout << "선택 : ";
		cin >> choice;
	}

	return 0;
}

void Customer::AccountCreate()
{
	char inname[100];
	cout << "[계좌개설]" << endl;
	cout << "계좌 ID : ";
	cin >> creditNum;
	cout << "이름 : ";
	cin >> inname;
	name = new char[strlen(inname) + 1];
	strcpy(name, inname);
	cout << "입금액 : ";
	cin >> money;
}

int Customer::get_creditNum() const
{
	return creditNum;
}

void Customer::Deposit(int depositMoney)
{
	money += depositMoney;
}

void Customer::Withdraw(int withdrawMoney)
{
	money -= withdrawMoney;
}

void Customer::showAll() const
{
	cout << creditNum << endl;
	cout << name << endl;
	cout << money << endl;
}