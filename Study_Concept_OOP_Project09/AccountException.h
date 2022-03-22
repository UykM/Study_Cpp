#pragma once

class MinusException
{
private:
	int exval;		// ������ ������ �Ǵ� �ݾ�
public:
	MinusException(int val) : exval(val)
	{ }

	void ShowExceptionInfo(void) const
	{
		cout << "��(��)�ݾ� " << exval << "�� ��ȿ���� �ʽ��ϴ�!" << endl;
	}
};

class InsuffException
{
private:
	int money;		// ���� �ܾ�
	int reqval;		// ��� �䱸��
public:
	InsuffException(int val, int req)
		: money(val), reqval(req)
	{ }

	void ShowExceptionInfo() const
	{
		cout << "�ܾ׿��� " << reqval - money << "���� �����մϴ�!" << endl;
	}
};

