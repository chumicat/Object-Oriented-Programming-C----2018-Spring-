/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 22, 2018
 * Last Update: Mar. 22, 2018
 * Version: v1.0
 * Problem statement: Maximize Pulse
 * Reference:
 */#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::ostream;
using std::ostream_iterator;
using std::sort;
using std::string;
using std::vector;

// Card is each line of input
class Card{
public:
	int n1 = 0;
	int n0 = 0;
	double rate = 0.0;
	int value = 0;

	Card(string s) {
		for (char c : s) {
			switch (c) {
			case '0':
				n0++;
				value += n1;
				break;
			case '1':
				n1++;
				break;
			}
		}
		rate = n0 == 0 ? DBL_MAX : n1 / (double)n0;
	}

	friend ostream& operator<<(ostream& os, const Card& card)
	{
		os << "n1 = " << card.n1 << ", n0 = " << card.n0 << ", value = " << card.value << ", rate = " << card.rate << endl;
		return os;
	}

	static int score(const vector<Card> &v) {
		int ans = 0;
		int num1 = 0, num0 = 0;
		for (const Card &c : v) {
			ans += c.value;
			ans += num1 * c.n0;
			num1 += c.n1;
		}
		return ans;
	}

	static void show(const vector<Card> &v) {
		copy(v.begin(), v.end(), ostream_iterator<Card>(cout, ""));
		cout << endl;
	}
};


int main() {
	// run until end
	int num;
	while (cin >> num) {
		// round variable
		vector<Card> v;

		// read each round of input
		string input;
		for (int n = 0; n < num; n++) {
			cin >> input;
			v.emplace_back(input);
			//cout << v.back().n0 << " " << v.back().n1 << " " << v.back().value << endl;
		}

		// sort
		sort(v.begin(), v.end(), [](const Card &left, const Card &right) {return left.rate > right.rate; });
		
		// show ans
		cout << Card::score(v) << endl;
	}

	return 0;
}