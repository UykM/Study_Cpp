#include <iostream>
using namespace std;

class FruitSeller
{
private:
	// int APPLE_PRICE;
	const int APPLE_PRICE;		// const 변수는 선언과 동시에 초기화해야 했기 때문에,
	int numOfApples;			// Initializer (선언과 동시에 초기화 가능)를 이용하면 const로 선언 가능.
	int myMoney;

public:
	/*
	FruitSeller(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	*/
	FruitSeller(int price, int num, int money)
		: APPLE_PRICE(price), numOfApples(num), myMoney(money)	// 선언과 동시에 초기화
	{
	}

	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult() const
	{
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
	int myMoney;		// private:
	int numOfApples;	// private:

public:
	/*
	FruitBuyer(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	*/
	FruitBuyer(int money)
		: myMoney(money), numOfApples(0)
	{
	}

	void BuyApples(FruitSeller& seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult() const
	{
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main(void)
{
	/*
	FruitSeller seller;
	seller.IniMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);		// 과일의 구매
	*/
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}