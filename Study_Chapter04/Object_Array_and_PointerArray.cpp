#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
		: age(myage)
	{
		name = new char[strlen(myname) + 1];	// �迭�� ����ʰ� ���ÿ� �����ڰ� ȣ���.
		strcpy(name, myname);
	}

	Person()					// ���� "��ü �迭�� ���"��, �ٸ� �Ű����� �����ڰ� ������, �⺻ �����ڰ� �ݵ�� ���ǵǾ� �־����!
								// �迭 ���� ���Ŀ� ������ ��Ҹ� ���ϴ� ������ �ʱ�ȭ
								// ��ü ������ �迭, ������ ���� �� �����ʹ� �⺻�����ڰ� �������� �ʴ´�.
		: name(NULL), age(0)	
	{
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char* myname, int myage)
	{
		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << ", ";
		cout << "����: " << age << endl;
	}

	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

// Array of Objects(��ü �迭)

int main(void)
{
	Person parr[3];			// ����� �Բ� �⺻ ������(Default Constructor) ȣ��
							// ClassName Object[n];  -  �⺻ ������ n�� ȣ��
							// ������ ����� ��ü
	char namestr[100];
	char* strptr;
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸�: ";
		cin >> namestr;
		cout << "����: ";
		cin >> age;
		strptr = new char[strlen(namestr) + 1];		
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);		// �����ڰ� ȣ���.
	}
	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();
	return 0;
}


// Array of Objects Pointer (��ü ������ �迭)
/*
int main(void)
{
	Person* parr[3];		// ������ ����� ��ü�� �ּ� ��
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸�: ";
		cin >> namestr;
		cout << "����: ";
		cin >> age;
		parr[i] = new Person(namestr, age);			// �������� Person::Person(const char*, int)�� ȣ��
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();
	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}
*/
