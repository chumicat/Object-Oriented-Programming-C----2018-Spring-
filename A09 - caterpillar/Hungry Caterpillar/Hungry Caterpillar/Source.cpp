/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 26, 2018
 * Last Update: Apr. 26, 2018
 * Version: v1.0
 * Problem statement: Hungry Catpillar
 * Reference:
 */

#include "caterpillar.h"

int main() {
	Caterpillar cat;

	/* Switch type to function */
	string type;
	while (cin >> type) {
		if (type == "EAT") {
			cat.eat();
		} else if (type == "PULL") {
			cat.pull();
		} else if (type == "THROW") {
			cat.throws();
		} else if (type == "CONSUME") {
			cat.consume();
		} else if (type == "SORT") {
			cat.sort();
		}
		cat.show();
	}
}