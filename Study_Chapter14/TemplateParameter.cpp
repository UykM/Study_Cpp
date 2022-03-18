#include <iostream>
using namespace std;

// template <typename T=int, int len=7>		// 함수의 매개변수에 디폴트 값의 지정이 가능하듯이, 템플릿 매개변수에도  Default Value 지정 가능!
template <typename T, int len>
class SimpleArray
{
private:
	T arr[len];
public:
	T& operator[] (int idx) { return arr[idx]; }
	SimpleArray<T, len>& operator=( const SimpleArray<T, len>&ref )
	{
		for (int i = 0; i < len; i++)
			arr[i] = ref.arr[i];
		return *this;
	}
};

int main(void)
{
	/* 
	// 템플릿 매개변수에 Default Value를 지정한 경우 
	SimpleArray<> arr;		// 템플릿 클래스의 객체생성을 의미하는 <> 기호는 반드시 추가해야 함.
	for(int i=0; i<7; i++)
		arr[i] = i+1;
	for(int i=0; i<7; i++)
		cout << arr[i] << " ";
	cout << endl;
	*/ 
	
	SimpleArray<int, 5> i5arr1;
	for (int i = 0; i < 5; i++)
		i5arr1[i] = i * 10;

	SimpleArray<int, 5> i5arr2;
	i5arr2 = i5arr1;			// i5arr1 = i7arr1; 처럼 길이가 다른 두 배열 객체간의 대입이 허용 X
	for (int i = 0; i < 5; i++)
		cout << i5arr2[i] << ", ";
	cout << endl;

	SimpleArray<int, 7> i7arr1;
	for (int i = 0; i < 7; i++)
		i7arr1[i] = i * 10;

	SimpleArray<int, 7> i7arr2;
	i7arr2 = i7arr1;
	for (int i = 0; i < 7; i++)
		cout << i7arr2[i] << ", ";
	cout << endl;
	return 0;
}