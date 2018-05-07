/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 14, 2018
 * Last Update: Apr. 14, 2018
 * Version: v1.0
 * Problem statement: Text Repair
 * Reference:
 */
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#define IFNAME "Error.txt"
#define OFNAME "Correct.txt"
using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;

int main() {
	/* Open file */
	ifstream ifs(IFNAME);
	ofstream ofs(OFNAME);

	/* Append all data into one string */
	string document = "";
	string line;
	while (getline(ifs, line))
		document += line;

	bool startOfFile = true;
	bool first = true;
	bool space = false;
	for (char c : document) {
		if (c == ' ') { /* Space situation */
			space = true;
		} else if (c == '.') { /* For end of line, make a new line and reset first bool */
			ofs << ".";
			first = true;
			space = false;
		} else if (first) { /* First character to uppercase */
			ofs << (startOfFile ? "" : " \n") << (char)toupper(c);
			startOfFile = false;
			first = false;
			space = false;
		} else { /* !first case, to lowercase */
			if (space)
				ofs << " ";
			ofs << (char)tolower(c);
			space = false;
		}
	}
}