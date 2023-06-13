#include<iostream>
#include "cal.h"
using namespace std;


int main(void)
{
	Calculator cal;
	cal.init();
	cout << cal.add(3.2, 2.4) << endl;
	cout << cal.min(3.5, 1.7) << endl;
	cout << cal.mul(2.2, 1.5) << endl;
	cout << cal.div(4.9, 1.2) << endl;
	cal.ShowOpCount();
}
