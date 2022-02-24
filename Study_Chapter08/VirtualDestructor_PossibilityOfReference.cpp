// ���� �Ҹ���(Virtual Destructor)
// ���� �Ҹ��ڰ� ȣ��Ǹ�, ����� ���������� �� �Ʒ��� �����ϴ� ���� Ŭ����(derived class)�� �Ҹ��ڰ� ��� ȣ��Ǹ鼭,
// ���� Ŭ����(base class)�� �Ҹ��ڰ� ���������� ȣ���.
#include <iostream>
using namespace std;

class First
{
private:
	char* strOne;
public:
	First(const char* str)
	{
		strOne = new char[strlen(str) + 1];
	}
	//~First()
	virtual ~First()		// ���� �Ҹ���
	{
		cout << "~First()" << endl;
		delete[]strOne;
	}
};

class Second : public First
{
private:
	char* strTwo;
public:
	Second(const char* str1, const char* str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	~Second()		// �Ҹ��ڵ� ����� ���������� �� ���� �����ϴ� ����(base) Ŭ������ �Ҹ��ڸ� virtual�� �����ϸ�, 
	{				// �̸� ����ϴ� ���� Ŭ������ �Ҹ��ڵ��� ��� '���� �Ҹ���)�� �����.
		cout << "~Second()" << endl;
		delete[]strTwo;
	}
};

int main(void)
{
	First* ptr = new Second("simple", "complex");
	delete ptr;		// First Ŭ������ �Ҹ��ڿ� Second Ŭ������ �Ҹ��ڰ� ���ÿ� ȣ��Ǿ�� ��.
					// ������, ��ü�� �Ҹ��� First�� �����ͷ� ����Ͽ�, First Ŭ������ �Ҹ��ڸ� ȣ��
					// �̷��� ��쿣 �޸��� ����(leak)�� �߻�.
					// ���� ��ü�� �Ҹ�������� delete �����ڿ� ���� ������ ������ �ڷ����� ������� ��� �Ҹ��ڰ� ȣ��ž� ��.
					// �̸� ���ؼ� �Ҹ��ڿ� virtual ������ �߰����ִ� ��!
	return 0;
}


/* �������� ���� ���ɼ�
"AAA�� ������ ������ AAA ��ü �Ǵ� AAA�� ���� Ȥ�� ���������� ����ϴ� ��� ��ü�� ����ų �� �ִ�.(��ü�� �ּ� �� ���� ����)"
�̷��� Ư���� �����ڿ��� �����.
�� AAA�� �����ڴ� AAA ��ü �Ǵ� AAA�� ���� Ȥ�� ���������� ����ϴ� ��� ��ü�� ���� ����!

#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj;	// obj�� Second Ŭ������ ���� ����ϴ� Third Ŭ������ ��ü�̹Ƿ�, Second�� �����ڷ� ���� ������.
						// Third Ŭ������ ���ǵ� ThirdFunc �Լ��� ȣ�� �Ұ���
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();	// SimpleFunc�� �����Լ��̹Ƿ�, Third Ŭ������ ���ǵ� SimpleFunc �Լ��� ȣ���.

	First& fref = obj;	// obj�� First Ŭ������ ���� ����ϴ� Third Ŭ������ ��ü�̹Ƿ�, First�� �����ڷ� ���� ������.
						// Second Ŭ������ ���ǵ� SecondFunc �Լ��� Third Ŭ������ ���ǵ� ThirdFunc �Լ��� ȣ�� �Ұ���
	fref.FirstFunc();
	fref.SimpleFunc();	// SimpleFunc�� �����Լ��̹Ƿ�, Third Ŭ������ ���ǵ� SimpleFunc �Լ��� ȣ���.
	return 0;
}


������ ���� ���ǵ� �Լ��� ���� �Ǹ�,
void GoddFunction(const First &ref) { .... }

1) First ��ü �Ǵ� First�� ���� Ȥ�� ���������� ����ϴ� Ŭ������ ��ü�� ������ ����� �ȴٴ� ����� ���
2) ���ڷ� ���޵Ǵ� ��ü�� ���� �ڷ����� ������� �Լ� �������� First Ŭ������ ���ǵ� �Լ��� ȣ���� �� �ִٴ� ����� ���
*/