/*
����Ʈ ������(Default Constructor)
��ü(Object) : �޸� ������ �Ҵ� ���Ŀ� �ݵ�� �ϳ��� �����ڰ� ȣ��Ǿ�� ��.
�̷��� ���ؿ� ���ܸ� ���� �ʱ� ����, 
������ ���� �����ڸ� �������� �ʴ� Ŭ�������� c++ �����Ϸ��� ���ؼ� Default Constructor ��� ���� �ڵ����� ����

class AAA
{
private:
	int num;
public:
	AAA() { } // Default Constructor
	int GetNum
	{
		return num;
	}
};

������ ���� new�� �̿��� ��ü�� �������� (Default) �����ڰ� ȣ���.

AAA * ptr = new AAA; 

*/

/*
������ ����ġ

class SoSimple	// �̿� ���� �����ڰ� ���ǵǾ� �ִ� Ŭ�������� Default Constructor �� ���Ե��� ����.
{
private:
	int num;
public:
	SoSimple(int n) : num(n) { }
};

���� ������ ���·δ� ��ü ���� ����
SoSimple simObj1(10);					(0)
SoSimple * simPtr1 = new SoSimple(2);	(0)

�Ұ����� ����
SoSimple simObj2;					(X)
SoSImple * simPtr2 = new SoSimple;	(X)

�̷��� ���·� ��ü�� ���� �����Ϸ���, ������ ���� �����ڸ� �߰��ؾ� ��.
SoSimple() : num(0) { }

*/

/* private ������
�ռ� ���� ������(Constructor)���� ��ü�� ������ Ŭ������ �ܺο��� ����Ǳ� ������ pulic���� ����Ǿ�����, 
Ŭ���� ���ο��� ��ü�� �����Ѵٸ�, �����ڰ� private���� ����� �� ����.
*/