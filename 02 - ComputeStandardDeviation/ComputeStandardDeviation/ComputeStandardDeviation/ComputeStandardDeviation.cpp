/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: March. 6, 2018
* Last Update: March. 6, 2018
* Version: v1.1
* Problem statement: Compute average and standard deviation
* Reference:
http://www.cplusplus.com/reference/numeric/accumulate/
*/

#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
using std::vector;

/* Calculate average of a number sequence */
double average(vector<double> v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

/* Calculate standard deviation of a number sequence */
double standardDeviation(vector<double> v)
{
	double ave = average(v);
	double sum = 0;
	for (int n = 0; n < v.size(); n++) {
		sum += pow(v[n] - ave, 2);
	}
	return sqrt(sum/v.size());
}

int main()
{	/* Get scale of the number sequence */
	int num;
	while (std::cin >> num) {
		/* Read number sequence */
		vector<double> v;
		double d;
		for (int n = 0; n < num; n++) {
			std::cin >> d;
			v.push_back(d);
		}

		/* Show the answer */
		std::cout << "Average:" << average(v) << "\tStandard deviation:" << standardDeviation(v) << std::endl;
	}

	return 0;
}
