// ����Ʈ ���� ������
// ��� �� ����� ����(���� ����)�� ����
// ������ ������ ���� �Ҵ��� �Ѵٸ�, �׸��� ���� ���簡 �ʿ��ϴٸ� ���� ����
// ���� �������� Ư���� �ſ� ���ϻ�����, ȣ��Ǵ� �������� ���̰� ����.
/*
#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1=0, int n2=0) : num1(n1), num2(n2)
	{ }
	void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{ }
	void ShowData() { cout << num3 << ", " << num3 << endl; }

	Second& operator=(const Second& ref)
	{
		cout << "Seccond& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main(void)
{
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc;		// fcpy.operator=(fsrc)
	scpy = ssrc;		// scpy.operator=(ssrc)
	fcpy.ShowData();
	scpy.ShowData();

	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;
	sob1 = sob2 = ssrc;

	fob1.ShowData();
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return 0;
}
*/

// ����Ʈ ���� �������� ���� 
/*
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
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}

���۰��
�̸�: Lee dong woo
����: 29
�̸�: Lee dong woo
����: 29
called destructor!		// �Ҹ��ڰ� �� ���ۿ� ȣ����� ����.

// ���� ����� ���ؼ� �ϳ��� ���ڿ��� �� ���� ��ü�� ���ÿ� �����ϴ� ��Ȳ�� ��������
// ��ü �Ҹ����(man2 ��ü�� �Ҹ�)���� �̹� �Ҹ�� ���ڿ�("Lee dong woo")�� �ߺ� �Ҹ��ϴ� ���� �߻�
// ���ڿ� "Yoon ji yul"�� �޸� ������ ���·� ����
*/

// ����Ʈ ���� �������� ������ (����Ʈ ���� �����ڿ� ����)
// ������ ������ ���� �Ҵ��� �ϴ� ���, ����Ʈ ���� �����ڴ� �� ���� ������ �߻�
// �̴� ���� ���縦 �����ϰ�, �޸� ������ �߻����� �ʵ��ϱ��� ���翡 �ռ� �޸� ��ü�� ������ ����
// ���� �����ؾ���!

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
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person& operator=(const Person& ref)
	{
		delete[]name;		// �޸��� ������ ���� ���� �޸� ��ü ����
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
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
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}


/* ��� ���������� ���� ������ ȣ��
* ���� ������ = ������ X
* ���� Ŭ����(derived class)�� �����ڿ��� �ƹ��� ��ø� ���� �ʾƵ� ���� Ŭ����(base class)�� �����ڰ� ȣ���.
* ���� Ŭ������ ���� �����ڿ��� �ƹ��� ��ø� ���� ������, ���� Ŭ������ ���� �����ڰ� ȣ�� X

#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{ }
	void ShowData() { cout << num1 << ", " << num2 << endl; }

	First& operator=(const First& ref)
	{
		cout << "Frist& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

class Second : public First
{
private:
	int num3, num4;
public:
	Second(int n1, int n2, int n3, int n4) 
		: First(n1, n2), num3(n3), num4(n4)
	{ }
	void ShowData() 
	{ 
		First::ShowData();
		cout << num3 << ", " << num3 << endl; 
	}

	// Seconst& operator=(const Second&) �ּ� ó��
	Second& operator=(const Second& ref)	// ���� Ŭ������ ���� ������ ����
	{
		cout << "Seccond& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
	
};

int main(void)
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;
	scpy.ShowData();
	return 0;
}

�ּ�ó�� �� ���, ���� ���
First& operator=()
111, 222
333, 444

�ּ��� ������ ���, ���� ���
Second& operator=()
0, 0
333, 444
// ���� Ŭ������ ���� ������ ���ǿ���, ��������� ���� Ŭ������ ���� ������ ȣ�⹮�� ����.
// ������, ���� Ŭ������ ���� �����ڴ� ȣ����� �ʾƼ�, 
// ���� Ŭ������ ��������� ��� �� ����� ���� ��󿡼� ���ܵ�

// ���� �� ������ Second Ŭ������ ���� �����ڴ� ������ ���·� ���ǵǾ�� ��.
Second& operator=(const Second& ref)
	{
		cout << "Seccond& operator=()" << endl;
		First::operator=(ref);	// ���� Ŭ������ ���� ������ ȣ���� ���
								// First�� �����ڴ� First ��ü �Ǵ� First�� ���� Ȥ�� ���������� ����ϴ� ��� ��ü�� ������ �� ����.

		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
*/


// ���� �����ڿ� ���� �����ڸ� ��� �����ϸ� �̴ϼȶ������� ���� ��� ������ �ִ� ������ �� �� ����.
// �̴ϼȶ������� �̿��ϸ� ����� ���տ� �ʱ�ȭ�� �̷����� ����.