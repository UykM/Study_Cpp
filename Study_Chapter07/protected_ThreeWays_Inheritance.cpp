/*
protected 로 선언된 멤버가 허용하는 접근의 범위
private < protected < public

class Base			// 기초 클래스
{
private:			// 기초 클래스에서만 접근 가능
	int num1;
protected:			// 유도 클래스에서도 접근 가능
	int num2;
public:
	int num3;
	void ShowData()
	{
		cout << num1 << ", " << num2 << ", " << num3;
	}
};

class Derived : public Base			// 유도 클래스
{
public:
	void ShowBaseMember()
	{
		cout << num1;	// 컴파일 에러
		cout << num2;	// 컴파일 OK!
		cout << num3;	// 컴파일 OK!
	}
*/

/*
세 가지 형태의 상속

class Base			
{
private:			
	int num1;
protected:			
	int num2;
public:
	int num3;
};

--------------------------------------------------------------------------------
class Derived : public Base			// private을 제외한 protected, public 은 그대로 상속
{									// 웬만하면 상속할 때 public 을 이용함.
	........
}

--------------------------------------------------------------------------------
class Derived : protected Base		// protected 보다 접근범위가 넓은 멤버는 protected 로 변경시켜서 상속
{
접근 불가:
	int num1;
protected:
	int num2;
protected:
	int num3;		// Base 클래스(기초 클래스)에선 public으로 선언된 num3 이
					// Base 클래스를 protected로 상속받은 Derived 클래스(유도 클래스)에선 protected 멤버가 됨.
					// int main(void)
					// {
					//		Derived drv;
					//		cout << drv.num3 << endl;		// 컴파일 에러!
					//		return 0;
					// }
					// 따라서 num3 는 외부에서 접근이 불가능한 멤버가 됨.
}

--------------------------------------------------------------------------------
class Derived : private Base	// private보다 접근의 범위가 넓은 멤버는 private 으로 변경시켜서 상속
{								// num2와 num3은 Derived 클래스 내에서만 접근이 가능한 멤버가 됨. (이 클래스를 또 상속한 경우에도 접근 불가능) 
접근 불가:
	int num1;
private:
	int num2;
private:
	int num3;
}
*/