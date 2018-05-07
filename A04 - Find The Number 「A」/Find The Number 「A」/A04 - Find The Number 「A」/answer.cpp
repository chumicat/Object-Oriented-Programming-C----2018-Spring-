/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 22, 2018
 * Last Update: Mar. 22, 2018
 * Version: v1.0
 * Problem statement: Find The Number ¡uA¡v
 * Reference:
 */

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <regex>
#include <utility>
using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::pair;
using std::regex;
using std::regex_match;
using std::string;
using std::stringstream;
using std::vector;

int main() {
	// end until EOF
	while (cin.peek() != EOF) {
		// round variable
		string input;
		double comp, max = DBL_MAX;
		vector<string> dataList;
		vector<string> ans;

		// round 1: get data
		while (cin.peek() != '\n') {
			cin >> input;
			if (any_of(input.begin(), input.end(), [](char c) {return c == '.';})) {
				while (input.back() == '0')
					input.pop_back();
				if (input.back() == '.')
					input.pop_back();
			}
			dataList.push_back(input);
		}

		// round 2: get compare element
		cin >> comp;

		// compare each data with comp
		for (string s:dataList) {
			// convert data and calculate diff
			stringstream ss(s);
			double value;
			ss >> value;
			double diff = fabs(value - comp);

			// passing answer
			if (diff == max) {
				ans.push_back(s);
			} else if (diff < max) {
				max = diff;
				ans.clear();
				ans.push_back(s);
			}
		}

		// show answer
		//copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, " + "));
		for(int n=0; n<ans.size()-1; n++)
			cout << ans[n] << " + ";
		cout << ans.back() << endl;

		// clear '\n' in buffer
		cin.get();
	}
	system("pause");
	return 0;
}