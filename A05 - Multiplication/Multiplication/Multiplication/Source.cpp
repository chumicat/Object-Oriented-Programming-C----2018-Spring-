/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 29, 2018
 * Last Update: Mar. 29, 2018
 * Version: v1.0
 * Problem statement: Multiplication
 * Reference:
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ostream_iterator;
using std::reverse;
using std::vector;

typedef struct input {
	vector<int> v = vector<int>(3);
	size_t d;
}Input;

void mul(vector<int> &v1, const vector<int> &v2) {
	vector<int> tmp(v1.size() + v2.size() - 1, 0);
	for (int i = 0; i < v1.size(); i++) 
		for (int j = 0; j < v2.size(); j++) 
			tmp[i + j] += v1[i] * v2[j];
	v1 = tmp;
}

int main() {
	// save old buf and redirect
	//std::ifstream in("data.txt");
	//std::streambuf  *cinbuf = std::cin.rdbuf(in.rdbuf());

	// check if end
	Input input;
	while (cin >> input.v[2]) {
		// round variable
		vector<int> ans(1, 1);

		// part a: get data
		cin >> input.v[1] >> input.v[0] >> input.d;

		// part b: calculate
		if (input.d == 0)
			cout << "0" << endl;
		else
			for (int i = 0; i < input.d; i++)
				mul(ans, input.v);

		// show
		reverse(ans.begin(), ans.end());
		copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	// reset to standard input again
	//std::cin.rdbuf(cinbuf);
}