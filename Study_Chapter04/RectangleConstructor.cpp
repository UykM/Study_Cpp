#include <iostream>
#include "Point_Constructor.h"
#include "Rectangle_Constructor.h"
using namespace std;

int main(void)
{
	Rectangle rec(1, 1, 5, 5);
	rec.ShowRecInfo();
	return 0;
}