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
	char* name = (char*)malloc(sizeof(char) * 10);//힙에 메모리가 할당되어있기 때문에, 함수를 나가도 메모리가 남아있음.
	printf("input : ");
	fgets(name, 10, stdin);
	return name;//함수내에서 초기화한 변수에 대한 주소값(메모리의 위치가 힙에 있기때문에)을 반환할 수 있게 됨,
}

int main(void) {

	int* ptr1 = (int*)malloc(sizeof(int));
	int* ptr2 = (int*)malloc(sizeof(int) * 10); //길이가 10인 배열의 메모리를 heap에 할당함
	/*
	메모리 할당여부 확인
	메모리가 할당되지 않으면 ptr은 null을 반환
	if(ptr !=){}

	*/
	/*
	realloc : 힙에 할당된 메모리의 크기 변경
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

	free(ptr1);//free 로 힙에 할당되어있는 메모리 삭제
	free(ptr2);

	return 0;
}