/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 8, 2018
 * Last Update: March. 8, 2018
 * Version: v1.0
 * Problem statement: Triangle Area
 * Reference:
 */
#include <iostream>
#include <iomanip>
#include <cmath>

class Point {
public:
	float x, y;
	Point() {}
	Point(float ix, float iy) :x(ix), y(iy) {}
	float len(Point p) { return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2)); }
};

float triangleArea(Point p1, Point p2, Point p3) {
	float a = p1.len(p2);
	float b = p1.len(p3);
	float c = p2.len(p3);
	float s = (a + b + c) / 2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() 
{
	Point p1, p2, p3;
	while (std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y) {
		float area = triangleArea(p1, p2, p3);
		if (area < 0)
			std::cout << "Not a triangle" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(2) << area << std::endl;
	}
	return 0;
}