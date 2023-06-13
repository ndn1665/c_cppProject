#include "cal.h"
#include <iostream>
using namespace std;

void Calculator::init()
{
	result = 0;
	add_count = 0;
	min_count = 0;
	mul_count = 0;
	div_count = 0;
}
double Calculator::add(double num1, double num2)
{
	result = num1 + num2;
	add_count += 1;
	return result;
}
double Calculator::min(double num1, double num2)
{
	result = num1 - num2;
	min_count += 1;
	return result;
}
double Calculator::mul(double num1, double num2)
{
	result = num1 * num2;
	mul_count += 1;
	return result;
}
double Calculator::div(double num1, double num2)
{
	result = num1 / num2;
	div_count += 1;
	return result;
}
void Calculator::ShowOpCount()
{
	cout << "add : " << add_count << endl;
	cout << "min : " << min_count << endl;
	cout << "mul : " << mul_count << endl;
	cout << "div : " << div_count << endl;
}