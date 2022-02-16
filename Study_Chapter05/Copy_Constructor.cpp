#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)					
		: num1(n1), num2(n2)
	{
		// empty
	}
	
	SoSimple(const SoSimple& copy)				// 복사 생성자 (참조형의 선언을 의미하는 & 은 반드시 삽입해야 함.)
												// 이 복사 생성자에 해당하는 코드가 생략되더라도 디폴트 복사 생성자가 자동으로 삽입되기 때문에 굳이 복사 생성자를 직접 정의할 필요 X
												// 하지만, 반드시 복사 생성자를 정의해야 하는 경우도 있음.
												// 멤버 대 멤버의 복사에 사용되는 원본을 변경시키는 것은 복사의 개념을 무너뜨리는 행위이기에, 키워드 const 를 삽입해서 실수를 방지함.
		: num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1;			// 복사 생성자 호출
									// SoSimple sime2(sim1); 으로 묵시적 변환
									// 이와 같은 묵시적인 변환을 허용하지 않는다면,
									// 복사 생성자 SoSimple 에 키워드 explicit 를 선언.
									// explicit SoSimple(const SoSimple &copy)4
									//				:: num1(copy.num1), num2(copy.num2)
									// { }
									// 이렇게 explicit 이 선언되면 SoSimple sim2(sim1) 와 같은 형태로 객체를 생성할 수밖에 없음.
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();
	return 0;
}


/* 위와 같은 멤버 대 멤버의 복사를 얕은 복사(shallow copy) 라 함. 다음 예제는 얕은 복사를 했을 때 발생하는 문제임.
#include <iostream>
#include <cstirng>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("신 민 규", 22);
	Person man2 = man1;				// 얕은 복사(shallow copy), 복사 생성자(생략된 디폴트 생성자) 호출
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}

실행결과

이름: 신 민 규
나이: 22
이름: 신민규
나이: 22
called destructor!

실행결과로부터 알 수 있는 문제는 "called destructor!" 이 한 번만 출력되었다는 점.
즉, 소멸자가 한 번만 호출됐다는 것임.
디폴트 복사 생성자는 멤버 대 멤버의 단순 복사를 진행하기 떄문에
위와 같은 경우엔 두 개의 객체(man1, man2)가 하나의 문자열을 동시에 참조하는 현상이 발생한 것.
따라서, man2 객체가 먼저 소멸된 상황을 가정하면,
man2의 소멸자가 호출되면서 man2 객체가 참조하고 있던 문자열도 같이 소멸됨.
이어서 남아있는 man1 객체이 소멸자도 실행되어야 하는데, man1 객체가 참조하는 문자열은 이미 man2 객체와 함께 소멸된 상태이기 때문에,
이미 지워진 문자열을 대상으로 delete 연산을 하기 때문에 문제가 발생.
*/


/* 위와 같은 문제를 해결하기 위해 깊은 복사(deep copy)를 이용함.
깊은 복사(deep copy) : 값을 복사할 때 메모리를 넘기는 방식(얕은 복사)이 아닌 값만 넘기고 메모리는 새롭게 만드는 방식
- 객체 별로 각각 문자열을 참조함. 멤버뿐만 아니라, 포인터로 참조하는 대상까지 깊게 복사한다는 의미.
따라서 위의 코드에 다음 생성자 코드만 추가하면 문제가 해결됨.
Person(const Person &copy) : age(copy.age}
{
	name = new char[strlen(copy.name)+1];		// 복사할 때, new로 새로운 메모리의 공간을 할당하기 때문에 위와 같은 문제 발생 X
	strcpy(name, copy.name);
}
*/



/* 복사 생성자가 호출되는 시점

Case 1: 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우(앞서 보인 경우)
ex) Person man1("신 민 규", 22);
	Person man2 = man1;


Case 2: Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
ex) class SoSimple
	{
	private:
		int num;
	public:
		SoSimple(int n) : num(n)
		{ }
		SoSimple(const SoSimple & copy) : num(copy.num)
		{
			cout << "Called SoSimple(const SoSimple& copyt)" << endl;
		}
		void ShowData()
		{
			cout << "num : " << num << endl;
		}
	};

	void SimpleFuncObj(SoSimple ob)			// main 함수에서 인자(obj 객체)를 전달 받음, 값을 전달 받았기 때문에 Call-by-value 방식
	{
		ob.ShowData();
	}

	int main(void)
	{
		SoSimple obj(7);
		cout << "함수 호출 전" << endl;
		SimpleFuncObj(obj);					// SimpleFuncObj 로 obj 객체를 인자로 전달 - 복사 생성자 호출
		cout << "함수 호출 후" << endl;
		return 0;
	}

Case 3: 객체를 반환하되, 참조형으로 반환하지 않는 경우
ex) class SoSimple
	{
	private:
		int num;
	public:
		SoSimple(int n) : num(n)
		{ }
		
		SoSimple(const SoSimple & copy) : num(copy.num)
		{
			cout << "Called SoSimple(const SoSimple& copyt)" << endl;
		}
		
		void ShowData()
		{
			cout << "num : " << num << endl;
		}
		
		Sosimple& AddNum(int n)
		{
			num += n;
			return *this;
		}
	};

	SoSimple SimpleFuncObj(SoSimple ob)
	{
		cout << "return 이전" << endl;
		return ob;							// 반환형이 참조형( Simple &SimpleFunObj(SoSimple ob) )이 아니므로 ob 객체의 복사본(임시객체)이 만들어지면서 반환이 진행
	}

	int main(void)
	{
		SoSimple obj(7);		
		SimpleFuncObj(obj).AddNum(30).ShowData();		// SimpleFunObj(obj) -> 첫 번째 복사 생성자 호출 : SimpleFuncObj(SoSimple ob) 로 obj 객체를 인자로 전달 - ob 객체의 복사 생성자 호출
														// return ob;        -> 두 번째 복사 생성자 호출 : ob 객체를 반환하게 되면, '임시객체'라는 것이 생성되고, 이 임시객체를 대상으로 AddNum 함수, ShowData 함수 호출
		obj.ShowData();
		return 0;
	}

실행 결과
Called SoSimple(const So Simple& copy)
return 이전
Called SoSimple(const So Simple& copy)
num: 37
num: 7
*/


/* 임시객체
* 다음 행으로 넘어가면 바로 소멸
* 참조자에 참조되는 임시객체는 바로 소멸 X

#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create objL " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy objL " << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main(void)
{
	Temporary(100);										// 100으로 초기화된 Temporary 임시객체 생성
														// Temporary temp(100); 인 경우엔 임시객체 생성 X
	cout << "********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();						// 
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);
	cout << "********** end of main!" << endl << endl;
	return 0;
}

실행결과
create obj: 100
destroy obj: 100
********** after make!

create obj: 200
My num is 200
destroy obj: 200
********** after make!

create obj: 300
********** end of main!

 destroy obj: 300
*/

/* 객체의 생성과 소멸 이해
 
#include <iostrema>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "New Object: " << this << endl;
	}
	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "New Copy obj: " << this << endl;
	}
	~SoSimple()
	{
		cout << "Destroy obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)			// main 함수에서 obj 객체를 인자(매개변수 ob) 로 전달받음.
{											// Case 2: Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우, 복사 생성자( SoSimple(const SoSimple& copy) ) 호출
	cout << "Parm ADR: " << &ob << endl;
	return ob;								// ob 객체의 값 자체 반환
											// Case 3 : ob 객체의 값 자체을 반환하기 때문에, 임시객체가 생성된 후, 복사 생성자( SoSimple(const SoSimple& copy) )  호출
}

int main(void)
{
	SoSimple obj(7);
	Simple FuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);	// 반환되는 임시객체에 tempRef 라는 이름을 할당하고 있음. - temRef 라는 새로운 객체를 생성한 것이 아님!
	cout << "Return Obj " << &tempRef << endl;
	return 0;
}


실행결과
New Object: 주소 A				// SoSimple obj(7);에 의해서 obj 객체 생성 
New Copy obj: 주소 B			// Simple FuncObj(obj); 함수호출로 인한 매개변수 ob 의  생성
Parm ADR: 주소 B				// 생성된 매개변수 ob(객체) 의 주소 출력
New Copy obj: 주소 C			// -> 임시객체의 주소 / return ob; 를 보면 ob 객체의 값 자체을 반환하기 때문에, 임시객체가 생성된 후, 복사 생성자( SoSimple(const SoSimple& copy) )  호출
Destroy obj: 주소 B				// 매개변수 ob의 소멸
Destroy obj: 주소 C				// 임시객체의 소멸

New Copy obj; 주소 B			// Simple FuncObj(obj); 함수호출로 인한 매개변수 ob 의 생성
Parm ADR: 주소 B				// 생성된 매개변수 ob(객체) 의 주소 출력
New Copy obj: 주소 C			// -> 임시객체의 주소 / return ob; 를 보면 ob 객체의 값 자체을 반환하기 때문에, 임시객체가 생성된 후, 복사 생성자( SoSimple(const SoSimple& copy) )  호출
Destroy ofj: 주소 B				// 매개변수 ob의 소멸
Return Obj	주소 C				// temRef 가 임시객체를 참조하기 때문에 같은 주소	/	참조자에 의해 참조되는 임시객체는 즉시 소멸 X
Destroy obj: 주소 C				// temRef가 참조하는 임시객체 소멸
Destroy obj: 주소 A				// 마지막으로 남겨진 obj 객체 소멸
*/