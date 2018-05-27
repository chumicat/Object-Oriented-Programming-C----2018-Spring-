#include "LargeInt.h"
#include "LargeNum.h"
#include "LargeVar.h"
#include "Parser.h"

LargeInt::LargeInt(int i)
{
	(*this) = i;
}

LargeInt::LargeInt(const string & s)
{
	*this = s;
}

//LargeInt::LargeInt(const string & s)
//{
//	(*this) = s;
//}

const LargeInt LargeInt::operator-() const
{	/* If case is 0, just return 0 rather thaan -0 */
	if (this->value.size() == 1 && this->value[0] == 0)
		return *this;
	LargeInt li(*this);
	li.sign = !li.sign;
	return li;
}

LargeInt & LargeInt::operator++()
{
	(*this) += 1;
	return *this;
}

const LargeInt LargeInt::operator++(int)
{
	LargeInt tmp = (*this);
	(*this) += 1;
	return tmp;
}

LargeInt & LargeInt::operator--()
{
	(*this) -= 1;
	return *this;
}

const LargeInt LargeInt::operator--(int)
{
	LargeInt tmp = (*this);
	(*this) -= 1;
	return tmp;
}

LargeInt & LargeInt::operator=(const LargeInt & rhs)
{
	this->sign = rhs.sign;
	this->value = rhs.value;
	return *this;
}

LargeInt & LargeInt::operator=(int i)
{
	/* Clear Data */
	value.clear();

	/* Set Sign */
	/* Inorder to pass INT64_MIN exception when i = -i, use ulli */
	unsigned long long int ulli;
	if (i < 0) {
		sign = true;
		ulli = -i;
	}
	else {
		sign = false;
		ulli = i;
	}

	while (ulli != 0) {
		value.push_back(ulli % 10);
		ulli /= 10;
	}

	/* Zero Case */
	if (value.empty())
		value.push_back(0);
	return *this;
}

LargeInt & LargeInt::operator=(const string & s)
{
	LargeVar vv;
	bool correct = ParserAll::parser_all(s, vv);
	*this = vv.getInt();
	if (!correct)
		cout << "set value is not correct" << endl;
	return *this;
}

//LargeInt & LargeInt::operator=(const string & s)
//{
//	setNum(s);
//	return *this;
//}

const bool LargeInt::operator>(const LargeInt & rhs) const
{	/* Check sign */
	if (this->sign != rhs.sign)
		return rhs.sign;

	/* When sign is equal, check value.size() */
	if (this->value.size() != rhs.value.size())
		return (this->value.size() > rhs.value.size()) ^ (this->sign);
	
	/* When value.size() still equal, compare all */
	const auto & a = std::mismatch(this->value.rbegin(), this->value.rend(), rhs.value.rbegin());
	if (a.first != this->value.rend()) /* this != rhs */
		return (*(a.first) > *(a.second)) ^ (this->sign);
	else /* this == rhs */
		return false;
}

const bool LargeInt::operator<(const LargeInt & rhs) const
{	/* Check sign */
	if (this->sign != rhs.sign)
		return this->sign;

	/* When sign is equal, check value.size() */
	if (this->value.size() != rhs.value.size())
		return (this->value.size() < rhs.value.size()) ^ (this->sign);

	/* When value.size() still equal, compare all */
	const auto & a = std::mismatch(this->value.rbegin(), this->value.rend(), rhs.value.rbegin());
	if (a.first != this->value.rend()) /* this != rhs */
		return (*(a.first) < *(a.second)) ^ (this->sign);
	else /* this == rhs */
		return false;
}

const bool LargeInt::operator>=(const LargeInt & rhs) const
{
	return !(*this < rhs);
}

const bool LargeInt::operator<=(const LargeInt & rhs) const
{
	return !(*this > rhs);
}

const bool LargeInt::operator==(const LargeInt & rhs) const
{
	return 
		this->sign == rhs.sign &&
		this->value.size() == rhs.value.size() &&
		(std::mismatch(this->value.begin(), this->value.end(), rhs.value.begin())).first == this->value.end();
}

const bool LargeInt::operator!=(const LargeInt & rhs) const
{
	return !(*this == rhs);
}

const bool LargeInt::operator>(const LargeNum & rhs) const
{
	return rhs < *this;
}

const bool LargeInt::operator<(const LargeNum & rhs) const
{
	return rhs > *this;
}

const bool LargeInt::operator>=(const LargeNum & rhs) const
{
	return rhs <= *this;
}

const bool LargeInt::operator<=(const LargeNum & rhs) const
{
	return rhs >= *this;
}

const bool LargeInt::operator==(const LargeNum & rhs) const
{
	return rhs == *this;
}

const bool LargeInt::operator!=(const LargeNum & rhs) const
{
	return rhs != *this;
}

Digit & LargeInt::operator[](size_t index)
{
	return this->value[index];
}

const size_t LargeInt::operator[](size_t index) const
{
	return (size_t)this->value[index];
}

template<typename const_Iterator>
inline void LargeInt::setValue(const const_Iterator & rhsItBegin, const const_Iterator & rhsItEnd)
{
	value.clear();
	std::reverse_iterator<const_Iterator> rend(rhsItBegin);
	std::reverse_iterator<const_Iterator> rbegin(rhsItEnd);
	for (std::reverse_iterator<const_Iterator> rit = rbegin; rit != rend; rit++)
		value.push_back(*rit-'0');
	return;
}

inline void LargeInt::setValue(const string & s)
{
	value.clear();
	for (string::const_reverse_iterator rit = s.rbegin(); rit != s.rend(); rit++)
		value.push_back(*rit-'0');
	return;
}

bool LargeInt::HS(const vecDigCosIt & lhsItBegin, const vecDigCosIt & lhsItEnd, const vecDigCosIt & rhsItBegin, const vecDigCosIt & rhsItEnd)
{	/* Check Size */
	int lhsSize = lhsItEnd - lhsItBegin;
	int rhsSize = rhsItEnd - rhsItBegin;
	if (lhsSize != rhsSize)
		return lhsSize > rhsSize;

	/* Check Value */
	std::reverse_iterator<vecDigCosIt> lhsrend(lhsItBegin);
	std::reverse_iterator<vecDigCosIt> lhsrbegin(lhsItEnd);
	std::reverse_iterator<vecDigCosIt> rhsrbegin(rhsItEnd);
	const auto & a = std::mismatch(lhsrbegin, lhsrend, rhsrbegin);
	if (a.first != lhsrend) /* this != rhs */
		return (*a.first) > (*a.second);
	else /* this == rhs */
		return true;
}

bool LargeInt::HS(const vector<Digit>& lhs, const vector<Digit>& rhs)
{	/* Check Size */
	if (lhs.size() != rhs.size())
		return lhs.size() > rhs.size();
	
	/* Check Value */
	const auto & a = std::mismatch(lhs.rbegin(), lhs.rend(), rhs.rbegin());
	if (a.first != lhs.rend()) /* lhs != rhs */
		return (*a.first) > (*a.second);
	else /* lhs == rhs */
		return true;
}

inline void LargeInt::trimZero()
{	/* Check from most signficat bit */
	while (!value.empty())
		if (value.back() == 0)
			value.pop_back();
		else
			break;

	/* only zero case */
	if (value.empty()) {
		value.push_back(0);
		sign = false;
	}
}

inline void LargeInt::formatSelf()
{	/* Deal each element */
	if(value.size() > 1)
		for (vector<Digit>::iterator it = value.begin(); it != value.end() - 1; it++) {
			if (*it < 0) {
				*(it + 1) += (*it) % 10 == 0 ? (*it) / 10 : (*it) / 10 - 1;
				(*it) = (*it) % 10 == 0 ? 0 : (*it) % 10 + 10;
			} else {
				*(it + 1) += (*it) / 10;
				(*it) = (*it) % 10;
			}
		}

	/* Deal last element */
	if (value.back() < 0) { /* We assume that input should check sign for us */
		std::cout << "error occured:\n";//throw;
	} else if (value.back() >= 10){
		value.push_back(value.back() / 10);
		*(value.end() - 2) = *(value.end() - 2) % 10;
	}

	/* We didn't deal significant zero directly need to call by user */
	//trimZero();
}

const LargeInt operator+(const LargeInt & lhs, const LargeInt & rhs)
{
	return LargeInt(lhs) += rhs;
}

const LargeInt operator-(const LargeInt & lhs, const LargeInt & rhs)
{
	return LargeInt(lhs) -= rhs;
}

const LargeInt operator*(const LargeInt & lhs, const LargeInt & rhs)
{
	return LargeInt(lhs) *= rhs;
}

const LargeInt operator/(const LargeInt & lhs, const LargeInt & rhs)
{
	return LargeInt(lhs) /= rhs;
}

const LargeInt operator%(const LargeInt & lhs, const LargeInt & rhs)
{
	return LargeInt(lhs) %= rhs;
}

ostream & operator<<(ostream & output, const LargeInt & rhs)
{
	return output << rhs.toString();
}

int LargeInt::toInt32() const
{
	if (this->inInt32())
		return atoi(this->toString().c_str());
	else
		throw;
}

long long int LargeInt::toInt64() const
{
	if (this->inInt64())
		return atoi(this->toString().c_str());
	else
		throw;
}

string LargeInt::toString() const
{
	// Dealing sign
	string s;
	if (sign)
		s += "-";
	
	// Dealing Value
	for (vector<Digit>::const_reverse_iterator rit = value.rbegin(); rit != value.rend(); rit++)
		s += ((*rit) + '0');
	return s;
}

void LargeInt::setNum(const string & s)
{	/* Check formats */
	regex format("[+-]?[0-9]*");
	if (!std::regex_match(s, format))
		cout << "not int type" << endl;
	/* Set sign */
	if (s[0] == '-')
		sign = true;
	else
		sign = false;
	/* Deal Value */
	if (s[0] == '+' || s[0] == '-')
		setValue(s.begin() + 1, s.end());
	else
		setValue(s);

	/* Deal -0 case */
	this->trimZero();
}

size_t LargeInt::digit()
{
	return this->value.size();
}

bool LargeInt::inInt32() const
{
	return (*this) <= LargeInt(INT32_MAX) && (*this) >= LargeInt(INT32_MIN);
}

bool LargeInt::inInt64() const
{
	return (*this) <= INT64_MAX && (*this) >= INT64_MIN;
}

bool LargeInt::inUInt32() const
{
	return (*this) <= LargeInt(UINT32_MAX) && (*this) >= LargeInt(0);
}

bool LargeInt::inUInt64() const
{
	return (*this) <= LargeInt(UINT64_MAX) && (*this) >= LargeInt(0);
}

LargeInt LargeInt::sqrt() const
{
	if ((*this) < LargeInt(0)) {
		//throw;
		std::cout << "unable to calculate sqrt that minus" << std::endl;
		return 0;
	}else if (*this == LargeInt(1))
		return 1;

	LargeInt floor = 0;
	LargeInt roof = (*this);
	while (roof > floor + 1) {
		LargeInt mid = (floor + roof) / 2;
		LargeInt pow2 = mid * mid;
		if (pow2 == (*this))
			return mid;
		else if (pow2 < (*this))
			floor = mid;
		else
			roof = mid;
	}
	return floor;
}

LargeNum LargeInt::sqrtToNum() const
{
	LargeNum tmp(*this);
	return tmp.sqrt();
}

LargeInt LargeInt::pow(const LargeInt & n) const
{
	if (n == LargeInt(0))
		return 1;
	else if (n % 2 == LargeInt(0))
		return ((*this)*(*this)).pow(n/2);
	else
		return (*this) * ((*this).pow(n-1));
}

LargeNum LargeInt::pow(const LargeNum & rhs) const
{
	LargeNum tmp(*this);
	return tmp.pow(rhs);
}

//LargeNum LargeInt::pow(const LargeNum & rhs) const
//{
//	return LargeNum();
//}

LargeInt LargeInt::abs() const
{
	LargeInt tmp(*this);
	tmp.sign = false;
	return tmp;
}

LargeInt LargeInt::gcd(const LargeInt & n) const
{
	if ((*this).abs() == n.abs())
		return n;
	else if ((*this) == LargeInt(0) || n == LargeInt(0))
		throw;

	LargeInt a = (*this).abs();
	LargeInt b = ((*this).abs() - n.abs()).abs();
	
	while (true) {
		if (a % b == LargeInt(0))
			return b;
		else
			a %= b;

		if (b % a == LargeInt(0))
			return a;
		else
			b %= a;
	}

}

LargeInt LargeInt::lcm(const LargeInt & n) const
{
	return (*this) / this->gcd(n) * n;
}

LargeInt LargeInt::fact() const
{
	LargeInt tmp(1);
	for (LargeInt i = 1; i <= *this; i++) {
		tmp *= i;
	}
	return tmp;
}

LargeInt LargeInt::fact(size_t ui)
{
	
	LargeInt tmp(1);
	for (size_t i = 1; i <= ui; i++) {
		tmp *= i;
	}
	return tmp;
}

const LargeInt & LargeInt::operator+=(const LargeInt & rhs)
{	/* Resize */
	this->value.resize(std::max(this->value.size(), rhs.value.size()));

	/* add or sub depend on sign */
	if (this->sign == rhs.sign){ /* Sign are same */
		std::transform(rhs.value.begin(), rhs.value.end(), this->value.begin(), this->value.begin(), std::plus<Digit>());
	} else if (HS(this->value, rhs.value)) { /* Sign are different and this is higher same than rhs */
		std::transform(this->value.begin(), this->value.begin() + rhs.value.size(), rhs.value.begin(), this->value.begin(), std::minus<Digit>());
	} else { /* Sign are different and this is lower than rhs */
		this->sign = rhs.sign;
		std::transform(rhs.value.begin(), rhs.value.end(), this->value.begin(), this->value.begin(), std::minus<Digit>());
	}
	
	/* Format */
	this->formatSelf();
	this->trimZero();
	return *this;
}

const LargeInt & LargeInt::operator-=(const LargeInt & rhs)
{	/* Resize */
	this->value.resize(std::max(this->value.size(), rhs.value.size()));

	/* add or sub depend on sign */
	if (this->sign != rhs.sign){ /* Sign are different */
		std::transform(rhs.value.begin(), rhs.value.end(), this->value.begin(), this->value.begin(), std::plus<Digit>());
	} else if (HS(this->value, rhs.value)) { /* Sign are same and this is higher same than rhs */
		std::transform(this->value.begin(), this->value.begin() + rhs.value.size(), rhs.value.begin(), this->value.begin(), std::minus<Digit>());
	} else { /* Sign are same and this is lower than rhs */
		this->sign = !this->sign;
		std::transform(rhs.value.begin(), rhs.value.end(), this->value.begin(), this->value.begin(), std::minus<Digit>());
	}

	/* Format */
	this->formatSelf();
	this->trimZero();
	return *this;
}

const LargeInt & LargeInt::operator*=(const LargeInt & rhs)
{	/* Allocate */
	vector<Digit> tmp(this->value.size() + rhs.value.size());
	
	/* Deal Sign */
	this->sign = this->sign ^ rhs.sign;

	/* Multiplies */
	for(size_t i = 0; i < this->value.size(); i++)
		for (size_t j = 0; j < rhs.value.size(); j++) {
			tmp[i + j] += this->value[i]*rhs.value[j];
			if (tmp[i + j] >= 10) {
				tmp[i + j + 1] += tmp[i + j] / 10;
				tmp[i + j] %= 10;
			}
		}
	(*this).value = tmp;

	/* Format */
	this->trimZero();
	return *this;
}

const LargeInt & LargeInt::operator/=(const LargeInt & rhs)
{	/* Zero Check */
	if (rhs == LargeInt(0))
		throw;
	
	/* Case of divisor is larger, return *this with 0 */
	if (!HS(this->value, rhs.value)) {
		this->value.resize(1);
		this->value[0] = 0;
		this->sign = false;
		return *this;
	}

	/* Set Sign */
	this->sign = this->sign ^ rhs.sign;

	/* Reserve memory */
	vector<Digit> tmp;
	tmp.reserve(this->value.size() - rhs.value.size() + 1);

	/* Make a copy since we need one more digit */
	LargeInt rhs_c = rhs;
	rhs_c.value.push_back(0);
	this->value.push_back(0);

	/* divides */
	for (int endIdx = this->value.size(); endIdx > 0; endIdx--) {
		int beginIdx = endIdx - rhs_c.value.size();
		if (beginIdx == -1) break;
		vector<Digit>::iterator begin = this->value.begin() + beginIdx;
		vector<Digit>::iterator end = this->value.begin() + endIdx;
		size_t counter = 0;
		while (HS(begin, end, rhs_c.value.begin(), rhs_c.value.end())) {
			++counter;
			std::transform(begin, end, rhs_c.value.begin(), begin, std::minus<Digit>());
			formatSelf();
		}
		tmp.insert(tmp.begin(), counter);
	}
	(*this).value = tmp;
	this->trimZero();

	/* Format */
	return *this;
}

const LargeInt & LargeInt::operator%=(const LargeInt & rhs)
{
	return (*this) -= (*this) / rhs * rhs;
}
