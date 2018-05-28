/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: May. 1, 2018
 * Last Update: May. 28, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 *  cpp-peglib: https://github.com/yhirose/cpp-peglib
 */

#include "LargeNum.h"
#include "LargeVar.h"
#include "Parser.h"

void LargeNum::RTCD()
{
	assert(this->value.second != LargeInt(0) && "denominator = 0");
	if (this->value.first == LargeInt(0))
		this->value.second = 1;
	else {
		LargeInt gcd = this->value.first.gcd(this->value.second);
		this->value.first /= gcd;
		this->value.second /= gcd;
	}
	return;
}

inline LargeInt LargeNum::intPart() const
{
	return this->value.first / this->value.second;
}

inline LargeNum LargeNum::digPart() const
{
	return (*this) - this->intPart();
}

LargeNum::LargeNum(double d)
{
	*this = d;
}

LargeNum::LargeNum(int i)
{
	*this = i;
}

LargeNum::LargeNum(const string & s)
{
	*this = s;
}

LargeNum::LargeNum(const LargeInt & rhs)
{
	*this = rhs;
}

const LargeNum operator+(const LargeNum & lhs, const LargeNum & rhs)
{
	return LargeNum(lhs)+=rhs;
}

const LargeNum operator-(const LargeNum & lhs, const LargeNum & rhs)
{
	return LargeNum(lhs)-=rhs;
}

const LargeNum operator*(const LargeNum & lhs, const LargeNum & rhs)
{
	return LargeNum(lhs)*=rhs;
}

const LargeNum operator/(const LargeNum & lhs, const LargeNum & rhs)
{
	return LargeNum(lhs)/=rhs;
}

istream & operator >> (istream & input, LargeNum & rhs)
{
	string s;
	getline(input, s);
	rhs = s;
	return input;
}

ostream & operator<<(ostream & output, const LargeNum & rhs)
{
	return output << rhs.toString();
}

LargeNum LargeNum::sqrt() const
{
	if (*this < 0) {
		cout << "Unable to calculate square root that < 0" << endl;
		return 0;
	} else if (*this >= 1) {
		LargeNum floor = this->intPart().sqrt();
		LargeNum roof = floor + 1;
		for (int i = 0; i < 340; i++) {
			LargeNum mid = (floor + roof) / 2;
			LargeNum pow2 = mid * mid;
			if (pow2 == (*this))
				return mid;
			else if (pow2 < (*this))
				floor = mid;
			else
				roof = mid;
		}
		return floor;
	} else {
		LargeNum floor = 0;
		LargeNum roof = 1;
		for (int i = 0; i < 340; i++) {
			LargeNum mid = (floor + roof) / 2;
			LargeNum pow2 = mid * mid;
			if (pow2 == (*this))
				return mid;
			else if (pow2 < (*this))
				floor = mid;
			else
				roof = mid;
		}
		return floor;
	}

}

LargeNum LargeNum::pow(const LargeNum & n) const
{
	LargeInt n2 = (2 * n.abs()).intPart();
	if (((2 * n).digPart() != 0) || (n.digPart() != 0 && (*this) < 0))
		cout << "unable to calculate pow which may cause Imaginary number" << endl;
	LargeNum num;
	if (n >= 0) {
		num.value.first = this->value.first.pow(n2);
		num.value.second = this->value.second.pow(n2);
	} else 	if (n < 0) {
		num.value.first = this->value.second.pow(n2);
		num.value.second = this->value.first.pow(n2);
	}
	num = num.sqrt();
	if ((*this) < 0 && n.intPart() % 2 == LargeInt(1))
		num.value.first = -num.value.first;
	return num;
}

LargeNum LargeNum::abs() const
{
	LargeNum tmp(*this);
	tmp.value.first = tmp.value.first.abs();
	tmp.value.second = tmp.value.second.abs();
	return tmp;
}

LargeNum LargeNum::fact() const
{
	if (this->value.second.abs() != LargeInt(1)) {
		cout << "unable to calculate faction of num that not int" << endl;
		return 0;
	}
	LargeInt tmp(this->intPart());
	return LargeNum(tmp.fact());
}

string LargeNum::toString() const
{
	LargeInt mul(10);
	mul = mul.pow(accuracy);
	LargeInt tmp = this->value.first * mul;
	tmp /= this->value.second;
	string tail = (tmp % mul).abs().toString();
	while (tail.size() < accuracy) {
		tail = "0" + tail;
	}
	return ((*this)<0? "-" : "") + (tmp / mul).abs().toString() + '.' + tail;
}

string LargeNum::toDivString() const
{
	return this->value.first.toString() +  "/" + this->value.second.toString();
}

const LargeNum & LargeNum::operator+=(const LargeNum & rhs)
{
	LargeInt first = value.first*rhs.value.second + this->value.second*rhs.value.first;
	this->value.second = this->value.second * rhs.value.second;
	this->value.first = first;
	this->RTCD();
	return *this;
}

const LargeNum & LargeNum::operator-=(const LargeNum & rhs)
{
	LargeInt first = value.first*rhs.value.second - this->value.second*rhs.value.first;
	this->value.second = this->value.second * rhs.value.second;
	this->value.first = first;
	this->RTCD();
	return *this;
}

const LargeNum & LargeNum::operator*=(const LargeNum & rhs)
{
	this->value.first = this->value.first * rhs.value.first;
	this->value.second = this->value.second * rhs.value.second;
	this->RTCD();
	return *this;
}

const LargeNum & LargeNum::operator/=(const LargeNum & rhs)
{
	this->value.first = this->value.first * rhs.value.second;
	this->value.second = this->value.second * rhs.value.first;
	this->RTCD();
	return *this;
}

const bool LargeNum::operator>(const LargeNum & rhs) const
{
	return this->value.first*rhs.value.second > this->value.second*rhs.value.first;
}

const bool LargeNum::operator<(const LargeNum & rhs) const
{
	return this->value.first*rhs.value.second < this->value.second*rhs.value.first;
}

const bool LargeNum::operator>=(const LargeNum & rhs) const
{
	return this->value.first*rhs.value.second >= this->value.second*rhs.value.first;
}

const bool LargeNum::operator<=(const LargeNum & rhs) const
{
	return this->value.first*rhs.value.second <= this->value.second*rhs.value.first;
}

const bool LargeNum::operator==(const LargeNum & rhs) const
{
	return this->value.first*rhs.value.second == this->value.second*rhs.value.first;
}

const bool LargeNum::operator!=(const LargeNum & rhs) const
{
	return this->value.first*rhs.value.second != this->value.second*rhs.value.first;
}

void LargeNum::setNum(string s)
{	/* Check formats */
	regex format("[+-]?[0-9]*['.']*[0-9]*");
	if (!std::regex_match(s, format))
		cout << "not num type" << endl;
	int scale = 0;
	int pos = s.find('.');

	if (pos == string::npos) {
		this->value.first.setNum(s);
		this->value.second = 1;
	} else {
		s.erase(s.begin() + pos);
		scale = s.size() - pos;
		this->value.first.setNum(s);
		this->value.second = LargeInt(10).pow(LargeInt(scale));
		this->RTCD();
	}
}
const LargeNum LargeNum::operator-() const
{
	LargeNum tmp(*this);
	tmp.value.first = -tmp.value.first;
	return tmp;
}

LargeNum & LargeNum::operator++()
{
	this->value.first += this->value.second;
	this->RTCD();
	return *this;
}

LargeNum & LargeNum::operator--()
{
	this->value.first -= this->value.second;
	this->RTCD();
	return *this;
}

LargeNum & LargeNum::operator=(const LargeNum & rhs)
{
	this->value = rhs.value;
	return *this;
}

LargeNum & LargeNum::operator=(const string & rhs)
{
	LargeVar vv;
	bool correct = ParserAll::parser_all(rhs, vv);
	*this = vv.getNum();
	if (!correct)
		cout << "set value is not correct" << endl;
	return *this;
}

LargeNum & LargeNum::operator=(double d)
{
	// not offerd accuracy service
	long long int mul = 10000000;
	long long int i = (long long int)((double)mul*d);
	this->value.first = i;
	this->value.second = mul;
	this->RTCD();
	//cout << *this << endl;
	//cout << this->toDivString() << endl;
	return *this;
}

LargeNum & LargeNum::operator=(int i)
{
	this->value.first = i;
	this->value.second = 1;
	return *this;
}

LargeNum & LargeNum::operator=(const LargeInt & rhs)
{
	this->value.first = rhs;
	this->value.second = 1;
	return *this;
}
