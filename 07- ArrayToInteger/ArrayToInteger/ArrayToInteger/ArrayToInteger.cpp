/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 12, 2018
 * Last Update: Mar. 12, 2018
 * Version: v1.0
 * Problem statement: Array To Integer
 * Reference:
 https://stackoverflow.com/questions/8888748/how-to-check-if-given-c-string-or-char-contains-only-digits
 https://stackoverflow.com/questions/7663709/convert-string-to-int-c
 */

//#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Atoi {
private:
	string beTrans;
	bool sign = false;
public:
	/* Constructor */
	Atoi(string s) { SetString(s); }

	/* Set and get function */
	void SetString(const string &s) { 
		// If error, don't very care. Check and delete sign. Title zero is accepted
		beTrans = s;
		if (!IsDigital()) return;
		if (beTrans[0] == '-') sign = true;
		if (beTrans[0] == '-' || beTrans[0] == '+') beTrans.erase(beTrans.begin());
		//while (beTrans[0] == '0') { beTrans.erase(beTrans.begin()); }
		//if (beTrans.empty()) beTrans = "0";
	}
	const string GetString() { return beTrans; }
	size_t Length() { return beTrans.size(); }

	// Check if in good format
	bool IsDigital() { return std::regex_match(beTrans, std::regex("[+-]?[0-9]+")); }

	// Convert to int char by char
	int StringToInteger() { 
		int ans = 0;
		for (char c : beTrans) {
			ans *= 10;
			ans += (int)(c - '0');
		}
		return sign? -ans : ans;
	}
};

int main(void) {
	string beTrans;

	while (cin >> beTrans) {
		Atoi atoi(beTrans + "20");
		if (atoi.IsDigital()) {
			cout << atoi.Length() << endl;
			cout << atoi.StringToInteger() << endl;
			cout << sizeof(atoi.StringToInteger()) << endl;
		}

		atoi.SetString(beTrans);
		if (atoi.IsDigital()) {
			cout << atoi.Length() << endl;
			cout << atoi.StringToInteger() << endl;
			cout << sizeof(atoi.StringToInteger()) << endl;
		}
	}
	return 0;
}