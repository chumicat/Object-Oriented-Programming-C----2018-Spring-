/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 26, 2018
 * Last Update: Apr. 26, 2018
 * Version: v1.0
 * Problem statement: Hungry Catpillar
 * Reference:
 */

#pragma once
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* dealing all caterpillar action */
class Caterpillar {
private:
	string body;
public:
	void eat();
	void pull();
	void throws();
	void consume();
	void sort();
	void show();
};