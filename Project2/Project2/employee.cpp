#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Employee // Employee 객체 name 등록
{
private:
	char name[100];
public:
	Employee(char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name : " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee // PermanentWorker객체 salary 등록
{
private:
	int salary;
public:
	PermanentWorker(char* name, int money)
		:Employee(name), salary(money)
	{}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary info : " << salary << endl;
	}
	virtual int GetPay() const
	{
		return salary;
	}
};

class TemporaryWorker : public Employee // workTime , hourPay 등록
{
private:
	int workTime;
	int hourPay;
public:
	TemporaryWorker(char* name, int time, int pay)
		:Employee(name), workTime(time), hourPay(pay)
	{}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary info : " << GetPay() << endl;
	}
	virtual int GetPay() const
	{
		return workTime * hourPay;
	}
};

class SalesWorker : public PermanentWorker // +salary, salesResult,bonusRatio 등록
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(char* name, int money, int result, double ratio)
		:PermanentWorker(name, money), salesResult(result), bonusRatio(ratio)
	{}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary info : " << GetPay() << endl;
	}
	virtual int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)salesResult * bonusRatio;
	}
};

class ForeignSalesWorker : public SalesWorker
{
private:
	int risk;
public:
	ForeignSalesWorker(char* name, int money, int result, double ratio)
		:SalesWorker(name, money, result, ratio), risk(0)
	{}
	void RiskPay(int inrisk)
	{
		risk = inrisk;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary info : " << GetPay() << endl;
		cout << "risk is : " << risk << endl;
	}
	virtual int GetPay() const
	{
		return SalesWorker::GetPay() + (int)SalesWorker::GetPay() / risk;
	}

};

class EmployeeHandler
{
private:
	Employee* emplist[50]; //모든 Employee를 상속한 객체를 가리키는 리스트
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}//EmployeeHandler 생성자

	void AddEmployee(Employee* emp)//Employee를 emplist에 넣기
	{
		emplist[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const // 각 employee의 ShowSalaryInfo 함수 호출
	{
		for (int i = 0; i < empNum; i++)
		{
			emplist[i]->ShowSalaryInfo();
		}
	}

	void ShowTotalSalary() const // totalSalary 출력
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
		{
			sum += emplist[i]->GetPay();
		}
		cout << "Total Salary : " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
		{
			delete emplist[i];
		}
	}
};

int main(void)
{
	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker((char*)"kim", 220));
	handler.AddEmployee(new PermanentWorker((char*)"hong", 200));
	handler.AddEmployee(new TemporaryWorker((char*)"baek", 50, 1));
	handler.AddEmployee(new SalesWorker((char*)"noh", 100, 10000, 0.1));
	ForeignSalesWorker* fsw = new ForeignSalesWorker((char*)"tae", 100, 100, 0.2);
	fsw->RiskPay(30);
	handler.AddEmployee(fsw);

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();

	cout << endl;
	return 0;
}