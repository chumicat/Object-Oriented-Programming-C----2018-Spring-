/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: Mar. 6, 2018
* Last Update: Mar. 6, 2018
* Version: v1.0
* Problem statement: Sort and output the input number with occurrences
* Reference:
*/

#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#define IFNAME "input.txt"
#define OFNAME "output.txt"
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;

/* Element of vector, which counting the value that had happened */
typedef struct valueCounterPair{
	int value;
	int counter;
}vcPair;

class valueList {
private:
	vector<vcPair> valuelist;

public:
	/* insert value to the vector */
	void insert(int value) {
		/* first situation */
		if (valuelist.size() == 0) {
			valuelist.push_back({ value, 1 });
			return;
		}

		/* Insert the value at specfic place which make vector keep sorted */
		vector<vcPair>::iterator it;
		for (it = valuelist.begin(); it < valuelist.end() && value < it->value; it++);
		if (it == valuelist.end() || value > it->value)
			valuelist.insert(it, { value, 1 });
		else /* value == it->value */
			it->counter++;
		return;
	}
	/* showing each value and how many times it had been read and out to file */
	void showAndOut(ofstream &ofs) {
		for (vector<vcPair>::iterator it = valuelist.begin(); it < valuelist.end(); it++) {
			std::cout << it->value << "\t" << it->counter << std::endl;
			ofs << it->value << "\t" << it->counter << std::endl;
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
