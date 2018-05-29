/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID： B10332030
 * Date: May. 29, 2018
 * Last Update: May. 29, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 */
#include <iostream>
using std::cout;
using std::endl;

template <class T>
double absoluteValue(T a, T b) {
	return a - b >= 0 ? a - b : b - a;
}

int main() {
	//Variable declarations
	int i1, i2;
	double d1, d2;
	char c1, c2;

	i1 = 10; i2 = 20;
	cout << "Absolute value of 10,20 is " << absoluteValue(i1, i2) << endl;

	d1 = 5.5; d2 = 3.1;
	cout << "Absolute value of 5.5, 3.1 is " << absoluteValue(d1, d2) << endl;

	c1 = 'A', c2 = 'C';
	cout << "Absolute value of A, C is " << absoluteValue(c1, c2) << endl;
	system("pause");
	return 0;
}