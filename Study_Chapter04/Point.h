#pragma once

class Point
{
private:
	int x;
	int y;

public:
	bool InitMembers(int xpos, int ypos);
	int GetX() const;				// const 선언된 함수
	int GetY() const;				// const 선언된 함수
	bool SetX(int xpos);
	bool SetY(int ypos);
};

/*	const 함수  -  이 const 는 이 함수 내에선 멤버변수에 저장된 값을 변경하지 않겠다는 의미!
Example 1)

class SimpleClass
{
private:
	int num;

public:
	void InitNum(int n)
	{
		num = n;
	}
	int GetNum()		// const 선언이 추가되어야 아래의 컴파일 에러 소멸
						// 실제로 멤버변수의 값이 변경되지 않더라도,
						// const로 선언되지 않은 함수는 멤버변수의 값을 변경할 수 있는 능력을 가진 함수이기 때문에,
						// const가 아닌 함수의 호출 자체가 제한됨!
	{
		return num;
	}
	void ShowNum() const		// 여기서 const 선언이 됐기 때문에, 멤버변수인 num에 저장된 값을 변경하지 않겠다는 의미
	{
		cout << GetNUm() << endl;	// 컴파일 에러 발생
	}
};

Example 2)

class EasyClass
{
private:
	int num;
public:
	void InitNum(int n)
	{
		num = n;
	}
	int GetNum()		// const 선언이 추가되어야 아래의 컴파일 에러 소멸
	{
		return num;
	}
};

class LiveClass
{
private:
	int num;
public:
	void InitNum(const EasyClass &easy)		// 여기서 InitNum 함수의 매개변수 easy 는 'const 참조자' !
	{
		num = easy.GetNum();	// 컴파일 에러 발생 - 함수 GetNum 은 const 함수가 아니기 때문에,
													  const 참조자(easy)를 대상으로 
													  값의 변경 능력을 가진 함수(GetNum())의 호출을 허용하지 않는다
	}
};
*/