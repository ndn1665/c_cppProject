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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	int choice;
	cout << "���� : ";
	cin >> choice;
	int customerNum = 0;
	while (true) {
		
		if (choice == 1) {
			cout << "[���°���]" << endl;
			cout << "���� ID : ";
			cin >> customers[customerNum].creditNum;
			cout <<  "�̸� : ";
			cin >> customers[customerNum].name;
			cout << "�Աݾ� : ";
			cin >> customers[customerNum].money;
			customerNum += 1;
		}
		if (choice == 2) {
			int id;
			int inputMoney;
			cout << "[�� ��]" << endl;
			cout << "���� ID : ";
			cin >> id;
			cout << "�Աݾ� : ";
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
			cout << "[�� ��]" << endl;
			cout << "���� ID : ";
			cin >> id;
			cout << "��ݾ� : ";
			cin >> withdrawMoney;
			for (int i = 0; i < 10; i++) {
				if (customers[i].creditNum == id) {
					customers[i].money -= withdrawMoney;
				}
			}
		}
		if (choice == 4) {
			for (int i = 0; i <= customerNum; i++) {
				cout << "���� ID : "<< customers[i].creditNum << endl;
				cout << "�̸� : " << customers[i].name << endl;
				cout << "�ܾ� : " << customers[i].money << endl;

			}
		}

		if (choice == 5) {
			break;
		}

		cout << "���� : ";
		cin >> choice;
	}

	return 0;
}