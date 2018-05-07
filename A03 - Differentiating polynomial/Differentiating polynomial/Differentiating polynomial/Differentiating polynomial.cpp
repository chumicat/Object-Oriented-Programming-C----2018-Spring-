/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 15, 2018
 * Last Update: Mar. 15, 2018
 * Version: v1.0
 * Problem statement: Number Pyramid
 * Reference:
 */

#include <iostream>
#include <vector>
using std::vector;

/* Show vector<int> */
void Print(const vector<int> &coefficients) {
	for (int n : coefficients)
		std::cout << n << " ";
	std::cout << std::endl;
	return;
}

/* different for times and show, do not change input */
void Differential(vector<int> coefficients, int times) {
	for (int i = 0; i < times; i++) {
		coefficients.pop_back();
		for (int j = 0; j < coefficients.size(); j++)
			coefficients[j] *= (coefficients.size() - j);
	}
	Print(coefficients);
	return;
}

/* different for one times, will change input */
void Differential(vector<int> &coefficients) {
	coefficients.pop_back();
	for (int j = 0; j < coefficients.size(); j++)
		coefficients[j] *= (coefficients.size() - j);
}

int main() {
	int N, times;
	while (std::cin >> N >> times) {
		// Read group of data
		vector<int> coefficients;
		int tmp;
		for (int n = 0; n < N; n++) {
			std::cin >> tmp;
			coefficients.push_back(tmp);
		}

		// method 1 differential
		Differential(coefficients, times);

		// method 2 differential
		for (int i = 0; i < times; i++) {
			Differential(coefficients);
			Print(coefficients);
		}
	}
	return 0;
}