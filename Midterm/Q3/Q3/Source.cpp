/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * Date: Apr. 21, 2018
 * Languaage: C++
 * Last Update: Apr. 21, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {

	/* Read num */
	int num;
	cin >> num;
	getchar();

	/* Read data */
	for (int i = 0; i < num; i++) {
		string s;
		getline(cin, s);

		stack<char> sc;
		bool correct = true;
		for (char c : s) {
			switch(c) {
			case '(':
			case '[':
			case '{':
				sc.push(c);
				break;
			case ')':
				if (sc.top() == '(')
					sc.pop();
				else
					correct = false;
				break;
			case ']':
				if (sc.top() == '[')
					sc.pop();
				else
					correct = false;
				break;
			case '}':
				if (sc.top() == '{')
					sc.pop();
				else
					correct = false;
				break;
			}
			if (!correct)
				break;
		}
		if (!correct || !sc.empty())
			cout << "not balanced\n";
		else
			cout << "balanced\n";
	}
}