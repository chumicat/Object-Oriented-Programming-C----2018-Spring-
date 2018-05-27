/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: May. 1, 2018
 * Last Update: May. 28, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 *  cpp-peglib: https://github.com/yhirose/cpp-peglib 
 */
#include "LargeVar.h"

LargeVar::LargeVar()
{
	*this = LargeInt(0);
}

LargeVar::LargeVar(const LargeInt & rhs)
{
	*this = rhs;
}

LargeVar::LargeVar(const LargeNum & rhs)
{
	*this = rhs;
}

LargeVar::LargeVar(const LargeVar & rhs)
{
	*this = rhs;
}

LargeVar::LargeVar(int i)
{
	*this = i;
}

LargeVar::LargeVar(double d)
{
	*this = d;
}

LargeVar & LargeVar::operator=(const LargeInt & rhs)
{
	isInt = true;
	i = LargeInt(rhs);
	n = LargeNum(0);
	return *this;
}

LargeVar & LargeVar::operator=(const LargeNum & rhs)
{
	isInt = false;
	this->i = LargeInt(0);
	this->n = LargeNum(rhs);
	return *this;
}

LargeVar & LargeVar::operator=(const LargeVar & rhs)
{
	this->isInt = rhs.isInt;
	if (rhs.isInt)
		*this = rhs.i;
	else
		*this = rhs.n;
	return *this;
}

LargeVar & LargeVar::operator=(int i)
{
	*this = LargeInt(i);
	return *this;
}

LargeVar & LargeVar::operator=(double d)
{
	*this = LargeNum(d);
	return *this;
}

const LargeVar LargeVar::operator-() const
{
	LargeVar tmp;
	if (this->isInt)
		tmp = -(this->i);
	else 
		tmp = -(this->n);
	
	return tmp;
}

const bool LargeVar::operator>(const LargeVar & rhs) const
{
	CMP(>)
}

const bool LargeVar::operator<(const LargeVar & rhs) const
{
	CMP(<)
}

const bool LargeVar::operator>=(const LargeVar & rhs) const
{
	CMP(>=)
}

const bool LargeVar::operator<=(const LargeVar & rhs) const
{
	CMP(<=)
}

const bool LargeVar::operator==(const LargeVar & rhs) const
{
	CMP(==)
}

const bool LargeVar::operator!=(const LargeVar & rhs) const
{
	CMP(!=)
}

void LargeVar::setInt(string s)
{
	this->isInt = true;
	this->i.setNum(s);
	this->n = LargeNum(0);
}

void LargeVar::setNum(string s)
{
	this->isInt = false;
	this->n.setNum(s);
	this->i = LargeInt(0);
}

void LargeVar::setToInt()
{
	if (this->isInt)
		return;
	
	this->isInt = true;
	this->i = this->n.intPart();
	this->n = LargeNum(0);
}

void LargeVar::setToNum()
{
	if (!this->isInt)
		return;

	this->isInt = false;
	this->n = LargeNum(this->i);
	this->i = LargeInt(0);
}

void LargeVar::setButKeepType(const LargeInt & rhs)
{
	if (this->isInt)
		*this = rhs;
	else {
		*this = rhs;
		this->setToNum();
	}
}

void LargeVar::setButKeepType(const LargeNum & rhs)
{
	if (this->isInt)
		*this = rhs.intPart();
	else
		*this = rhs;
}

void LargeVar::setButKeepType(const LargeVar & rhs)
{
	if (this->isInt == rhs.isInt)
		*this = rhs;
	else if (this->isInt)
		this->setButKeepType(rhs.n);
	else
		this->setButKeepType(rhs.i);

}

LargeInt LargeVar::getInt()
{
	if (this->isInt)
		return this->i;
	else
		return this->n.intPart();
}

LargeNum LargeVar::getNum()
{
	if (this->isInt)
		return LargeNum(this->i);
	else
		return this->n;
}

LargeVar LargeVar::sqrt() const
{
	LargeVar tmp;
	if (this->isInt)
		tmp = (this->i.sqrtToNum());
	else
		tmp = (this->n.sqrt());
	return tmp;
}

LargeVar LargeVar::pow(const LargeVar & rhs) const
{
	LargeVar tmp;
	if (this->isInt && rhs.isInt)
		tmp = (this->i.pow(rhs.i));
	else if (this->isInt && !rhs.isInt)
		tmp = (this->i.pow(rhs.n));
	else if (!this->isInt && rhs.isInt)
		tmp = (this->n.pow(rhs.i));
	else
		tmp = (this->n.pow(rhs.n));
	return tmp;
}

LargeVar LargeVar::fact() const
{
	LargeVar tmp;
	if (this->isInt)
		tmp = (this->i.fact());
	else
		tmp = (this->n.fact());
	return tmp;
}

const LargeVar operator+(const LargeVar & lhs, const LargeVar & rhs)
{
	CAL(+)
}

const LargeVar operator-(const LargeVar & lhs, const LargeVar & rhs)
{
	CAL(-)
}

const LargeVar operator*(const LargeVar & lhs, const LargeVar & rhs)
{
	CAL(*)
}

const LargeVar operator/(const LargeVar & lhs, const LargeVar & rhs)
{
	CAL(/)
}

const LargeVar operator%(const LargeVar & lhs, const LargeVar & rhs)
{
	if (lhs.isInt && rhs.isInt)
		return LargeVar(lhs.i + rhs.i);
	else
		throw;
}

ostream & operator<<(ostream & output, const LargeVar & rhs)
{
	if (rhs.isInt)
		return output << rhs.i;
	else
		return output << rhs.n;
	return output;
}
