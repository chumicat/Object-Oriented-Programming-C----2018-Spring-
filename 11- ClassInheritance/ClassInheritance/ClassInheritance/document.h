/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID： B10332030
 * Date: May. 23, 2018
 * Last Update: May. 23, 2018
 * Version: v1.0
 * Problem statement: ClassInhenitance
 * Reference:
 */

#pragma once
#include <algorithm>
#include <string>
using std::string;

class Document {
protected:
	string text;
public:
	string setText(const string &s);
	string getText() const;
	Document & operator= (const Document &d);
};

bool ContainsKeyword(const Document &d, const string &searchTarget);