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

class Police
{
private:
	int handcuffs;		// ������ ������ ��
	Gun* pistol;		// �����ϰ� �ִ� ����
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(const Police& ref)
		: handcuffs(ref.handcuffs)
	{
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));		// Gun �� ��������� ȣ��
		else
			pistol = NULL;
	}
	Police& operator=(const Police& ref)
	{
		if (pistol != NULL)
			delete pistol;

		if(ref.pistol )
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
};

int main(void)
{
	Police pman(5, 3);		// �Ѿ� 5, ���� 3
	pman.Shot();
	pman.PutHandcuff();
	return 0;
}
