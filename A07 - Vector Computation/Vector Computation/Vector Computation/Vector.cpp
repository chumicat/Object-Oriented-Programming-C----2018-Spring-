/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 14, 2018
 * Last Update: Mar. 14, 2018
 * Version: v1.0
 * Problem statement: Vector Computation
 * Reference:
 */

#include "Vector.h"

Vector::Vector() : x(0.0), y(0.0) {}

Vector::Vector(double x, double y) :x(x), y(y) {}

Vector Vector::operator+(Vector v)
{
	return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(Vector v)
{
	return Vector(x - v.x, y - v.y);
}

double Vector::operator*(Vector v)
{
	return x*v.x + y*v.y;
}

Vector Vector::operator*(double d)
{
	return Vector(x*d, y*d);
}
