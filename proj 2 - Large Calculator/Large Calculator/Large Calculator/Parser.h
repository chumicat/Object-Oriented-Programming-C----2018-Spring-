#pragma once
/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: May. 1, 2018
 * Last Update: May. 28, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 *  cpp-peglib: https://github.com/yhirose/cpp-peglib
 */
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include "peglib.h"
#include "LargeVar.h"
using namespace peg;
using namespace std;
typedef LargeVar Ele;

class ParserAll {
public:
	static bool parser_all(string str, Ele &val) {
		/* Variable */
		regex intReg("([1-9][0-9]*)|0");
		regex numReg("[0-9]*['.']*[0-9]*");
		regex idReg("[_A-Za-z][_A-Za-z0-9]*");
		bool toShow = true;
		static unordered_map<string, Ele> variableMap;

		/* (1) Parsing rule */
		parser parser(R"(
		ASSIGN			<-	"Set" TYPE IDSTR '=' EXPRESSION / IDSTR '=' EXPRESSION / EXPRESSION
        EXPRESSION		<-	LV6 (LV6_OP LV6)*
        LV6				<-	LV5 (LV5_OP LV5)*
        LV5				<-	LV4 (LV4_OP LV4)*
		LV4				<-	LV3 LV3_OP*
		LV3				<-	LV2_OP* LV2
		LV2				<-	'(' EXPRESSION ')' / IDVAL /  NUMBER 
		TYPE			<-	"Integer" / "Decimal"
        LV6_OP			<-	[-+]
        LV5_OP			<-	[/*]
		LV4_OP			<-	[^]
		LV3_OP			<-	[!]
		LV2_OP			<-	[-+]
        NUMBER			<-	[0-9]*["."]*[0-9]* / [0]
		IDVAL			<-	[_A-Za-z][_A-Za-z0-9]*
		IDSTR			<-	[_A-Za-z][_A-Za-z0-9]*
        %whitespace		<-	[ \t\r\n]*
    )");

		/* (2) Parsing action */
		auto return_char = [](const SemanticValues& sv) -> char { return static_cast<char>(*sv.c_str()); };
		auto return_token = [](const SemanticValues& sv) { return sv.token(); };
		auto binary_leftToRight = [&](const SemanticValues& sv) -> Ele {
			auto result = sv[0].get<Ele>();
			for (size_t i = 1u; i < sv.size(); i += 2) {
				Ele num = sv[i + 1].get<Ele>();
				auto ope = sv[i].get<char>();
				switch (ope) {
				case '+': result = result + num; break;
				case '-': result = result - num; break;
				case '*': result = result * num; break;
				case '/':
					Ele zero(0);
					if (num != zero) {
						result = result / num;
					}
					else {
						cout << "Divisor can't be zero" << endl;
						toShow = false;
					}
					break;
				}
			}
			return result;
		};
		auto binary_rightToLeft = [](const SemanticValues& sv) -> Ele {
			auto result = sv[sv.size() - 1].get<Ele>();
			for (int i = (int)sv.size() - 3; i >= 0; i -= 2) {
				auto num = sv[i].get<Ele>();
				auto ope = sv[i + 1].get<char>();
				switch (ope) {
				case '^': result = num.pow(result); break;
					//case '^': result = pow(num, result); break;
				}
			}
			return result;
		};
		auto unary_leftToRight = [](const SemanticValues& sv) -> Ele {
			auto result = sv[0].get<Ele>();
			//auto fact = [&]() {for (int i = result-1; i >= 1; --i) result *= i; };
			for (size_t i = 1u; i < sv.size(); ++i) {
				auto ope = sv[i].get<char>();
				switch (ope) {
				case '!': result = result.fact(); break;
					//case '!': fact(); break;
				}
			}
			return result;
		};
		auto unary_rightToLeft = [](const SemanticValues& sv) -> Ele {
			auto result = sv[sv.size() - 1].get<Ele>();
			for (int i = (int)sv.size() - 2; i >= 0; --i) {
				auto ope = sv[i].get<char>();
				switch (ope) {
				case '+': break;
				case '-': result = -result; break;
				}
			}
			return result;
		};
		auto id_deal = [&](const SemanticValues& sv)->Ele {
			Ele zero(0);
			string str = string(sv.c_str());
			smatch matchResult;
			string id;
			if (regex_search(str, matchResult, idReg))
				id = matchResult[0];
			else {
				cout << "error occured" << endl;
				return zero;
			}

			if (variableMap.count(id))
				return variableMap[id];
			else
				cout << "This variable hadn't been declared" << endl;
			return zero;
		};
		auto num_deal = [&](const SemanticValues& sv) -> Ele {
			string str(sv.c_str());
			//while (*str.begin() == '(' || *str.begin() == '-' || *str.begin() == ')')
			//	str.erase(str.begin());

			int i = atoi(sv.c_str());
			double n = atof(sv.c_str());
			smatch matchResult_i, matchResult_n;
			regex_search(str, matchResult_i, intReg);
			regex_search(str, matchResult_n, numReg);

			Ele ans;
			//if (string(matchResult_i[0]).size() == 0) {
			//	ans = id_deal(sv);
			//}else 
			if (string(matchResult_i[0]).size() == string(matchResult_n[0]).size()) {
				//cout << "int: " << string(matchResult_i[0]) << endl;
				ans.setInt(string(matchResult_i[0]));
			}
			else {
				//cout << "num: " << string(matchResult_n[0]) << endl;
				ans.setNum(string(matchResult_n[0]));
			}

			return ans; // atof(sv.c_str());
		};
		auto assign_deal = [&](const SemanticValues& sv) -> Ele {
			Ele zero(0);
			switch (sv.size()) {
			case 1: /* EXPRESSION */
				toShow = toShow & true;
				return sv[0].get<Ele>(); break;

			case 2: {/* IDSTR '=' EXPRESSION */
					 /* Analysis and get id and value */
				const string id = sv[0].get<string>();
				Ele value = sv[1].get<Ele>();

				/* Assign value */
				if (variableMap.count(id)) {
					variableMap[id].setButKeepType(value);
				}
				else
					cout << "This variable hadn't been declared" << endl;
				toShow = false; return zero; break;

			}case 3: {/* "Set" TYPE IDSTR '=' EXPRESSION */
					  /* Analysis and get id and value */
				//cout << sv.size() << endl;
				//cout << sv.c_str() << endl;
				//cout << sv[0].get<string>() << endl;
				//cout << sv[1].get<string>() << endl;
				//cout << sv[2].get<Ele>() << endl;
				Ele value = sv[2].get<Ele>();
				const string s = sv[0].get<string>();
				const string id = sv[1].get<string>();
				if (s == "Integer")
					value.setToInt();
				else
					value.setToNum();

				/* Declared id and assign value */
				variableMap.erase(id);
				variableMap.emplace(id, value);
				toShow = false; return zero; break;
			}
			}
		};

		/* (3) Binding rule and action */
		parser["ASSIGN"] = assign_deal;
		parser["EXPRESSION"] = binary_leftToRight;
		parser["LV6"] = binary_leftToRight;
		parser["LV5"] = binary_rightToLeft;
		parser["LV4"] = unary_leftToRight;
		parser["LV3"] = unary_rightToLeft;
		parser["TYPE"] = return_token;
		parser["LV6_OP"] = return_char;
		parser["LV5_OP"] = return_char;
		parser["LV4_OP"] = return_char;
		parser["LV3_OP"] = return_char;
		parser["LV2_OP"] = return_char;
		parser["NUMBER"] = num_deal;
		parser["IDVAL"] = id_deal;
		parser["IDSTR"] = return_token;

		/* (4) Parse style */
		parser.enable_packrat_parsing(); // Enable packrat parsing.		/* Delete every space in input */
		
		/* (5) format of input */
		auto endIt = copy_if(str.begin(), str.end(), str.begin(), [](char c) {return c != ' ' && c != '\t'; });
		str.resize(std::distance(str.begin(), endIt));

		/* Parsing */
		parser.parse(str.c_str(), val);
		if (toShow) // succes
			return true;
		else // error
			return false;
	}
};