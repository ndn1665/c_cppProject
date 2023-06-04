#include<stdio.h>
void simplefunc(void) {
	static int num1 = 0;
	int num2 = 0;

	printf("%d\n", num1);
	printf("%d\n", num2);
	num1++;
	num2++;

}

int main(void) {
	simplefunc();
	simplefunc();
	simplefunc();

	return 0;
}