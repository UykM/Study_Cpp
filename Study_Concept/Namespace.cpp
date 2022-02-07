#include <iostream>
using namespace std; // ������� <iostream>�� ����Ǿ� �ִ� cin, cout, endl �� �̸����� std�� ����Ǿ�����
/*                      ������ �� ���� �̸��浹�� �Ͼ ���ɼ��� ��������
*                       ��Ȳ�� ���� �� ȥ���Ͽ� ����ؾ� ��
 =  using std::cin;
    using std::cout;      // �������� ������ (::) -> namespace �� ������ �� ���� ������
    using std::endl;
*/

namespace BestComImpl
{
    void SimpleFunc(void);
}

namespace BestComImpl
{
    void PrettyFunc(void);
}

namespace ProgComImpl
{
    void SimpleFunc(void);
}

namespace Parent            // namespace�� ��ø
{
    int num = 2;

    namespace SubOne
    {
        int num = 3;
    }

    namespace SubTwo
    {
        int num = 4;
    }
}

int val = 100;      // ��������

int main(void)
{
    BestComImpl::SimpleFunc();

    cout << Parent::num << endl;            //namespace �� ��ø
    cout << Parent::SubOne::num << endl;
    cout << Parent::SubTwo::num << endl;

    int val = 20;   // ��������
    val += 3;       // �������� val�� �� 3 ����
    ::val += 7;     // �������� val�� �� 7 ����  /  �������� ������(::)�� �̿��Ͽ� �������� val�� ����

    return 0;
}

void BestComImpl::SimpleFunc(void)
{
    cout << "BestCom�� ������ �Լ�" << endl;
    PrettyFunc();                  // ���� �̸�����  :: �̸����� ����� �ʿ� X
    ProgComImpl::SimpleFunc();    // �ٸ� �̸�����
}

void BestComImpl::PrettyFunc(void)
{
    cout << "So Pretty!!" << endl;
}

void ProgComImpl::SimpleFunc(void)
{
    cout << "ProgCom�� ������ �Լ� " << endl;
}

/*
* namespace�� ��Ī ����
*
*  namespace AAA
* {
*   namespace BBB
*   {
*       namespace CCC
*       {
*           int num1;
*           int num2;
*        }
*   }
* }
*
* �� ��쿡
* namespace ABC=AAA:BBB:CCC
* cout << ABC::num << endl   ������ �Է����� �ʰ� ��Ī�� �����Ͽ� ��� ����
*/
