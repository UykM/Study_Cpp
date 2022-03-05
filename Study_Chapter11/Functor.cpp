// Funtor �� �Լ� �Ǵ� ��ü�� ���۹�Ŀ� �������� ������ �� �ַ� ����.

#include <iostream>
using namespace std;

class SortRule		
{
public:
	virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule		// ��������
											// Functor�� ���ǵ� Ŭ����
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 > num2) { return true; }
		else { return false; }
	}
};

class DescendingSort : public SortRule		// ��������
											// Functor�� ���ǵ� Ŭ����
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 < num2) return true;
		else return false;
	}
};

class DataStorage		// int�� ������ �����
{
private:
	int* arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) :idx(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void AddData(int num)
	{
		if (MAX_LEN <= idx)
		{
			cout << "�� �̻� ������ �Ұ����մϴ�." << endl;
			return;
		}
		arr[idx++] = num;
	}
	void ShowAllData()
	{
		for (int i = 0; i < idx; i++) cout << arr[i] << ' ';
		cout << endl;
	}
	void SortData(const SortRule& functor)		// �������� �˰��� ��� 
												// �Ű����� ���� SortRule �� �������̹Ƿ�, SortRule Ŭ������ ����ϴ� 
												// AscendingSort Ŭ������ DescendingSort Ŭ������ ��ü�� ���ڷ� ���� ����.
												// �׸��� SortRule Ŭ������ operator() �Լ��� virtual�� ����Ǿ�, ���� Ŭ������ operator() �Լ��� ��� ȣ��
												// ������ ����(Functor)�� ������ ���޵Ǵ��Ŀ� ���� ������ ������ �ٲ�.
												// �̰��� Functor�� �����ϴ� ����!
	{											
		for (int i = 0; i < (idx - 1); i++)		
		{
			for (int j = 0; j < (idx - 1) - i; j++)
			{
				if (functor(arr[j], arr[j + 1]))	// functor�� �Լ�ȣ�� ����� ���� ������ ����
				{									// ��, functor�� true�� ��ȯ�ϴ� ���ǿ� ���� ������ ����� �޶���.
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

int main(void)
{
	DataStorage storage(5);
	storage.AddData(40);
	storage.AddData(30);
	storage.AddData(50);
	storage.AddData(20);
	storage.AddData(10);

	storage.SortData(AscendingSort());
	storage.ShowAllData();

	storage.SortData(DescendingSort());
	storage.ShowAllData();
	return 0;
}