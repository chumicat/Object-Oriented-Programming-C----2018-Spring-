#include "vector.h"

VecNf::VecNf() : v(1, 0)
{

}

VecNf::VecNf(int size) : v(size)
{
}

VecNf::VecNf(float ary[], int size) : v(size)
{
	for (int i = 0; i < size; i++)
		v[i] = ary[i];
}

VecNf::VecNf(double ary[], int size) : v(size)
{
	for (int i = 0; i < size; i++)
		v[i] = ary[i];
}

bool VecNf::dimensionFalse(const VecNf & v) const
{
	bool result = this->v.size() == v.v.size();
	if (!result)	
		cout << "dimensions inconsistent" << endl;
	return !result;
}

VecNf VecNf::operator+(const VecNf & v) const
{
	if(dimensionFalse(v))
		return VecNf();
	VecNf result(this->v.size());
	for (int i = 0; i < this->v.size(); i++)
		result.v[i] = this->v[i] + v.v[i];
	return result;
}

VecNf VecNf::operator-(const VecNf & v) const
{
	if (dimensionFalse(v))
		return VecNf();
	VecNf result(this->v.size());
	for (int i = 0; i < this->v.size(); i++)
		result.v[i] = this->v[i] - v.v[i];
	return result;
}

double VecNf::operator*(const VecNf & v) const
{
	if (dimensionFalse(v))
		return 0;
	double sum = 0;
	for (int i = 0; i < this->v.size(); i++)
		sum += this->v[i] * v.v[i];
	return sum;
}


VecNf VecNf::operator*(double d) const
{
	VecNf result(this->v.size());
	for (int i = 0; i < this->v.size(); i++)
		result.v[i] = this->v[i] * d;
	return result;
}

double VecNf::operator[](size_t i) const
{
	return v[i];
}

double & VecNf::operator[](size_t i)
{
	return v[i];
}

VecNf operator*(double d, const VecNf & v)
{
	VecNf result(v.v.size());
	for (int i = 0; i < v.v.size(); i++)
		result.v[i] = v.v[i] * d;
	return result;
}
