// �� ��ȯ �������� �����ε�
#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)	// ������
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	operator int()		// �� ��ȯ �������� �����ε�
						// �׸��� �� ��ȯ �����ڴ� ��ȯ���� ��� X
						// ȣ�� ������, 
						// operator+ �̸�, + �����ڰ� �������� �� ȣ��Ǵ� �Ͱ� �����ϰ�
						// int������ �� ��ȯ�ؾ� �ϴ� ��Ȳ���� ȣ��ȴٰ� ����!
	{
		return num;
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num1;
	num1 = 30;		// num=Number(30);				// �ӽð�ü�� ����
					// num.operator=(Number(30));	// �ӽð�ü�� ������� �ϴ� ���� �������� ȣ��
	
	// Number�� ��ü�� �;� �� ��ġ�� int�� �����Ͱ� �ͼ�, int�� �����͸� ���ڷ� ���޹޴� Number Ŭ������ ������ ȣ���� ���ؼ� Number�� �ӽð�ü�� ����
	// �׸��� �� Number ��ü�� ������� ���Կ��� ����
	num1.ShowNumber();

	// �ݴ�� ��ü�� �⺻ �ڷ��� �����ͷ� �� ��ȯ�� ������.
	// Number Ŭ������ ������� ������ ���� ���������� �����Ϸ���, 
	// Number Ŭ������ + �����ڸ� �����ε� �ϰ� �ְų�, num1�� int�� �����ͷ� ��ȯ �Ǿ�� ��.

	Number num2 = num1 + 20;	// num1 ��ü�� operator int �Լ��� ȣ��Ǿ�, �� �� ��ȯ�Ǵ� �� 30�� 20�� ���������� ����Ǹ�,
								// �� ������ ����� Number Ŭ������ �����ڰ� ȣ��ǰ� num2 ��ü�� ������.
	num2.ShowNumber();
	
	return 0;
}