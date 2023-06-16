#include<iostream>

using namespace std;
using std::cin;
typedef struct customer {
	int creditNum;
	char name[100];
	int money;
}Customer;

int main(void) {
	Customer customers[10];

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
			cout << "[계좌개설]" << endl;
			cout << "계좌 ID : ";
			cin >> customers[customerNum].creditNum;
			cout <<  "이름 : ";
			cin >> customers[customerNum].name;
			cout << "입금액 : ";
			cin >> customers[customerNum].money;
			customerNum += 1;
		}
		if (choice == 2) {
			int id;
			int inputMoney;
			cout << "[입 금]" << endl;
			cout << "계좌 ID : ";
			cin >> id;
			cout << "입금액 : ";
			cin >> inputMoney;
			for (int i = 0; i < 10; i++) {
				if (customers[i].creditNum == id) {
					customers[i].money += inputMoney;
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
			for (int i = 0; i < 10; i++) {
				if (customers[i].creditNum == id) {
					customers[i].money -= withdrawMoney;
				}
			}
		}
		if (choice == 4) {
			for (int i = 0; i <= customerNum; i++) {
				cout << "계좌 ID : "<< customers[i].creditNum << endl;
				cout << "이름 : " << customers[i].name << endl;
				cout << "잔액 : " << customers[i].money << endl;

			}
		}

		if (choice == 5) {
			break;
		}

		cout << "선택 : ";
		cin >> choice;
	}

	return 0;
}