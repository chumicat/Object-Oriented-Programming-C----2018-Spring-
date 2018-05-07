/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: Mar. 7, 2018
* Last Update: Mar. 7, 2018
* Version: v1.0
* Problem statement: Fraction
* Reference:
https://openhome.cc/Gossip/AlgorithmGossip/GCDPNumber.htm#C1
*/

#include <iostream>
using std::cout;
using std::endl;

class Fraction {
private:
	int numerator;
	int denominator;
	/* calculate greatest common divisor */
	int gcd(int m, int n) {
		while (n != 0) {
			int r = m % n;
			m = n;
			n = r;
		}
		return m;
	}
public:
	/* Constructior */
	Fraction() {}
	Fraction(int n, int d) : numerator(n), denominator(d) {}

	/* Set and get function */
	void setNumerator(int n) { numerator = n; }
	void setDenominator(int d) { denominator = d; }

	/* Get value */
	double getDouble() { return numerator / (double)denominator; }
	void outputReducedFraction() { 
		int gcdf = gcd(numerator, denominator);
		if (denominator / gcdf == 1)
			cout << numerator / gcdf;
		else
			cout << numerator / gcdf << "/" << denominator/gcdf;
	}
};


//input-main1.cpp
int main()
{
	Fraction f1, f2;
	f1.setNumerator(4);
	f1.setDenominator(2);
	cout << f1.getDouble() << endl;
	f1.outputReducedFraction();
	cout << endl;

	f2.setNumerator(20);
	f2.setDenominator(60);
	cout << f2.getDouble() << endl;
	f2.outputReducedFraction();
	cout << endl;
	return 0;
}

////input-main2.cpp
//int main()
//{
//	Fraction f1, f2, f3, f4;
//	f1.setNumerator(500);
//	f1.setDenominator(2);
//	cout << f1.getDouble() << endl;
//	f1.outputReducedFraction();
//	cout << endl;
//
//	f2.setNumerator(1);
//	f2.setDenominator(80);
//	cout << f2.getDouble() << endl;
//	f2.outputReducedFraction();
//	cout << endl;
//
//	f3.setNumerator(450);
//	f3.setDenominator(1);
//	cout << f3.getDouble() << endl;
//	f3.outputReducedFraction();
//	cout << endl;
//
//	f4.setNumerator(3);
//	f4.setDenominator(50);
//	cout << f4.getDouble() << endl;
//	f4.outputReducedFraction();
//	cout << endl;
//	return 0;
//}