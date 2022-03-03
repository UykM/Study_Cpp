#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;		// 장전된 총알의 수
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
	int handcuffs;		// 소유한 수갑의 수
	Gun* pistol;		// 소유하고 있는 권총
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
			pistol = new Gun(*(ref.pistol));		// Gun 의 복사생성자 호출
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
	Police pman(5, 3);		// 총알 5, 수갑 3
	pman.Shot();
	pman.PutHandcuff();
	return 0;
}
