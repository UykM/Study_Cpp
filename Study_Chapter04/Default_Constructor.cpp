/*
디폴트 생성자(Default Constructor)
객체(Object) : 메모리 공간의 할당 이후에 반드시 하나의 생성자가 호출되어야 함.
이러한 기준에 예외를 두지 않기 위해, 
다음과 같이 생성자를 정의하지 않는 클래스에는 c++ 컴파일러에 의해서 Default Constructor 라는 것이 자동으로 삽입

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

다음과 같이 new를 이용한 객체의 생성에도 (Default) 생성자가 호출됨.

AAA * ptr = new AAA; 

*/

/*
생성자 불일치

class SoSimple	// 이와 같이 생성자가 정의되어 있는 클래스에는 Default Constructor 가 삽입되지 않음.
{
private:
	int num;
public:
	SoSimple(int n) : num(n) { }
};

따라서 다음의 형태로는 객체 생성 가능
SoSimple simObj1(10);					(0)
SoSimple * simPtr1 = new SoSimple(2);	(0)

불가능한 형태
SoSimple simObj2;					(X)
SoSImple * simPtr2 = new SoSimple;	(X)

이러한 형태로 객체가 생성 가능하려면, 다음과 같은 생성자를 추가해야 함.
SoSimple() : num(0) { }

*/

/* private 생성자
앞서 보인 생성자(Constructor)들은 객체의 생성이 클래스의 외부에서 진행되기 때문에 pulic으로 선언되었으나, 
클래스 내부에서 객체를 생성한다면, 생성자가 private으로 선언될 수 있음.
*/