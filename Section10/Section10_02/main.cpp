#include <iostream>
#include "monster.h"

using namespace std;

/* Section10_02 ���� ���� */


int main()
{
	Monster mon1("Sanson", position2D(0,0));
	cout << mon1 << endl;
	Monster mon2("Parsival", position2D(0, 0));
	cout << mon2 << endl;

	mon1.moveTo(position2D(1,1));
	cout << mon1 << endl;

	return 0;
}