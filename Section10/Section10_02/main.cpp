#include <iostream>
#include "monster.h"

using namespace std;

/* Section10_02 구성 관계 */


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