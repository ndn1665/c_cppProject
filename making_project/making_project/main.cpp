#include "commonDecl.h"

//userboard넣어서 유저게시판 만들기
class Game
{
private:
	int score;
public:
	Game()
		:score(0)
	{
		srand((unsigned int)time(NULL));
	}
	virtual void Play() = 0;
	virtual void SetScore(int score)
	{
		this->score = score;
	}
	void MinusScore()
	{
		this->score -= 1;
	}
	virtual int Result() = 0;
	int GetScore() const
	{
		return score;
	}
};

class SlotGame : public Game
{
private:
	int arr[3];
public:
	SlotGame()
	{
		for (int i = 0; i < 3; i++)
		{
			arr[i] = 0;
		}
	}
	void Play()
	{
		arr[0] = rand() % 9 + 1;
		arr[1] = rand() % 9 + 1;
		arr[2] = rand() % 9 + 1;
		cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	}
	void SetScore(int money)
	{
		Game::SetScore(money / 500);
	}
	int Result()
	{
		if (arr[0] == arr[1] && arr[1] == arr[2]) return 500 * 100;
		else return -500;
	}
};

class CoinGame : public Game
{
private:
	bool coin;
public:
	CoinGame() {}
	void Play()
	{
		coin = rand() % 2;
		cout << coin << endl;
	}
	void SetScore(int money)
	{
		Game::SetScore(money / 1000);
	}
	int Result()
	{
		if (coin == true) return 1000 * 1.5;
		else return -1000;
	}
};



class GameControl
{
private:
	Game* game;
	int money;
public:
	GameControl(int money)
	{
		this->money = money;
	}
	void ChooseGame()
	{
		int choice;
		cout << "============================================================" << endl;
		cout << "  게임 선택 \n  1. 슬롯게임  2.동전던지기" << endl;
		cin >> choice;

		if (choice <= 0 || choice > 2) exit(1);

		else if (choice == 1)
		{
			game = new SlotGame;
			PlayGame();
		}
		else if (choice == 2)
		{
			game = new CoinGame;
			PlayGame();
		}
	}
	void MoneyChange(int x)
	{
		money += x;
	}
	void PlayGame()
	{
		game->SetScore(money);
		while (game->GetScore() != 0)
		{
			game->Play();
			game->MinusScore();
			money += game->Result();
			ShowMoney();
			
		}
	}
	void ShowMoney() const
	{
		cout << money << endl;
	}
};

int main(void)
{
	int money;
	
	cout << "============================================================" << endl;
	cout << "입금액을 넣으시오 : "; cin >> money;
	if (money <= 0) exit(1);
	GameControl control(money);
	control.ChooseGame();


	


	return 0;
}