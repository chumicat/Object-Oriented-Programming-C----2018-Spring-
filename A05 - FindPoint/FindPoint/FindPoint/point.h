/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: Mar. 29, 2018
* Last Update: Mar. 29, 2018
* Version: v1.0
* Problem statement: Find Point
* Reference:
http://sandbox.mc.edu/~bennet/cs220/codeex/cl0_cc.html
*/

#pragma once
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>

using namespace std;

// Class to represent points.
class Point {
private:
	double xval, yval;
public:
	// Constructor uses default arguments to allow calling with zero, one,
	// or two values.
	Point(double x = 0.0, double y = 0.0) {
		xval = x;
		yval = y;
	}

	// Extractors.
	double x()const { return xval; }
	double y()const { return yval; }

	// Distance to another point.  Pythagorean thm.
	double dist(const Point &other) const {
		double xd = xval - other.xval;
		double yd = yval - other.yval;
		return sqrt(xd*xd + yd*yd);
	}

	// Add or subtract two points.
	Point add(Point b)
	{
		return Point(xval + b.xval, yval + b.yval);
	}
	Point sub(Point b)
	{
		return Point(xval - b.xval, yval - b.yval);
	}

	// Move the existing point.
	void move(double a, double b)
	{
		xval += a;
		yval += b;
	}

	// Print the point on the stream.  The class ostream is a base class
	// for output streams of various types.
	void print(ostream &strm)
	{
		strm << "(" << xval << "," << yval << ")";
	}
};

// Print a line of the form x op y = z, where x, y, and z are points. 
void prline(ostream &strm, Point x, char *op, Point y, Point z)
{
	x.print(strm);
	cout << " " << op << " ";
	y.print(strm);
	cout << " = ";
	z.print(strm);
	cout << endl;
}

#endif POINT_H