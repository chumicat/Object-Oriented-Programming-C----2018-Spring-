/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 17, 2018
 * Last Update: Mar. 17, 2018
 * Version: v1.0
 * Problem statement: NameSpaceTraining
 * Reference:
 */

#pragma once
#ifndef PASSWORD_H
#define PASSWORD_H

#include <iostream>
#include <regex>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace Authenticate
{
	/* Get user input of password */
	void inputPassword();
	/* Get function of namespace variable */
	string getPassword();
}

namespace {
	/* Check if input is fit password format */
	bool isValid();
	/* Variable */
	static string password;
}

#endif // !PASSWORD_H

