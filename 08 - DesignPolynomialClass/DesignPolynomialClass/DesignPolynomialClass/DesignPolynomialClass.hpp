/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 10, 2018
 * Last Update: Apr. 18, 2018
 * Version: v1.0
 * Problem statement: Design Polynomial Class
 * Reference:
https://isocpp.org/wiki/faq/const-correctness#overview-const
https://stackoverflow.com/questions/8716330/purpose-of-returning-by-const-value
 */

#pragma once
#include <algorithm>
#include <cmath>
#include <iterator>
class Polynomial
{
private:
public:
	double *coef;
	int size;	// store valid element double in coef
public:
	/* Constructor & destructor */
	Polynomial() : coef(NULL), size(0) {}
	Polynomial(const Polynomial& poly) : size(poly.size) { 
		delete coef;
		coef = new double[poly.size];
		memcpy(coef, poly.coef, size*sizeof(double));
	}
	Polynomial(double coefficient[], int size) : size(size) {
		coef = new double[size];
		memcpy(coef, coefficient, size*sizeof(double));
		int m = 0;
	}
	~Polynomial() { delete coef; coef = NULL;  }

	/* Operator */
	//Use indexed polynomial as r-value to inspect coefficient
	//and as l-value to assign coefficient
	double& operator[](int degree);
	const double& operator[](int degree)const;
	const Polynomial& operator=(const Polynomial& rhs);
	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);

	/* Function */
	int mySize();
	const void show() const;
	friend double evaluate( const Polynomial& poly, const double arg);
};

inline double & Polynomial::operator[](int degree)
{
	if (degree >= size) throw;
	return coef[degree];
}

inline const double & Polynomial::operator[](int degree) const
{
	if (degree >= size) throw;
	return coef[degree];
}

inline const Polynomial & Polynomial::operator=(const Polynomial & rhs)
{
	//if(rhs.size == 0)
	delete coef;
	coef = new double[rhs.size];
	memcpy(coef, rhs.coef, rhs.size*sizeof(double));
	size = rhs.size;
	
	return rhs;
}

Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs)
{
	int degree = std::max(lhs.size, rhs.size);
	double *coef = new double[degree] { 0.0 };
	for (int n = 0; n < lhs.size; n++)
		coef[n] = lhs.coef[n];
	for (int n = 0; n < rhs.size; n++)
		coef[n] += rhs.coef[n];
	//for (int n = degree - 1; n >= 1 && coef[n] == 0; n--) //n >= 1 for first element allowed to be zero
	//	degree--;
	return Polynomial(coef, degree);
}

Polynomial operator-(const Polynomial & lhs, const Polynomial & rhs)
{
	int degree = std::max(lhs.size, rhs.size);
	double *coef = new double[degree] { 0.0 };
	for (int n = 0; n < lhs.size; n++)
		coef[n] = lhs[n];
	for (int n = 0; n < rhs.size; n++)
		coef[n] -= rhs[n];
	//for (int n = degree - 1; n >= 1 && coef[n] == 0; n--) //n >= 1 for first element allowed to be zero
	//	degree--;
	return Polynomial(coef, degree);
}

Polynomial operator*(const Polynomial & lhs, const Polynomial & rhs)
{
	int degree;
	if (lhs.size != 0 && rhs.size != 0)
		degree = lhs.size + rhs.size - 1;
	else
		return Polynomial();
	double *coef = new double[degree] { 0.0 };
	for (int n1 = 0; n1 < lhs.size; n1++)
		for (int n2 = 0; n2 < rhs.size; n2++)
			coef[n1 + n2] += lhs[n1] * rhs[n2];
	return Polynomial(coef, degree);
}

inline int Polynomial::mySize()
{
	return size;
}

const void Polynomial::show() const
{
	std::cout << "size = " << size << ", coef = ";
	for (int n = 0; n < size; n++)
		std::cout << coef[n] << " ";
	std::cout << std::endl;
}

inline double evaluate( const Polynomial & poly, const double arg)
{
	double sum = 0.0;
	for (int n = 0; n < poly.size; n++) {
		//std::cout << "poly[n] = " << poly[n] << ", arg = " << arg << std::endl;
		sum += poly[n] * pow(arg, n);
		//std::cout << "eva = " << sum << std::endl;
	}
	return sum;
}