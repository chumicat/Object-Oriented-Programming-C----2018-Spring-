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

class Email: public Document {
protected:
	string sender;
	string recipient;
	string title;
public:
	Email(const string &body, const string &sender, const string &recipient, const string &title);
	Email & operator=(const Email &e);
};