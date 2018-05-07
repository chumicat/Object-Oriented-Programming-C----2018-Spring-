/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID： B10332030
 * Date: Mar. 7, 2018
 * Last Update: Mar. 7, 2018
 * Version: v1.0
 * Problem statement: ComplexClass
 * Reference:
http://en.cppreference.com/w/cpp/language/operators
 */

#include <cmath>
#include <iostream>
#include <string>
#include"complex.h"
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using namespace std;

class Complex {
private:
	double mReal;
	double mImaginary;

public:
	/* Constructor */
	Complex() { mReal = 0; mImaginary = 0; }
	Complex(double iReal) : mReal(iReal) { mImaginary = 0; }
	Complex(double iReal, double iImaginary) : mReal(iReal), mImaginary(iImaginary) {}

	/* Get, Set member fuction */
	double real() { return mReal; }
	double imag() { return mImaginary; }
	friend double real(Complex c) { return c.real(); }
	friend double imag(Complex c) { return c.imag(); }
	void setReal(double d) { mReal = d; }
	void setImag(double d) { mImaginary = d; }
	void setRealAndImag(double d1, double d2) { mReal = d1, mImaginary = d2; }
	friend double norm(Complex c) { return sqrt(pow(c.real(), 2)+pow(c.imag(), 2)); }

	/* Operator overload */
	/////////// 如果不實作"Complex operator+(double d)"，"Complex + double"居然會匹配到"Complex operator+(Complex c)"
	/* Complex <> Complex */
	bool operator== (Complex& c) { return real() == c.real() && imag() == c.imag(); }
	Complex operator+ (Complex& c) { return Complex(real() + c.real(), imag() + c.imag()); }
	Complex operator- (Complex& c) { return Complex(real() - c.real(), imag() - c.imag()); }
	Complex operator* (Complex& c) { return Complex(real()*c.real() - imag()*c.imag(), real()*c.imag() + imag()*c.real()); }
	Complex operator/ (Complex c) { 
		double deno = pow(c.real(), 2) + pow(c.imag(), 2);
		return Complex((real()*c.real() + imag()*c.imag()) / deno, (imag()*c.real() - real()*c.imag()) / deno);
	}
	/* Complex <> double */
	bool operator== (double& d) { return d == real() && imag() == 0; }
	Complex operator+ (double& d) { return Complex(real() + d, imag()); }
	Complex operator- (double& d) { return Complex(real() - d, imag()); }
	Complex operator* (double& d) { return Complex(real() * d, imag() * d); }
	Complex operator/ (double& d) { return Complex(real() / d, imag() / d); }
	/* double <> Complex */
	friend Complex operator+ (const double& real, Complex& c) { return Complex(real + c.real(), c.imag()); }
	friend Complex operator- (const double& real, Complex& c) { return Complex(real - c.real(), -c.imag()); }
	friend Complex operator* (const double& real, Complex& c) { return Complex(real * c.real(), real * c.imag()); }
	friend Complex operator/ (const double& real, Complex& c) { 
		double deno = pow(c.real(), 2) + pow(c.imag(), 2);
		return Complex(real*c.real() / deno, -real*c.imag() / deno);
	}
	friend istream& operator>> (istream& input, Complex& c) { 
		double v1, v2;
		input >> v1 >> v2;
		c.setRealAndImag(v1, v2);
		return input;
	}
	friend ostream& operator<< (ostream& output, Complex& c) {
		//if (c.real() != 0)	output << c.real();
		//if (c.real() != 0 && c.imag() > 0)	output << "+";
		//if (c.real() != 0 && c.imag() < 0)	output << "-";
		//if (c.imag() != 0)	output << fabs(c.imag()) << "*i";
		output << c.real() << " + " << c.imag() << "*i\n";
		return output;
	}
};

int main()
{
	// test constructors
	Complex x, y(3), z(-3.2, 2.1);
	cout << "x =  " << x << "y = " << y << "z = " << z << endl << endl;

	x = Complex(3, -4);

	cout << "testing members and support functions as well as"
		<< " output operator:\n"
		<< "complex number x = " << x << endl
		<< "real part: " << x.real() << endl
		<< "real part from friend real(x): " << real(x) << endl
		<< "imaginary part: " << x.imag() << endl
		<< "imaginary part from friend imag(x) : " << imag(x) << endl
		<< "norm: " << norm(x) << endl << endl;
		;
	cout << "test operator ==:" << endl << endl;
	if (x == y)
		cout << "x = y" << endl << endl;
	else
		cout << "x!=y" << endl << endl;

	cout << "test complex arithmetic and output routines: \n\n";
	y = Complex(1, -1);
	cout << "x =  " << x << "y = " << y << "z = " << z << endl << endl;

	z = x + y;
	cout << "z = x + y = " << z << endl;

	z = x * y;
	cout << "z = x * y = " << z << endl;

	z = x - y;
	cout << "z = x - y = " << z << endl;

	z = x / y;
	cout << "z = x / y = " << z << endl << endl;

	//test of automatic conversion double -> complex by the constructor. 

	double d(2.0);
	cout << "d: " << d << "   x: " << x << endl;
	cout << "x+d: ";
	z = x + d;
	cout << z << endl;
	z = x - d;
	cout << "x-d: ";
	cout << z << endl;
	z = x * d;
	cout << "x*d: ";
	cout << z << endl;
	z = x / d;
	cout << "x/d: ";
	cout << z << endl;
	z = d + x;
	cout << "d+x: ";
	cout << z << endl;
	z = d - x;
	cout << "d-x: ";
	cout << z << endl;
	z = d * x;
	cout << "d*x: ";;
	cout << z << endl;
	z = d / x;
	cout << "d/x: ";;
	cout << z << endl;

	//test whether double/complex and complex/complex give same result:
	Complex two(2, 0);
	cout << "two/x: ";
	cout << two / x << endl;

	cout << "\nGetting data from standard input: \n";
	cin >> x >> y;
	cout << "data read is: x = " << x << " y = " << y << endl << endl;
	system("pause");
	return 0;
}

//int main()
//{
//	// test constructors
//	Complex x, y(6), z(0, 2.1);
//	cout << "x =  " << x << "y = " << y << "z = " << z << endl << endl;
//
//	x = Complex(3, -4);
//
//	cout << "testing members and support functions as well as"
//		<< " output operator:\n"
//		<< "complex number x = " << x << endl
//		<< "real part: " << x.real() << endl
//		<< "real part from friend real(x): " << real(x) << endl
//		<< "imaginary part: " << x.imag() << endl
//		<< "imaginary part from friend imag(x) : " << imag(x) << endl
//		<< "norm: " << norm(x) << endl << endl;
//
//	cout << "test complex arithmetic and output routines: \n\n";
//	y = Complex(8, -6);
//	cout << "x =  " << x << "y = " << y << "z = " << z << endl << endl;
//
//	z = x + y;
//	cout << "z = x + y = " << z << endl;
//
//	z = x * y;
//	cout << "z = x * y = " << z << endl;
//
//	z = x - y;
//	cout << "z = x - y = " << z << endl;
//
//	z = x / y;
//	cout << "z = x / y = " << z << endl << endl;
//
//	//test of automatic conversion double -> complex by the constructor. 
//
//	double d(-4);
//	cout << "d: " << d << "   x: " << x << endl;
//	cout << "x+d: ";
//	z = x + d;
//	cout << z << endl;
//	z = x - d;
//	cout << "x-d: ";
//	cout << z << endl;
//	z = x * d;
//	cout << "x*d: ";
//	cout << z << endl;
//	z = x / d;
//	cout << "x/d: ";
//	cout << z << endl;
//	z = d + x;
//	cout << "d+x: ";
//	cout << z << endl;
//	z = d - x;
//	cout << "d-x: ";
//	cout << z << endl;
//	z = d * x;
//	cout << "d*x: ";;
//	cout << z << endl;
//	z = d / x;
//	cout << "d/x: ";;
//	cout << z << endl;
//
//	//test whether double/complex and complex/complex give same result:
//	Complex test(2, 3);
//	cout << "test/x: ";
//	cout << test / x << endl;
//
//	cout << "\nGetting data from standard input: \n";
//	cin >> x >> y;
//	cout << "data read is: x = " << x << " y = " << y << endl << endl;
//	return 0;
//}
