/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 15, 2018
 * Last Update: Mar. 15, 2018
 * Version: v1.0
 * Problem statement: Factorial
 * Reference:
 */

#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

/* Calculate f!, limit f = 20 */
long long int Factorial(size_t f) {
	if (f > 20) throw;
	long long int ans = 1;
	for (size_t n = 1; n <= f; n++)
		ans *= n;
	return ans;
}

int main() {
	/* Read each group of data */
	int count;
	while (std::cin >> count) {
		/* Store same group of data in vector */
		vector<int> v;
		int num;
		for (int n = 0; n < count; n++) {
			std::cin >> num;
			v.push_back(num);
		}

		/* Sort data */
		std::sort(v.begin(), v.end());

		/* Show answer */
		if (!v.empty())
			std::cout << Factorial(v[0]);
		for (int n=1; n<v.size(); n++)
			std::cout << "<" << Factorial(v[n]) ;
		std::cout << std::endl;
	}
	return 0;
}