#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class VecNf {
	vector<double> v;
public:
	VecNf();
	VecNf(int size);
	VecNf(float ary[], int size);
	VecNf(double ary[], int size);

	bool dimensionFalse(const VecNf &v) const;

	//VecNf& operator=(const VecNf &v);
	VecNf operator+(const VecNf &v) const;
	VecNf operator-(const VecNf &v) const;
	double operator*(const VecNf &v) const;
	VecNf operator*(double d) const;
	friend VecNf operator*(double d, const VecNf &v);
	double operator[](size_t i)const;
	double& operator[](size_t i);
};