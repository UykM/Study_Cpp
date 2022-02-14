#include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "��ü ����" << endl;
	}
	
	SelfRef& Adder(int n)		// ��ȯ���� ������
	{
		num += n;
		return *this;			// ��ü ������, �� ��ü�� �������� ��ȯ��.
	}
	
	SelfRef& ShowTwoNumber()		// ��ȯ���� ������
	{
		cout << num << endl;
		return *this;				// this�� �ڱ� �ڽ��� ����Ű�� Ű����(�ּҰ�),  *this �� �ڱ� �ڽ��� ��
	}
};

int main(void)
{
	SelfRef obj(3);					// ��ü obj ���� ��, 3���� �ʱ�ȭ
	SelfRef& ref = obj.Adder(2);	// ������(&)�� �޾ұ� ������, ������ ref�� ��ü obj�� �����ϰ� ��.
									// ����, ��ü obj�� ��ü ref�� ���� �޸��� ��ġ�� ����.

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
	// obj. ShowTwoNumber();  =>  ��ü obj�� ��ü ref�� ���� �޸��� ��ġ�� �ֱ� ������, 8�� ���

	return 0;
}