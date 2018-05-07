/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 14, 2018
 * Last Update: Mar. 14, 2018
 * Version: v1.0
 * Problem statement: Vector Computation
 * Reference:
 */

#pragma once
class Vector {
public:
	double x, y;
	Vector();
	Vector(double x, double y);
	Vector operator+(Vector v);
	Vector operator-(Vector v);
	double operator*(Vector v);
	Vector operator*(double d);
};