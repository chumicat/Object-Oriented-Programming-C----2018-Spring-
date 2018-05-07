/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 12, 2018
 * Last Update: Apr. 12, 2018
 * Version: v1.0
 * Problem statement: Rect
 * Reference:
 */
#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#define x_min(a) (a).x
#define x_max(a) (a).x + (a).width
#define y_max(a) (a).y
#define y_min(a) (a).y - (a).height
using std::cout;
using std::max;
using std::min;
using std::string;
using std::to_string;

class Rect {
public:
	int x, y, width, height;
public:
	Rect();
	Rect(int x, int y, int width, int height);
	Rect operator+(const Rect &r);
	Rect operator*(const Rect &r);
	string toString();
};