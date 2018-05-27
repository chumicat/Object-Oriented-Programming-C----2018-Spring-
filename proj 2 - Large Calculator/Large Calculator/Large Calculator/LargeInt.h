#pragma once
//#ifndef LARGEINT_H
//#define LARGEINT_H
// https://www.ptt.cc/man/C_and_CPP/D8D2/DA94/DDBB/M.1127480887.A.E7F.html
// https://stackoverflow.com/questions/34593263/c-overloading-operator

#include <algorithm>
#include <cctype>
#include <functional>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>
#include "LargeBase.h"
#define vecDigCosIt vector<Digit>::const_iterator
typedef signed char Digit;

//using namespace std;
using std::istream;
using std::iterator;
using std::ostream;
using std::regex;
using std::string;
using std::vector;

class LargeNum;
class LargeVar;
class ParserAll;
class LargeInt:public LargeBase {
private:
	/* Member */
	bool sign;
	vector<Digit> value;

	/* Get and Set Function */
	template <typename const_Iterator>
	inline void setValue(const const_Iterator &rhsItBegin, const const_Iterator &rhsItEnd);
	inline void setValue(const string &s);
	// EQ NE / GT LT GE LE / HI LO HS LS 
	static bool HS(const vecDigCosIt & lhsItBegin, const vecDigCosIt & lhsItEnd, const vecDigCosIt & rhsItBegin, const vecDigCosIt & rhsItEnd);
	static bool HS(const vector<Digit> & lhs, const vector<Digit> & rhs);
	inline void trimZero();
	inline void formatSelf();

public:
	/* Constructor */
	//LargeInt();
	LargeInt(int i = 0);
	LargeInt(const string &s);

	/* Operator Overloaded */
	const LargeInt operator-() const;
	LargeInt & operator++ (); /* Prefix */
	const LargeInt operator++ (int); /* Postfix */
	LargeInt & operator-- (); /* Prefix */
	const LargeInt operator-- (int); /* Postfix */
	LargeInt & operator= (const LargeInt & rhs);
	LargeInt & operator= (int i);
	LargeInt & operator= (const string & s);
	friend const LargeInt operator+ (const LargeInt & lhs, const LargeInt & rhs);
	friend const LargeInt operator- (const LargeInt & lhs, const LargeInt & rhs);
	friend const LargeInt operator* (const LargeInt & lhs, const LargeInt & rhs);
	friend const LargeInt operator/ (const LargeInt & lhs, const LargeInt & rhs);
	friend const LargeInt operator% (const LargeInt & lhs, const LargeInt & rhs);
	const LargeInt & operator+= (const LargeInt & rhs);
	const LargeInt & operator-= (const LargeInt & rhs);
	const LargeInt & operator*= (const LargeInt & rhs);
	const LargeInt & operator/= (const LargeInt & rhs);
	const LargeInt & operator%= (const LargeInt & rhs);
	const bool operator> (const LargeInt & rhs) const;
	const bool operator< (const LargeInt & rhs) const;
	const bool operator>= (const LargeInt & rhs) const;
	const bool operator<= (const LargeInt & rhs) const;
	const bool operator== (const LargeInt & rhs) const;
	const bool operator!= (const LargeInt & rhs) const;
	const bool operator> (const LargeNum & rhs) const;
	const bool operator< (const LargeNum & rhs) const;
	const bool operator>= (const LargeNum & rhs) const;
	const bool operator<= (const LargeNum & rhs) const;
	const bool operator== (const LargeNum & rhs) const;
	const bool operator!= (const LargeNum & rhs) const;
	Digit & operator[](size_t index);
	const size_t operator[](size_t index) const;
	//friend istream & operator>> (istream & input, const LargeInt & rhs);
	friend ostream & operator<<(ostream & output, const LargeInt & rhs);

	/* Get and Set Function */
	void setNum(const string & s);
	template <typename const_Iterator>
	const const_Iterator begin() const;
	template <typename const_Iterator>
	const const_Iterator end() const;

	/* Check Function */
	size_t digit();
	bool inInt32() const;
	bool inInt64() const;
	bool inUInt32() const;
	bool inUInt64() const;
	
	/* Calculate Function */
	LargeInt sqrt() const;
	LargeNum sqrtToNum() const;
	LargeInt pow(const LargeInt & n) const;
	LargeNum pow(const LargeNum & rhs) const;
	LargeInt abs() const;
	LargeInt gcd(const LargeInt & n) const;
	LargeInt lcm(const LargeInt & n) const;
	LargeInt fact() const;
	static LargeInt fact(size_t ui);

	/* Convert Function */
	int toInt32() const;
	long long int toInt64() const;
	string toString() const;
};
//#endif // LARGEINT_H