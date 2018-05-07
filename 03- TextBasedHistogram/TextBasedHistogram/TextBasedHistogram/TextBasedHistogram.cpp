/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 6, 2018
 * Last Update: Mar. 6, 2018
 * Version: v1.0
 * Problem statement: Text based histogram
 * Reference:
 */

#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#define IFNAME "grade.txt"
#define OFNAME "grades.Output"
#define MAXSIZE 6
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;

class valueList {
private:
	int valuelist[MAXSIZE] = {0};
public:
	void insert(int value) {
		/* nofit situation */
		if (value >= MAXSIZE || value < 0)
			return;
		valuelist[value]++;
		return;
	}
	void showAndOut(ofstream &ofs) {
		for (int n = 0; n < MAXSIZE; n++) {
			std::cout << valuelist[n] << " grade(s) of " << n << std::endl;
			ofs << valuelist[n] << " grade(s) of " << n << std::endl;
		}
		return;
	}
};

int main()
{	/* Variable */
	ifstream ifs(IFNAME);
	ofstream ofs(OFNAME);
	string line;

	/* Read data line by line */
	while (std::getline(ifs, line))
	{	/* Read line int by int */
		stringstream ss(line);
		int value;
		valueList vl;
		while (ss >> value) {
			vl.insert(value);
		}
		vl.showAndOut(ofs);
	}
	return 0;
}
