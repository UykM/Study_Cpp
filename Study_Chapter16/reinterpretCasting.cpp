//	reinterpret_cast<T>(expr)
//	전혀 상관이 없는 자료형으로의 형 변환에 사용이 됨.
/*	서로 전혀 상관없는 클래스들 대상으로 다음과 같은 코드를 작성할 때 사용됨.
class SimpleCar { ... };
class BestFriend { ... };

int main(void)
{
	SimpleCar* car = new Car;
	BestFriend* fren = reinterpret_cast<BestFriend*>(car);
}
*/
// 즉, reinterpret_cast 연산자는 포인터를 대상으로 하는, 그리고 포인터와 관련이 있는 모든 유형의 형 변환을 허용함.
/*
int main(void)
{
	int num = 72;
	int* ptr = &num;

	int adr = reinterpret_cast<int>(ptr);		// 주소 값을 정수로 변환
	cout << "Addr: " << adr << endl;			// 주소 값 출력

	int* rptr = reinterpret_cast<int*>(adr);	// 정수를 다시 주소 값으로 변환
	cout << "value: " << *rptr << endl;			// 주소 값에 저장된 정수 출력
}
*/

// reinterpret_cast 연산자가 의미있게 쓰이는 경우의 예제
#include <iostream>
using namespace std;

int main(void)
{
	int num = 0x010203;
	char* ptr = reinterpret_cast<char*>(&num);		// int형 정수에 바이트 단위 접근을 위해 int형 포인터를 char형 포인터로 변환

	for (int i = 0; i < sizeof(num); i++)
		cout << static_cast<int>(*(ptr + i)) << endl;
}