/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID： B10332030
 * Date: May. 23, 2018
 * Last Update: May. 23, 2018
 * Version: v1.0
 * Problem statement: ClassInhenitance
 * Reference:
 */

#pragma once
#include <string>
#include "document.h"
using std::string;

class File : public Document {
protected:
	string pathname;
public:
	File(const string &body, const string &pathname);
	void setPathname(const string &s);
	string getPathname() const;
};