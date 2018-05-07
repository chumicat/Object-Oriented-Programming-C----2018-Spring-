/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 29, 2018
 * Last Update: Mar. 29, 2018
 * Version: v1.0
 * Problem statement: Find Point
 * Reference:
 */

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include "point.h"
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::pair;
using std::vector;

class Shape {
public:
	virtual bool contained(const Point &p) {
		return 0;
	}
};

class Circle:public Shape {
private:
	Point center;
	double r;
public:
	Circle(double x, double y, double r) : center(x, y), r(r) {}
	virtual bool contained(const Point &p) override {
		return p.dist(center) <= r;
	}
};

class Rectangular:public Shape {
private:
	Point leftTop;
	Point rightBottom;
public:
	Rectangular(double x1, double y1, double x2, double y2) : leftTop(x1, y1), rightBottom(x2, y2) {}
	virtual bool contained(const Point &p) override {
		return	
			leftTop.x() <= p.x() &&
			p.x() <= rightBottom.x() &&
			leftTop.y() >= p.y() &&
			p.y() >= rightBottom.y();
	}
};

int main() {
	// save old buf and redirect
	//std::ifstream in("data.txt");
	//std::streambuf  *cinbuf = std::cin.rdbuf(in.rdbuf());

	// check if end
	int num;
	while (cin >> num) {
		// round variable
		vector<Shape*> vs;
		vector<Point> vp;

		// part a: get rectangular and circle
		for (int i = 0; i < num; i++) {
			char type;
			double x1, y1, x2, y2, r;
			cin >> type;
			if (type == 'r') {
				cin >> x1 >> y1 >> x2 >> y2;
				vs.push_back(new Rectangular(x1, y1, x2, y2));
			} else if (type == 'c') {
				cin >> x1 >> y1 >> r;
				vs.push_back(new Circle(x1, y1, r));
			} else {
				throw;
			}
		}

		// part b: get point
		cin >> num;
		for (int i = 0; i < num; i++) {
			double x, y;
			cin >> x >> y;
			vp.emplace_back(x, y);
		}

		// show
		for (Point &p : vp) {
			bool dirty = false;
			for (int i = 0; i < vs.size(); i++) {
				if (vs[i]->contained(p)) {
					dirty = true;
					cout << "Point (" << p.x() << ", " << p.y()
					<< ") is contained in figure " << i + 1 << endl;
				}
			}
			if(!dirty)
				cout << "Point (" << p.x() << ", " << p.y()
				<< ") is not contained in any figure" << endl;
		}
	}

	// reset to standard input again
	//std::cin.rdbuf(cinbuf);
}