#pragma once

class Point
{
private:
	int x;
	int y;

public:
	bool InitMembers(int xpos, int ypos);
	int GetX() const;				// const ����� �Լ�
	int GetY() const;				// const ����� �Լ�
	bool SetX(int xpos);
	bool SetY(int ypos);
};

/*	const �Լ�  -  �� const �� �� �Լ� ������ ��������� ����� ���� �������� �ʰڴٴ� �ǹ�!
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
	int GetNum()		// const ������ �߰��Ǿ�� �Ʒ��� ������ ���� �Ҹ�
						// ������ ��������� ���� ������� �ʴ���,
						// const�� ������� ���� �Լ��� ��������� ���� ������ �� �ִ� �ɷ��� ���� �Լ��̱� ������,
						// const�� �ƴ� �Լ��� ȣ�� ��ü�� ���ѵ�!
	{
		return num;
	}
	void ShowNum() const		// ���⼭ const ������ �Ʊ� ������, ��������� num�� ����� ���� �������� �ʰڴٴ� �ǹ�
	{
		cout << GetNUm() << endl;	// ������ ���� �߻�
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
	int GetNum()		// const ������ �߰��Ǿ�� �Ʒ��� ������ ���� �Ҹ�
	{
		return num;
	}
};

class LiveClass
{
private:
	int num;
public:
	void InitNum(const EasyClass &easy)		// ���⼭ InitNum �Լ��� �Ű����� easy �� 'const ������' !
	{
		num = easy.GetNum();	// ������ ���� �߻� - �Լ� GetNum �� const �Լ��� �ƴϱ� ������,
													  const ������(easy)�� ������� 
													  ���� ���� �ɷ��� ���� �Լ�(GetNum())�� ȣ���� ������� �ʴ´�
	}
};
*/