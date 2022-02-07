#include <iostream>
using namespace std; // 헤더파일 <iostream>에 선언되어 있는 cin, cout, endl 등 이름공간 std에 선언되어있음
/*                      하지만 이 경우는 이름충돌이 일어날 가능성이 높아져서
*                       상황에 따라 잘 혼용하여 사용해야 함
 =  using std::cin;
    using std::cout;      // 범위지정 연산자 (::) -> namespace 을 지정할 때 쓰는 연산자
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

namespace Parent            // namespace의 중첩
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

int val = 100;      // 전역변수

int main(void)
{
    BestComImpl::SimpleFunc();

    cout << Parent::num << endl;            //namespace 의 중첩
    cout << Parent::SubOne::num << endl;
    cout << Parent::SubTwo::num << endl;

    int val = 20;   // 지역변수
    val += 3;       // 지역변수 val의 값 3 증가
    ::val += 7;     // 전역변수 val의 값 7 증가  /  범위지정 연산자(::)를 이용하여 전역변수 val에 접근

    return 0;
}

void BestComImpl::SimpleFunc(void)
{
    cout << "BestCom이 정의한 함수" << endl;
    PrettyFunc();                  // 동일 이름공간  :: 이름공간 명시할 필요 X
    ProgComImpl::SimpleFunc();    // 다른 이름공간
}

void BestComImpl::PrettyFunc(void)
{
    cout << "So Pretty!!" << endl;
}

void ProgComImpl::SimpleFunc(void)
{
    cout << "ProgCom이 정의한 함수 " << endl;
}

/*
* namespace의 별칭 지정
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
* 이 경우에
* namespace ABC=AAA:BBB:CCC
* cout << ABC::num << endl   일일히 입력하지 않고 별칭을 생성하여 출력 가능
*/
