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
#include <string>
#include <vector>
using namespace std;

int main() {
	/* Read data */
	string a, b;
	while (cin >> a >> b){
		/* Check sign */
		bool sign = false;
		if (a[0] == '-') {
			sign = !sign;
			a.erase(a.begin());
		}
		if (b[0] == '-') {
			sign = !sign;
			b.erase(b.begin());
		}

		/* Pass */
		vector <int> v(a.size() + b.size() , 0);
		vector <int> aa(a.size());
		vector <int> bb(b.size());
		for (int i = 0; i < a.size(); i++)
			aa[i] = a[i] - '0';
		for (int i = 0; i < b.size(); i++)
			bb[i] = b[i] - '0';

		reverse(aa.begin(), aa.end());
		reverse(bb.begin(), bb.end());

		//for (int i = 0; i < aa.size(); i++)
		//	cout << aa[i] << endl;
		//for (int i = 0; i < bb.size(); i++)
		//	cout << bb[i] << endl;

		/* Mul */
		for (int i = 0; i < aa.size(); i++) {
			for (int j = 0; j < bb.size(); j++) {
				v[i + j] += aa[i] * bb[j];
				if (v[i + j] >= 10) {
					v[i + j + 1] += v[i + j] / 10;
					v[i + j] = v[i + j] % 10;
				}
			}
		}

		for (int i = v.size() - 1; i >= 0; i--)
			if (v[i] == 0)
				v.pop_back();
			else
				break;

		reverse(v.begin(), v.end());

		if (v.empty())
			v.push_back(0);

		cout << (sign ? "-" : "");
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
		cout << endl;

		//for (int n : v)
		//	cout << n;
		//system("pause");
	}
	system("pause");
}