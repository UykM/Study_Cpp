// ����� ���� �⺻ ������ IS-A ����
// ��ȭ�� IS A ���� ��ȭ�� , �� ���� ��ȭ�⵵ ������ ��ȭ����.
// ���� Ŭ������ ���� Ŭ�������� �̷��� IS-A ���谡 �����ؾ� ��.
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
	char owner[50];
public:
	Computer(const char* name)
	{
		strcpy(owner, name);
	}
	void Calculate()
	{
		cout << "��û ������ ����մϴ�." << endl;
	}
};

class NotebookComp : public Computer
{
private:
	int Battery;
public:
	NotebookComp(const char* name, int initChag)
		: Computer(name), Battery(initChag)
	{}
	void Charging()
	{
		Battery += 5;
	}
	void UseBattery()
	{
		Battery -= 1;
	}
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo()
	{
		return Battery;
	}
};

class TableNotebook : public NotebookComp
{
private:
	char regstPenModel[50];
public:
	TableNotebook(const char* name, int initChag, const char* pen)
		: NotebookComp(name, initChag)
	{
		strcpy(regstPenModel, pen);
	}
	void Write(const char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)		// strcmp(���ڿ�A, ���ڿ�B)		���ڿ�A == ���ڿ�B �� ��쿡 0�� ��ȯ
		{
			cout << "��ϵ� ���� �ƴմϴ�.";
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("�̼���", 5);
	TableNotebook tn("������", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
	return 0;
}

// HAS-A ���� (������ ����)
// ���� HAS-A ��
/*
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;		// ������ �Ѿ��� ��
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shot()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police : public Gun
{
private:
	int hnadcuffs;		// ������ ������ ��
public:
	Police(int bnum, int bcuff)
		: Gun(bnum), handcuffs(bcuff)
	{ }
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
};

int main(void)
{
	Police pman(5,3);		// �Ѿ� 5, ���� 3
	pman.Shot();
	pman.PutHandcuff();
	return 0;
}
*/

// ������ �� ����� ������� ǥ���� �� ������, �ٸ� ������ε� ǥ���� �����ϰ�,
// ������ ���迡 �ش��ϴ� Ŭ������ ����� �ƴ� �ٸ� ������� ǥ���ϴ� ���� �� ���� �����.
// �� ������, ������� ǥ���� ��쿣 
// "������ �������� ���� ������ ǥ���ؾ� �մϴ�.", "������ ���Ѱ� �����Ӹ� �ƴ϶�, ������� �����ϱ� �����߽��ϴ�." ���� �䱸������ �ݿ��ϱ� ���� ����.
// ������� ���� �� Ŭ������ ���� �������� ��� ������.
// ���� ����ó�� Gun Ŭ������ ����ϴ� Police Ŭ�����δ� ���� �����ϴ� ������ ǥ���� ����.
// ��, HAS-A ������ ǥ���� ����� Ȱ���Ѵٸ� ���α׷��� ���濡 ���� ������ ������ �� ����.
// ���� ������ ���迡 �ش��ϴ� Ŭ������ ����� �ƴ� �ٸ� ������� ǥ���ϴ� ���� �� �ٶ����� ���!