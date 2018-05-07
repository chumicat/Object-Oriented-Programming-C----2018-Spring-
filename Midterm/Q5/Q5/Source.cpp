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
	int cycle;
	cin >> cycle;
	for (int i_c = 0; i_c < cycle; i_c++) {
		vector<int> v;
		int num;
		cin >> num;

		int maxnum = INT32_MIN;
		for (int i_n = 0; i_n < num;i_n++) {
			int data;
			cin >> data;
			maxnum = max(maxnum, data);
			v.push_back(data);
		}

		int sum = 0;
		for (int i = 0; i < maxnum; i++) {
			bool act = false;
			int counter = 0;
			for (int n : v) {
				if (i < n && act == false) {
					act = true;
					continue;
				}
				if (act) {
					if (i >= n)
						counter++;
					else {
						sum += counter;
						counter = 0;
					}
				}
			}
		}

		cout << sum << endl;
		
	}
	system("pause");
}