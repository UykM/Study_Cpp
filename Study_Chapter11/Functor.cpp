// Funtor 는 함수 또는 객체의 동작방식에 유연함을 제공할 때 주로 사용됨.

#include <iostream>
using namespace std;

class SortRule		
{
public:
	virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule		// 오름차순
											// Functor로 정의된 클래스
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 > num2) { return true; }
		else { return false; }
	}
};

class DescendingSort : public SortRule		// 내림차순
											// Functor로 정의된 클래스
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 < num2) return true;
		else return false;
	}
};

class DataStorage		// int형 정수의 저장소
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
			cout << "더 이상 저장이 불가능합니다." << endl;
			return;
		}
		arr[idx++] = num;
	}
	void ShowAllData()
	{
		for (int i = 0; i < idx; i++) cout << arr[i] << ' ';
		cout << endl;
	}
	void SortData(const SortRule& functor)		// 버블정렬 알고리즘 사용 
												// 매개변수 형이 SortRule 의 참조형이므로, SortRule 클래스를 상속하는 
												// AscendingSort 클래스와 DescendingSort 클래스의 객체는 인자로 전달 가능.
												// 그리고 SortRule 클래스의 operator() 함수는 virtual로 선언되어, 유도 클래스의 operator() 함수가 대신 호출
												// 때문에 펑터(Functor)로 무엇이 전달되느냐에 따라서 정렬의 기준이 바뀜.
												// 이것이 Functor를 정의하는 이유!
	{											
		for (int i = 0; i < (idx - 1); i++)		
		{
			for (int j = 0; j < (idx - 1) - i; j++)
			{
				if (functor(arr[j], arr[j + 1]))	// functor의 함수호출 결과를 통해 정렬이 진행
				{									// 즉, functor가 true를 반환하는 조건에 따라서 정렬의 방식이 달라짐.
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