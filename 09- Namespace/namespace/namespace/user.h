/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 17, 2018
 * Last Update: Mar. 17, 2018
 * Version: v1.0
 * Problem statement: NameSpaceTraining
 * Reference:
 */

#pragma once
#ifndef USER_H
#define USER_H

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
	void inputUserName();
	/* Get function of namespace variable */
	string getUserName();
}

namespace {
	/* Variable */
	static string username;
	/* Check if input is fit user format */
	bool isValid();
}



#endif // !USER_H