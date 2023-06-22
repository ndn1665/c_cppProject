#include<iostream>
#pragma warning(disable: 4996)

using namespace std;
using std::cin;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(char* title, char* isbn, int tag)
		:price(tag)
	{
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);
	}

	Book(Book& ref)
		:price(ref.price)
	{
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
	}
	Book& operator=(Book& book)
	{
		delete[]title;
		delete[]isbn; // 메모리 누수방지를 위한 delete처리
		//기존 title에 저장된 주소값이 떠돌아다니지 않도록 지워주는것이다.

		price = book.price;
		title = new char[strlen(book.title) + 1];
		strcpy(title, book.title);
		isbn = new char[strlen(book.isbn) + 1];
		strcpy(isbn, book.isbn);
		return *this;
	}
	void show() const
	{
		cout << title << endl;
		cout << isbn << endl;
		cout << price << endl;

	}

	~Book()
	{
		delete[]title;
		delete[]isbn;
	}
};

class Ebook :public Book
{
private:
	char* DRMkey;
public:
	Ebook(char* title, char* isbn, int tag, char* DRMkey)
		:Book(title, isbn, tag)
	{
		this->DRMkey = new char[strlen(DRMkey) + 1];
		strcpy(this->DRMkey, DRMkey);
	}

	Ebook(Ebook& ref)
		:Book(ref)//Book의 복사생성자, 복사생성자도 이렇게 이니셜라이저 위치에 둘 수 있다.
	{
		DRMkey = new char[strlen(ref.DRMkey) + 1];
		strcpy(DRMkey, ref.DRMkey);
	}
	Ebook& operator=(Ebook& ebook)
	{
		Book::operator=(ebook);
		delete[]DRMkey;
		DRMkey = new char[strlen(ebook.DRMkey) + 1];
		strcpy(DRMkey, ebook.DRMkey);
		return *this;
	}
	void show() const
	{
		Book::show();
		cout << DRMkey << endl;

	}
	~Ebook()
	{
		delete[]DRMkey;
	}
};
int main(void)
{
	Ebook ebook1((char*)"tail", (char*)"011", 10000, (char*)"asfas");
	Ebook ebook2 = ebook1;
	ebook2.show();

	Ebook ebook3 = ebook1;
	ebook3.show();
	cout << endl;
	return 0;
}