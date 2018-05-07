/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 12, 2018
 * Last Update: Apr. 12, 2018
 * Version: v1.0
 * Problem statement: Rect
 * Reference:
 */
#include "Rect.h"

Rect::Rect() : x(0), y(0), width(0), height(0) {}

Rect::Rect(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

Rect Rect::operator+(const Rect & r)
{
	int x_min = min(x_min(*this), x_min(r));
	int x_max = max(x_max(*this), x_max(r));
	int y_max = max(y_max(*this), y_max(r));
	int y_min = min(y_min(*this), y_min(r));

	return Rect(x_min, y_max, x_max - x_min, y_max - y_min);
}

Rect Rect::operator*(const Rect & r)
{
	int x_min = max(x_min(*this), x_min(r));
	int x_max = min(x_max(*this), x_max(r));
	int y_max = min(y_max(*this), y_max(r));
	int y_min = max(y_min(*this), y_min(r));

	if (x_min <= x_max && y_min <= y_max) {
		return Rect(x_min, y_max, x_max - x_min, y_max - y_min);
	} else {
		cout << "Not overlapping\n";
		return Rect();
	}
}

string Rect::toString()
{
	return 
		"( " + to_string(x) + " , " + to_string(y) + 
		" , " + to_string(width) + " , " + to_string(height) + " )";
}
