#pragma once
#include "LargeVar.h"
#include "LargeInt.h"
#include "LargeNum.h"
#define CMP(cmpToken) \
	if (this->isInt && rhs.isInt) \
		return i cmpToken (rhs.i); \
	else if (this->isInt && !rhs.isInt) \
		return i cmpToken (rhs.n); \
	else if (!this->isInt && rhs.isInt) \
		return n cmpToken (rhs.i); \
	else \
		return n cmpToken (rhs.n);

#define CAL(calToken) \
	LargeVar tmp;	\
	if (lhs.isInt && rhs.isInt) \
		tmp = ((lhs.i) calToken (rhs.i)); \
	else if (lhs.isInt && !rhs.isInt) \
		tmp = ((lhs.i) calToken (rhs.n)); \
	else if (!lhs.isInt && rhs.isInt) \
		tmp = ((lhs.n) calToken (rhs.i)); \
	else \
		tmp = ((lhs.n) calToken (rhs.n)); \
	return tmp;


class LargeVar {
private:
	bool isInt;
	LargeInt i;
	LargeNum n;
public:
	LargeVar();
	LargeVar(const LargeInt & rhs);
	LargeVar(const LargeNum & rhs);
	LargeVar(const LargeVar &rhs);
	LargeVar(int i);
	LargeVar(double d);
	LargeVar & operator= (const LargeInt & rhs);
	LargeVar & operator= (const LargeNum & rhs);
	LargeVar & operator= (const LargeVar & rhs);
	LargeVar & operator= (int i);
	LargeVar & operator= (double d);
	const LargeVar operator-() const;
	friend const LargeVar operator+ (const LargeVar & lhs, const LargeVar & rhs);
	friend const LargeVar operator- (const LargeVar & lhs, const LargeVar & rhs);
	friend const LargeVar operator* (const LargeVar & lhs, const LargeVar & rhs);
	friend const LargeVar operator/ (const LargeVar & lhs, const LargeVar & rhs);
	friend const LargeVar operator% (const LargeVar & lhs, const LargeVar & rhs);
	//const LargeVar & operator+= (const LargeVar & rhs);
	//const LargeVar & operator-= (const LargeVar & rhs);
	//const LargeVar & operator*= (const LargeVar & rhs);
	//const LargeVar & operator/= (const LargeVar & rhs);
	//const LargeVar & operator%= (const LargeVar & rhs);
	const bool operator> (const LargeVar & rhs) const;
	const bool operator< (const LargeVar & rhs) const;
	const bool operator>= (const LargeVar & rhs) const;
	const bool operator<= (const LargeVar & rhs) const;
	const bool operator== (const LargeVar & rhs) const;
	const bool operator!= (const LargeVar & rhs) const;
	friend ostream & operator<<(ostream & output, const LargeVar & rhs);
	void setInt( string s);
	void setNum( string s);
	void setToInt();
	void setToNum();
	void setButKeepType(const LargeInt & rhs);
	void setButKeepType(const LargeNum & rhs);
	void setButKeepType(const LargeVar & rhs);
	LargeInt getInt();
	LargeNum getNum();

	LargeVar sqrt() const;
	LargeVar pow(const LargeVar & rhs) const;
	LargeVar fact() const;
};