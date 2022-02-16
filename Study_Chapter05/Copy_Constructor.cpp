#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)					
		: num1(n1), num2(n2)
	{
		// empty
	}
	
	SoSimple(const SoSimple& copy)				// ���� ������ (�������� ������ �ǹ��ϴ� & �� �ݵ�� �����ؾ� ��.)
												// �� ���� �����ڿ� �ش��ϴ� �ڵ尡 �����Ǵ��� ����Ʈ ���� �����ڰ� �ڵ����� ���ԵǱ� ������ ���� ���� �����ڸ� ���� ������ �ʿ� X
												// ������, �ݵ�� ���� �����ڸ� �����ؾ� �ϴ� ��쵵 ����.
												// ��� �� ����� ���翡 ���Ǵ� ������ �����Ű�� ���� ������ ������ ���ʶ߸��� �����̱⿡, Ű���� const �� �����ؼ� �Ǽ��� ������.
		: num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	SoSimple sim2 = sim1;			// ���� ������ ȣ��
									// SoSimple sime2(sim1); ���� ������ ��ȯ
									// �̿� ���� �������� ��ȯ�� ������� �ʴ´ٸ�,
									// ���� ������ SoSimple �� Ű���� explicit �� ����.
									// explicit SoSimple(const SoSimple &copy)4
									//				:: num1(copy.num1), num2(copy.num2)
									// { }
									// �̷��� explicit �� ����Ǹ� SoSimple sim2(sim1) �� ���� ���·� ��ü�� ������ ���ۿ� ����.
	cout << "���� �� �ʱ�ȭ ����" << endl;
	sim2.ShowSimpleData();
	return 0;
}


/* ���� ���� ��� �� ����� ���縦 ���� ����(shallow copy) �� ��. ���� ������ ���� ���縦 ���� �� �߻��ϴ� ������.
#include <iostream>
#include <cstirng>
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
	Person man1("�� �� ��", 22);
	Person man2 = man1;				// ���� ����(shallow copy), ���� ������(������ ����Ʈ ������) ȣ��
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}

������

�̸�: �� �� ��
����: 22
�̸�: �Źα�
����: 22
called destructor!

�������κ��� �� �� �ִ� ������ "called destructor!" �� �� ���� ��µǾ��ٴ� ��.
��, �Ҹ��ڰ� �� ���� ȣ��ƴٴ� ����.
����Ʈ ���� �����ڴ� ��� �� ����� �ܼ� ���縦 �����ϱ� ������
���� ���� ��쿣 �� ���� ��ü(man1, man2)�� �ϳ��� ���ڿ��� ���ÿ� �����ϴ� ������ �߻��� ��.
����, man2 ��ü�� ���� �Ҹ�� ��Ȳ�� �����ϸ�,
man2�� �Ҹ��ڰ� ȣ��Ǹ鼭 man2 ��ü�� �����ϰ� �ִ� ���ڿ��� ���� �Ҹ��.
�̾ �����ִ� man1 ��ü�� �Ҹ��ڵ� ����Ǿ�� �ϴµ�, man1 ��ü�� �����ϴ� ���ڿ��� �̹� man2 ��ü�� �Բ� �Ҹ�� �����̱� ������,
�̹� ������ ���ڿ��� ������� delete ������ �ϱ� ������ ������ �߻�.
*/


/* ���� ���� ������ �ذ��ϱ� ���� ���� ����(deep copy)�� �̿���.
���� ����(deep copy) : ���� ������ �� �޸𸮸� �ѱ�� ���(���� ����)�� �ƴ� ���� �ѱ�� �޸𸮴� ���Ӱ� ����� ���
- ��ü ���� ���� ���ڿ��� ������. ����Ӹ� �ƴ϶�, �����ͷ� �����ϴ� ������ ��� �����Ѵٴ� �ǹ�.
���� ���� �ڵ忡 ���� ������ �ڵ常 �߰��ϸ� ������ �ذ��.
Person(const Person &copy) : age(copy.age}
{
	name = new char[strlen(copy.name)+1];		// ������ ��, new�� ���ο� �޸��� ������ �Ҵ��ϱ� ������ ���� ���� ���� �߻� X
	strcpy(name, copy.name);
}
*/



/* ���� �����ڰ� ȣ��Ǵ� ����

Case 1: ������ ������ ��ü�� �̿��ؼ� ���ο� ��ü�� �ʱ�ȭ�ϴ� ���(�ռ� ���� ���)
ex) Person man1("�� �� ��", 22);
	Person man2 = man1;


Case 2: Call-by-value ����� �Լ�ȣ�� �������� ��ü�� ���ڷ� �����ϴ� ���
ex) class SoSimple
	{
	private:
		int num;
	public:
		SoSimple(int n) : num(n)
		{ }
		SoSimple(const SoSimple & copy) : num(copy.num)
		{
			cout << "Called SoSimple(const SoSimple& copyt)" << endl;
		}
		void ShowData()
		{
			cout << "num : " << num << endl;
		}
	};

	void SimpleFuncObj(SoSimple ob)			// main �Լ����� ����(obj ��ü)�� ���� ����
	{
		ob.ShowData();
	}

	int main(void)
	{
		SoSimple obj(7);
		cout << "�Լ� ȣ�� ��" << endl;
		SimpleFuncObj(obj);					// SimpleFuncObj �� obj ��ü�� ���ڷ� ���� - ���� ������ ȣ��
		cout << "�Լ� ȣ�� ��" << endl;
		return 0;
	}

Case 3: ��ü�� ��ȯ�ϵ�, ���������� ��ȯ���� �ʴ� ���
ex) class SoSimple
	{
	private:
		int num;
	public:
		SoSimple(int n) : num(n)
		{ }
		
		SoSimple(const SoSimple & copy) : num(copy.num)
		{
			cout << "Called SoSimple(const SoSimple& copyt)" << endl;
		}
		
		void ShowData()
		{
			cout << "num : " << num << endl;
		}
		
		Sosimple& AddNum(int n)
		{
			num += n;
			return *this;
		}
	};

	SoSimple SimpleFuncObj(SoSimple ob)
	{
		cout << "return ����" << endl;
		return ob;
	}

	int main(void)
	{
		SoSimple obj(7);
		SimpleFuncObj(obj).AddNum(30).ShowData();		// SimpleFuncObj �� obj ��ü�� ���ڷ� ���� - ob�� ���� ������ ȣ��
		obj.ShowData();
		return 0;
	}

���� ���
Called SoSimple(const So Simple& copy)
return ����
Called SoSimple(const So Simple& copy)
num: 37
num: 7
*/