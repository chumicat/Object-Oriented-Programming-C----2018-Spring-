#pragma once
//#ifndef LARGENUM_H
//#define LARGENUM_H
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <utility>
#include "LargeInt.h"
#include "LargeBase.h"

//using namespace std;
using namespace std;
class LargeInt;
class LargeVar;
class ParserAll;
class LargeNum: public LargeBase {
private:
	/* Member */
	pair<LargeInt, LargeInt> value; // first = molecular, second = denominator
	size_t accuracy = 100;

	/* Get and Set Function */
	inline void RTCD();

public:
	inline LargeInt intPart() const;
	inline LargeNum digPart() const;
	/* Constructor */
	LargeNum(double d);
	LargeNum(int i = 0);
	LargeNum(const string &s);
	LargeNum(const LargeInt &rhs);

	/* Operator Overloaded */
	const LargeNum operator-() const;
	LargeNum & operator++ (); /* Prefix */
	const LargeNum operator++ (int); /* Postfix */
	LargeNum & operator-- (); /* Prefix */
	const LargeNum operator-- (int); /* Postfix */
	LargeNum & operator= (double d);
	LargeNum & operator= (int i);
	LargeNum & operator= (const LargeInt & rhs);
	LargeNum & operator= (const LargeNum & rhs);
	LargeNum & operator= (const string & rhs);
	friend const LargeNum operator+ (const LargeNum & lhs, const LargeNum & rhs);
	friend const LargeNum operator- (const LargeNum & lhs, const LargeNum & rhs);
	friend const LargeNum operator* (const LargeNum & lhs, const LargeNum & rhs);
	friend const LargeNum operator/ (const LargeNum & lhs, const LargeNum & rhs);
	const LargeNum & operator+= (const LargeNum & rhs);
	const LargeNum & operator-= (const LargeNum & rhs);
	const LargeNum & operator*= (const LargeNum & rhs);
	const LargeNum & operator/= (const LargeNum & rhs);
	const bool operator> (const LargeNum & rhs) const;
	const bool operator< (const LargeNum & rhs) const;
	const bool operator>= (const LargeNum & rhs) const;
	const bool operator<= (const LargeNum & rhs) const;
	const bool operator== (const LargeNum & rhs) const;
	const bool operator!= (const LargeNum & rhs) const;
	Digit & operator[](size_t index);
	const size_t operator[](size_t index) const;
	//friend istream & operator>> (istream & input, const LargeNum & rhs);
	friend ostream & operator<<(ostream & output, const LargeNum & rhs);

	void setNum(string s);

	/* Check Function */
	size_t digit();
	bool inDouble() const;

	/* Calculate Function */
	LargeNum sqrt() const;
	LargeNum pow(const LargeNum & n) const;
	LargeNum abs() const;
	LargeNum fact() const;

	/* Convert Function */
	string toString() const;
	string toDivString() const;
};
//#endif //LARGENUM_H