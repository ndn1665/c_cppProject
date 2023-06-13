#pragma once
#ifndef __CAL_H__
#define __CALH__

class Calculator
{
private:
	double result;
	int add_count;
	int min_count;
	int mul_count;
	int div_count;

public:
	void init();
	double add(double num1, double num2);
	double min(double num1, double num2);
	double mul(double num1, double num2);
	double div(double num1, double num2);
	void ShowOpCount();
};


#endif