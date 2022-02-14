#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER};

	void ShowPositionInfo(int pos)
	{
		switch(pos)
		{
			case CLERK:
				cout << "���" << endl;
				break;
			case SENIOR:
				cout << "����" << endl;
				break;
			case ASSIST:
				cout << "�븮" << endl;
				break;
			case MANAGER:
				cout << "����" << endl;
				break;
		}
	}
}

class NameCard
{
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	NameCard(const char* _name, const char* _company, const char* _phone, int _position)
		: position(_position)
	{
		name = new char[strlen(_name) + 1];
		company = new char[strlen(_company) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(name, _name);
		strcpy(company, _company);
		strcpy(phone, _phone);
	}

	void ShowNameCardInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "��ȭ��ȣ: " << phone << endl;
		cout << "����: "; COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}

	~NameCard()
	{
		delete[]name;
		delete[]company;
		delete[]phone;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::CLERK);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
}