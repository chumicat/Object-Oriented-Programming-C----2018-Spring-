/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 15, 2018
 * Last Update: Mar. 15, 2018
 * Version: v1.0
 * Problem statement: Number Pyramid
 * Reference:
 */

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

/* Calculate coefficient. If use probility, need to deal properly. */
vector<vector<long long int>> Coefficient() {
	// initial level nad first value of baska triangle
	vector<vector<long long int>> ans(100);
	ans.at(0).push_back(1);

	// dealing each level
	for (int i = 1; i < ans.size(); i++) {
		// set each level size
		ans.at(i).resize(i + 1);

		// calculate baska triangle
		ans.at(i).front() = ans.at(i - 1).front();
		for (int j = 1; j < ans.at(i).size()-1; j++) {
			ans.at(i).at(j) = ans.at(i - 1).at(j - 1);
			ans.at(i).at(j) += ans.at(i - 1).at(j);
		}
		ans.at(i).back() = ans.at(i - 1).back();
	}

	//for (int n = 0; n < ans.size(); n++) {
	//	for (int m = 0; m < ans.at(n).size(); m++)
	//		std::cout << ans.at(n).at(m) << " ";
	//	std::cout << std::endl;
	//}
	return ans;
}

int main() {
	// baska triangle
	vector<vector<long long int>> coefficient = Coefficient();

	while (true) {
		// Variable
		vector<int> v;
		char buffer[52];
		char c; int n; bool title = true;

		// Read each round data
		std::cin.get(buffer, 51).get();
		for (n = 0, c = buffer[0]; c != NULL; c = buffer[++n]) {
			// Dealing each round, delete title zero, store in vector
			if (title && c == '0')
				continue;
			title = false;
			v.push_back((int)(c - '0'));
		}

		// calculate ans
		long long int ans = 0;
		for (int i=0; i<v.size() ;i++)
			ans += v.at(i) * coefficient.at(v.size() - 1).at(i);
		std::cout << ans << std::endl;
	}
}