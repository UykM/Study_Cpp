#pragma once

class MinusException
{
private:
	int exval;		// 예외의 원인이 되는 금액
public:
	MinusException(int val) : exval(val)
	{ }

	void ShowExceptionInfo(void) const
	{
		cout << "입(출)금액 " << exval << "은 유효하지 않습니다!" << endl;
	}
};

class InsuffException
{
private:
	int money;		// 현재 잔액
	int reqval;		// 출금 요구액
public:
	InsuffException(int val, int req)
		: money(val), reqval(req)
	{ }

	void ShowExceptionInfo() const
	{
		cout << "잔액에서 " << reqval - money << "원이 부족합니다!" << endl;
	}
};

