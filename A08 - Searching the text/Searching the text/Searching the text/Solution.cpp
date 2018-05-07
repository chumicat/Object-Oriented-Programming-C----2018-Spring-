/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 14, 2018
 * Last Update: Apr. 14, 2018
 * Version: v1.0
 * Problem statement: Search the text
 * Reference:
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define FNAME "Data.txt"
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::vector;

int main() {
	fstream fs(FNAME);

	/* Read each line in file */
	string line;
	vector<string> vs;
	while (getline(fs, line))
		vs.push_back(line);

	/* Check all possible word for each input */
	string word;
	while (cin >> word) {
		bool match = false;
		for (int n = 0; n < vs.size(); n++) {
			/* Get line n */
			string line = vs[n];

			/* First match in this line */
			int i = line.find(word);
			if (i == -1)
				continue;
			else
				cout << "The word " << word << " find at line " << n+1 << ", position:" << i+1;
			
			/* Other match in this line */
			i = line.find(word, ++i);
			while (i != -1) {
				cout << ", " << i+1;
				i = line.find(word, ++i);
			}

			/* End line and make a new line */
			cout << endl;
			match = true;
		}

		/* All situation didn't match */
		if(!match)
			cout << "The word " << word << " not exist in this file.\n";
	}
}