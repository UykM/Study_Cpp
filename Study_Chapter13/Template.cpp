/*
* �Լ� ���ø� ����

template <typename T>			// template <class T>	typename�� class�� ���� �ǹ�
T �Լ��̸�(T num1, T num2)		// T�� �ڷ����� �������� �ʰڴٴ� �ǹ̷� ���
{								// T��� ���� ��ſ� �ٸ� ���� ��� ����
	return num1+num2;
}

�� Point! 
�Լ� ���ø��� �ϼ��� �Լ��� �ƴ϶� �ʿ��� �Լ����� �̾Ƴ��� ���� �Լ��� Ʋ�̶�� ����ϱ�
*/

/*
#include <iostream>
using namespace std;

template <typename T>			// �Լ� ���ø� : �Լ��� ����µ� ���Ǵ� ���ø�!
T Add(T num1, T num2)
{
	return num1 + num2;
}

int Add(int num1, int num2)		// �Ϲ� �Լ�
{
	cout << "Add(int num1, int num2)" << endl;
	return num1 + num2;
}

double Add(double num1, double num2)	// �Ϲ� �Լ�
{
	cout << "Add(double num1, double num2)" << endl;
	return num1 + num2;
}

int main(void)
{
	cout << Add(15, 20) << endl;				// �Ϲ��Լ� ȣ��
	cout << Add(2.9, 3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;			// �Ϲ��Լ��� ���ǵǾ��� ������, <int> ǥ�ø� ���ؼ� ������ �Լ��� ȣ���� ���
	cout << Add<double>(3.14, 2.75) << endl;	// �Ϲ��Լ��� ���ǵǾ����� �ʴٸ�, <double> ǥ�� ���� ���ø� �Լ� ȣ�� ����!
	return 0;
}

// ���ø� �Լ�	: �����Ϸ��� ����� ���� �Լ�, �� ���ø��� ������� ��������� �Լ�!
// int Add<int>(int num1, int num2)
// {
//		return num1+num2;
// }
// �Լ� ���ø��� ������ ��Ȳ���� �Ϲ��Լ����� �����ϴ� ���� �ٶ������� ����
// ���� �����Ϸ��� ���ؼ� ��������� ���ø� �Լ��� �Ϲ��Լ��� ���еȴٴ� ����� �����ֱ� ���� ���� ��

*/


/* �� �̻��� ��(Type)�� ���� ���ø� �����ϱ�
#include <iostream>
using namespace std;

template <class T1, class T2>
void ShowData(double num)			// �Ű����� ���� double�� ����Ǿ��ֱ� ������, ���޵Ǵ� ���ڸ� ���ؼ��� T1, T2�� �ڷ����� �������� ����.
{
cout << (T1)num << ", " << (T2)num << endl;
}

int main(void)
{
	ShowData<char, int>(65);		// ����, ��ó�� ���ø� �Լ��� ȣ�������� ������ ���缭 ȣ���ؾ���.
	ShowData<char, int>(67);		// ShowData(65);	�̷��� �����Ͽ� ȣ�� X
	ShowData<char, double>(68.9);	
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);
	return 0;
}
*/


// �Լ� ���ø��� Ư��ȭ
// ��Ȳ�� ���� ���ø� �Լ��� ��������� ���ܸ� �� �ʿ䰡 ����.
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template <>
char* Max(char* a, char* b)		// char* �� ���ø� �Լ��� �ʿ��� ��쿣, �� �Լ��� ������ ��. 
{
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template <>
const char* Max(const char* a, const char* b)		// const char* �� ���ø� �Լ��� �ʿ��� ��쿣, �� �Լ��� ������ ��.
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;				// char* Max(char*, char*) ���ø� �Լ��� ���ǵǾ� ���� �ʴٸ�, �ùٸ� ��� ��� X
	cout << Max(3.5, 7.5) << endl;	
	cout << Max("Simple", "Best") << endl;		// const char* Max(const char*, const char*) ���ø� �Լ��� ���ǵǾ� ���� �ʴٸ�, �ùٸ� ��� ��� X

	char str1[] = "Simeple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;
	return 0;
}