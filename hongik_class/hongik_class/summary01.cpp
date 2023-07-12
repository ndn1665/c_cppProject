#include<iostream>
#include<string>
using namespace std;

int main()
{
	char line[100];
	int len = 50;
	cin.getline(line, len, '\n');// line에 len-1만큼 문자입력, \n를 만나면 (len-1만큼 입력 안했더라도) 종료 // 이건 문자열 배열을 만드는것이다.
	//len 자리엔 널문자가 삽입되기에 그 len -1까지만 입력 된다. 그리고 string line에는 사용할 수 없다. char line이어야 한다. // istream 헤더에 포함된 함수
	
	string line2; //string은 문자열 크기에 제약이 없음
	getline(cin, line2);//getline(cin,변수,구분자(생략가능'\n'))  // string 헤더에 포함된 함수
	string elvis("elvis presly");
	cout << elvis[0] << endl; // e
	string singer;
	if (singer == elvis) {}//이런식으로 사용 가능
	singer.size(); //-> 길이구하는 함수 .size() or singer.length() or singer.capacity() -> 

	/*
	추가적인 string함수
	singer.append() == singer+"sentence"
	singer.substr(시작위치,크기)
	singer.replace(시작위치,크기, 바꿀string)
	singer.find(문자열,start_index,길이)

	문자열 연산자
	+,+=, ==, < 등등

	변경함수
	stoi
	to_string
	*/

	string str("hello");
	string copystr(str);

	char text[] = { 'l','o','v','e','\0' };
	string love(text);

	cout << str << endl;
	cout << copystr << endl;
	cout << love << endl;

	
	return 0;
}