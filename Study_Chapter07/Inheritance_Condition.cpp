// 상속을 위한 기본 조건인 IS-A 관계
// 전화기 IS A 무선 전화기 , 즉 무선 전화기도 일종의 전화기임.
// 기초 클래스와 유도 클래스간에 이러한 IS-A 관계가 성립해야 함.
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
		cout << "요청 내용을 계산합니다." << endl;
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
			cout << "충전이 필요합니다." << endl;
			return;
		}
		cout << "이동하면서 ";
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
			cout << "충전이 필요합니다." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0)		// strcmp(문자열A, 문자열B)		문자열A == 문자열B 인 경우에 0을 반환
		{
			cout << "등록된 펜이 아닙니다.";
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("이수종", 5);
	TableNotebook tn("정수영", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
	return 0;
}

// HAS-A 관계 (소유의 관계)
// 경찰 HAS-A 총
/*
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

class Police : public Gun
{
private:
	int hnadcuffs;		// 소유한 수갑의 수
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
	Police pman(5,3);		// 총알 5, 수갑 3
	pman.Shot();
	pman.PutHandcuff();
	return 0;
}
*/

// 하지만 이 관계는 상속으로 표현할 수 있지만, 다른 방식으로도 표현이 가능하고,
// 소유의 관계에 해당하는 클래스는 상속이 아닌 다른 방식으로 표현하는 것이 더 좋은 방법임.
// 그 이유는, 상속으로 표현한 경우엔 
// "권총을 소유하지 않은 경찰을 표현해야 합니다.", "경찰이 권총과 수갑뿐만 아니라, 전기봉도 소유하기 시작했습니다." 등의 요구사항을 반영하기 쉽지 않음.
// 상속으로 묶인 두 클래스는 강한 연관성을 띠기 때문임.
// 위의 예제처럼 Gun 클래스를 상속하는 Police 클래스로는 총을 소유하는 경찰만 표현이 가능.
// 즉, HAS-A 관계의 표현에 상속을 활용한다면 프로그램의 변경에 많은 제약을 가져다 줄 것임.
// 따라서 소유의 관계에 해당하는 클래스는 상속이 아닌 다른 방식으로 표현하는 것이 더 바람직한 방법!