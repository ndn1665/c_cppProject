#include<iostream>
using namespace std;

class FruitSeller
{
private:

	int apple_price;
	int num_of_apples;
	int my_money;

public:

	void Initmem(int price, int num, int money)
	{
		apple_price = price;
		num_of_apples = num;
		my_money = money;
	}
	int Saleapples(int money)
	{
		if (money < 0)
		{
			cout << "cannot pay under 0" << endl;
			return false;
		}
		int count = money / apple_price;
		num_of_apples -= count;
		my_money += count * apple_price;
		return count;
	}
	void Saleresult() const
	{
		cout << "num of apples left : " << num_of_apples << endl;
		cout << "money left : " << my_money << endl;
	}

};

class Fruitbuyer
{
private:
	int num_of_apples;
	int my_money;
public:
	void Initmem(int apples, int money)
	{
		num_of_apples = apples;
		my_money = money;
	}
	int Buyapples(FruitSeller& seller, int money)
	{
		int num = seller.Saleapples(money);
		if (num == false)
		{
			cout << "money wrong" << endl;
			return false;
		}
		num_of_apples += num;
		my_money -= money;
		return num_of_apples;
	}
	void Buyresult() const
	{
		cout << "num of apples baught : " << num_of_apples << endl;
		cout << "money left : " << my_money << endl;
	}
};

int main(void)
{
	FruitSeller seller;
	Fruitbuyer buyer;

	seller.Initmem(1000, 10, 2000);
	buyer.Initmem(0, 12000);

	if (buyer.Buyapples(seller, 8000))
	{
		seller.Saleresult();
		buyer.Buyresult();
	}


	return 0;
}