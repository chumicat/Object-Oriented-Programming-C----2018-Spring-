#include "Creatures.h"
#include <iostream>
#include <time.h>
using std::cout;
using std::endl;

int main()
{
	srand(time(NULL));
	Human h(30, 10);
	h.getDamage();
	cout << endl;

	Elf e;
	e.getDamage();
	cout << endl;

	Balrog b(50, 50);;
	b.getDamage();
	cout << endl;

	Cyberdemon c(30, 40);
	c.getDamage();
	cout << endl;
	system("pause");
	return 0;
}