#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
char * func(char* ptr) {

	strcpy_s(ptr, 6, "hello");
	return ptr;
}

int main(void) {
	char name1[20];
	char new_name[20];

	printf("%s",func(name1));
	return 0;
}
*/

//malloc

char* func(void) {
	char* name = (char*)malloc(sizeof(char) * 10);//���� �޸𸮰� �Ҵ�Ǿ��ֱ� ������, �Լ��� ������ �޸𸮰� ��������.
	printf("input : ");
	fgets(name, 10, stdin);
	return name;//�Լ������� �ʱ�ȭ�� ������ ���� �ּҰ�(�޸��� ��ġ�� ���� �ֱ⶧����)�� ��ȯ�� �� �ְ� ��,
}

int main(void) {

	int* ptr1 = (int*)malloc(sizeof(int));
	int* ptr2 = (int*)malloc(sizeof(int) * 10); //���̰� 10�� �迭�� �޸𸮸� heap�� �Ҵ���
	/*
	�޸� �Ҵ翩�� Ȯ��
	�޸𸮰� �Ҵ���� ������ ptr�� null�� ��ȯ
	if(ptr !=){}

	*/
	/*
	realloc : ���� �Ҵ�� �޸��� ũ�� ����
	void * realloc(void * ptr,size_t size)
	ex> arr = (int *)realloc(ptr,sizeof(int)*100);

	*/
	ptr1 = 10;

	for (int i = 0; i < 10; i++) {
		ptr2[i] = i;
	}

	printf("%d\n", ptr1);
	for (int i = 0; i < 10; i++) {
		printf("%d", ptr2[i]);
	}

	free(ptr1);//free �� ���� �Ҵ�Ǿ��ִ� �޸� ����
	free(ptr2);

	return 0;
}