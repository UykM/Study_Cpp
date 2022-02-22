/*
protected �� ����� ����� ����ϴ� ������ ����
private < protected < public

class Base			// ���� Ŭ����
{
private:			// ���� Ŭ���������� ���� ����
	int num1;
protected:			// ���� Ŭ���������� ���� ����
	int num2;
public:
	int num3;
	void ShowData()
	{
		cout << num1 << ", " << num2 << ", " << num3;
	}
};

class Derived : public Base			// ���� Ŭ����
{
public:
	void ShowBaseMember()
	{
		cout << num1;	// ������ ����
		cout << num2;	// ������ OK!
		cout << num3;	// ������ OK!
	}
*/

/*
�� ���� ������ ���

class Base			
{
private:			
	int num1;
protected:			
	int num2;
public:
	int num3;
};

--------------------------------------------------------------------------------
class Derived : public Base			// private�� ������ protected, public �� �״�� ���
{									// �����ϸ� ����� �� public �� �̿���.
	........
}

--------------------------------------------------------------------------------
class Derived : protected Base		// protected ���� ���ٹ����� ���� ����� protected �� ������Ѽ� ���
{
���� �Ұ�:
	int num1;
protected:
	int num2;
protected:
	int num3;		// Base Ŭ����(���� Ŭ����)���� public���� ����� num3 ��
					// Base Ŭ������ protected�� ��ӹ��� Derived Ŭ����(���� Ŭ����)���� protected ����� ��.
					// int main(void)
					// {
					//		Derived drv;
					//		cout << drv.num3 << endl;		// ������ ����!
					//		return 0;
					// }
					// ���� num3 �� �ܺο��� ������ �Ұ����� ����� ��.
}

--------------------------------------------------------------------------------
class Derived : private Base	// private���� ������ ������ ���� ����� private ���� ������Ѽ� ���
{								// num2�� num3�� Derived Ŭ���� �������� ������ ������ ����� ��. (�� Ŭ������ �� ����� ��쿡�� ���� �Ұ���) 
���� �Ұ�:
	int num1;
private:
	int num2;
private:
	int num3;
}
*/