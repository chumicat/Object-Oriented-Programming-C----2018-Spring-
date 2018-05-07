/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 7, 2018
 * Last Update: Mar. 7, 2018
 * Version: v1.0
 * Problem statement: Class Point in plane
 * Reference:
 */

#include <iostream>
using std::cout;
using std::endl;

class Point {
private:
	double x;
	double y;

public:
	/* Constructor */
	Point() {}
	Point(double px, double py) : x(px), y(py){}

	/* Get and set function */
	void set(double px, double py) {
		x = px;
		y = py;
	}
	double retrieveVertical() {
		return x;
	}
	double retrieveHorizontal() {
		return y;
	}

	/* moving function */
	void move(double px, double py) {
		x += px;
		y += py;
	}
	void rotate() {
		/* Rotate 90 degree clockwise */
		int tmp = -x;
		x = y;
		y = tmp;
	}

};

// input-main1.cpp
int main(void) {
	Point point;

	point.set(0, 5);
	cout << point.retrieveVertical() << " " << point.retrieveHorizontal() << endl;

	point.move(1, 2);
	cout << point.retrieveVertical() << " " << point.retrieveHorizontal() << endl;
	for (int i = 0; i < 4; i++) {
		point.rotate();
		cout << point.retrieveVertical() << " " << point.retrieveHorizontal() << endl;
	}

	return 0;
}

// input-main2.cpp
//int main(void) {
//	Point A, B, C;
//
//	A.set(5, -20);
//	cout << A.retrieveVertical() << " " << A.retrieveHorizontal() << endl;
//
//	B.set(3, -2);
//	cout << B.retrieveVertical() << " " << B.retrieveHorizontal() << endl;
//
//	B.move(1, 2);
//	cout << B.retrieveVertical() << " " << B.retrieveHorizontal() << endl;
//
//	C.set(5, 25);
//	cout << C.retrieveVertical() << " " << C.retrieveHorizontal() << endl;
//	C.move(3, -15);
//	cout << C.retrieveVertical() << " " << C.retrieveHorizontal() << endl;
//
//	for (int i = 0; i < 4; i++) {
//		C.rotate();
//		cout << C.retrieveVertical() << " " << C.retrieveHorizontal() << endl;
//	}
//	return 0;
//}