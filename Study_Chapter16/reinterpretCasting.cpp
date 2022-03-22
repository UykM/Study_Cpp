//	reinterpret_cast<T>(expr)
//	���� ����� ���� �ڷ��������� �� ��ȯ�� ����� ��.
/*	���� ���� ������� Ŭ������ ������� ������ ���� �ڵ带 �ۼ��� �� ����.
class SimpleCar { ... };
class BestFriend { ... };

int main(void)
{
	SimpleCar* car = new Car;
	BestFriend* fren = reinterpret_cast<BestFriend*>(car);
}
*/
// ��, reinterpret_cast �����ڴ� �����͸� ������� �ϴ�, �׸��� �����Ϳ� ������ �ִ� ��� ������ �� ��ȯ�� �����.
/*
int main(void)
{
	int num = 72;
	int* ptr = &num;

	int adr = reinterpret_cast<int>(ptr);		// �ּ� ���� ������ ��ȯ
	cout << "Addr: " << adr << endl;			// �ּ� �� ���

	int* rptr = reinterpret_cast<int*>(adr);	// ������ �ٽ� �ּ� ������ ��ȯ
	cout << "value: " << *rptr << endl;			// �ּ� ���� ����� ���� ���
}
*/

// reinterpret_cast �����ڰ� �ǹ��ְ� ���̴� ����� ����
#include <iostream>
using namespace std;

int main(void)
{
	int num = 0x010203;
	char* ptr = reinterpret_cast<char*>(&num);		// int�� ������ ����Ʈ ���� ������ ���� int�� �����͸� char�� �����ͷ� ��ȯ

	for (int i = 0; i < sizeof(num); i++)
		cout << static_cast<int>(*(ptr + i)) << endl;
}