#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable: 4996)
class Book {

	char* title; // 제목 문자열
	int price; // 가격

public:

	Book(const char* title, int price);
	
	Book(Book& b); // 깊은 복사 복사 생성자 작성
	
	~Book(); void set(const char* title, int price);
	
	void show() 
	{
		cout << title << ' ' << price << "원" << endl;
	}

};

Book::Book(const char* title, int price) {
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}

Book::Book(Book& b)
{
	int len = strlen(b.title);
	title = new char[len + 1];
	strcpy(title, b.title);
	price = b.price;
}

void Book::set(const char* title, int price) { //
	if(this->title) delete [] this->title;
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}
Book::~Book()
{
	delete[]title;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}