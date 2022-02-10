#include <iostream>
using namespace std;

class SinivelCap		// Äà¹° Ã³Ä¡¿ë Ä¸¼ú
{
public:
	void Take() const
	{
		cout << "Äà¹°ÀÌ ½Ï~ ³³´Ï´Ù." << endl;
	}
};

class SneezeCap			// ÀçÃ¤±â Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const
	{
		cout << "ÀçÃ¤±â°¡ ¸Ü½À´Ï´Ù." << endl;
	}
};

class SnuffleCap		// ÄÚ¸·Èû Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const
	{
		cout << "ÄÚ°¡ »½ ¶Õ¸³´Ï´Ù." << endl;
	}
};

class CONTAC600			// Ä¸½¶È­µÈ Å¬·¡½º
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const
	{
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient		// Ä¸½¶È­·Î °£°áÇØÁø °á°ú
{
public:
	void TakeCONTAC600(const CONTAC600& cap) const
	{
		cap.Take();
	}
};

int main(void)
{
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}