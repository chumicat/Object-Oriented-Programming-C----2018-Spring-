/* 
 * 
 * reference:
 *  cpp-peglib: https://github.com/yhirose/cpp-peglib
 */

#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include "peglib.h"
#include "LargeInt.h"
#include "LargeNum.h"
#include "LargeVar.h"
#include "Parser.h"

using namespace peg;
using namespace std;
//typedef LargeVar Ele;

int main(){
	Ele val;
	string str;
	//LargeInt a("4");
	//LargeInt a("456");
	//cout << a << endl;
	//cout << (a = "0") << endl;
	//cout << (a = "-0") << endl;
	//cout << (a = "-00") << endl;
	//cout << (a = "-123") << endl;
	//cout << (a = "00123456789012345678901324567890") << endl;
	//cout << (a = "30/5+0.25*100") << endl;
	//cout << (a = "0.2+0.3+1.25") << endl;
	//cout << (a = "5.0/2+9/2") << endl;
	//cout << (a = "5.0/2+9.0/2") << endl;
	//cout << (a = "2^3^2") << endl;
	//LargeNum b("456");
	//cout << b << endl;
	//cout << (b = "5.0/2+9/2") << endl;
	//cout << (b = "5.0/2+9.0/2") << endl;
	//cout << (b = "2^3^2") << endl;
	//cout << (b = "58/0") << endl;

	//cout << a << endl;

	//LargeVar a(LargeInt(4));
	//LargeVar b(LargeNum(5.0));
	//cout << (a + b) << endl;
	//cout << (a - b) << endl;
	//cout << (a * b) << endl;
	//cout << (a / b) << endl;
	//cout << (b + a) << endl;
	//cout << (b - a) << endl;
	//cout << (b * a) << endl;
	//cout << (b / a) << endl;
	//LargeVar sssss = b / a;
	//cout << "b/a = " << sssss << endl;
	//cout << (-a) << endl;
	//cout << (-b) << endl;
	//cout << (a.sqrt()) << endl;
	//cout << (b.sqrt()) << endl;
	//cout << (b.pow(a)) << endl;
	//cout << (a.pow(b)) << endl;
	//cout << (a.fact()) << endl;
	//vector<LargeVar> lv;
	//lv.push_back(LargeInt("250"));
	//lv.push_back(LargeInt("0"));
	//lv.push_back(LargeNum(20.125));
	//lv.push_back(LargeNum("3.1415926535"));
	//lv.push_back(LargeNum("-0"));
	//lv.push_back(LargeNum(-2.714));
	//lv.push_back(123);
	//lv.push_back(-2);
	//lv.push_back(-2.576);
	//lv.push_back(123.45678);
	//for (Ele a : lv)
	//	cout << a << endl;

	cout << "> ";
	while (getline(cin, str)) {
		/* Parsing */
		bool toShow = ParserAll::parser_all(str, val);

		/* Show Result */
		if(toShow)
			cout << val << endl;
		cout << "> ";
		toShow = true;
	}
}