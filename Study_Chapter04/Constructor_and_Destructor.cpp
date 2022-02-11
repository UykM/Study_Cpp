#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:		// �������� �����ε��� �����ϴ�.
	SimpleClass()		// ��ü ����
	{					// SimpleClass sc1();	 �Ұ�ȣ ���� �Ұ� (X)  
		num1 = 0;		// -> �Լ��� �������� ��ü�� �������� ���� �Ұ�
		num2 = 0;		// SimpleClass sc1;		(O)
						// SimpleClass *ptr1 = new SimpleClass;
						// SimpleClass *ptr1 = new SimpleClass();
	}
	
	SimpleClass(int n)		// ��ü ����
	{						// SImpleClass sc2(100);	- ���� �� ���������� ����
		num1 = n;			// SimpleClass * ptr2 = new SimpleClass(100)	- ���� �Ҵ��� ����
		num2 = 0;
	}
	
	SimpleClass(int n1, int n2)			
	{
		num1 = n1;
		num2 = n2;
	}

	/* �ּ� ������, ������ ����
	
	SimpleClass sc2(100); 
	��ó�� ��ü�� �����ϸ� 15���� �����ڿ� 30���� �����ڰ� ��� ȣ�� �����ؼ�,
	ȣ���� �����ڸ� �������� ���ؼ� ������ ���� �߻�.
	
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}
	*/

	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};



int main(void)
{
	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100, 200);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();

	return 0;
}

/* �Ҹ���(Destructor) : ����Ʈ ������(Default Constructor)�� ����������, ���� �Ҹ��ڸ� �������� ������ �ڵ����� ���Ե�.

class AAA
{
	// empty class
}

class AAA
{
public:
	AAA() {}
	~AAA() {}
};

���� �� Ŭ���� ���Ǵ� ������.
�̷��� �Ҹ���(Destructor)�� �밳 �����ڿ��� �Ҵ��� ���ҽ��� �Ҹ꿡 ����.
���� ��� new �����ڸ� �̿��ؼ� �Ҵ��� ���� �޸� ������ �ִٸ�,
�Ҹ��ڿ����� delet �����ڸ� �̿��ؼ� �� �޸� ������ �Ҹ���.

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("�� �� ��", 22);
	man1.ShowPersonInfo();

	return 0;
}
*/