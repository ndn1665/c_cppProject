#include<iostream>
using namespace std;

int main()
{
	int arr[26];

	char text[10001];
	for (int i = 0; i < 26; i++)
	{
		arr[i] = 0;
	}

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
	cin.getline(text, 10001, ';');
	int count = 0;
	for (int i = 0; i < strlen(text); i++)
	{
		if (isalpha(text[i]))
		{
			count++;
			text[i] = tolower(text[i]);
			arr[text[i] - 'a']++;
		}
	}

	cout << "총 알파벳 수 " << count << endl;
	cout << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << char(i + 97) << " (" << arr[i] << ") " << ": ";
		for (int j = 0; j < arr[i]; j++)
		{
			cout << '*';
		}
		cout << endl;
	}

	return 0;
}