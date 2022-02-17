// ������ ���ȭ �ϴ� const
// const int num = 10;

// ��ü�� ���ȭ �ϴ� const
// const SoSimple sim(20);

// ��ü�� const ������ �ٰ� �Ǹ�, "�� ��ü�� ������ ������ ������� �ʰڴ�."�� �ǹ�
// ���� �� ��ü�� ������δ� ���� �����ų �ɷ��� ���� const ����Լ��� ȣ���� ����
/* �̷��� const ��ü�� Ư���� Ȯ���� �� �ִ� ����
#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n);
	{ }
	SoSImple& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const
	{
		cout << "num: " << num << endl;
	}
};

int main(void)
{
	const SoSimple obj(7);
	// obj.AddNum(20);		// AddNum ����Լ��� const �Լ��� �ƴϱ� ������ ȣ�� �Ұ���
	obj.ShowData();
	return 0;
*/

/* const�� �Լ� �����ε�
* �Լ��� �����ε��� �����Ϸ���, �Ű������� ���� �ڷ����� �޶�� �ϴµ�
* ������ ���� const�� ���� ������ �Լ� �����ε��� ������ �� �� ����.
void SimpleFunc() { ... }
void SImpleFunc() const { ... }

* ���� ������ ���ؼ� �� �Լ��� � ��쿡 ȣ��Ǵ��� Ȯ��
#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n);
	{ }
	void SimplFunc()
	{
		 cout << "SimpleFunc: " << num << endl;
	}
	void SimpleFunc() const
	{	
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YourFunc(const SoSimple &obj)		// ���޵Ǵ� ���ڸ� const �����ڷ� �ް� ����.
{										
	obj.SimpleFunc();					// ���� const ����Լ��� SimpleFunc() const ȣ��
}

int main(void)
{
	SoSimple obj1(2);
	const SoSImple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();			// ��ü�� const �� ����ž��� ������ const ����Լ��� SimpleFunc() const �� ȣ��

	YourFunc(obj1);				// YourFunc �Լ��� ���޵Ǵ� ���ڸ� const �����ڷ� �ް� �ֱ� ������
	YourFunc(obj2);				// �Ѵ� const ����Լ��� SimpleFunc() const �� ȣ��
	return 0;
}

���� ���
SimpleFunc: 2
const SimpleFunc: 7
const SimpleFunc: 2
const SimpleFUnc: 7
*/