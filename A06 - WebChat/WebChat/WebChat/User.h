/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 5, 2018
 * Last Update: Apr. 5, 2018
 * Version: v1.0
 * Problem statement: Web Chat
 * Reference:
 */

#pragma once
#include <iostream>
#include <string>
#include <utility>
#include "Connection.h"
using std::move;

class User {
public:
	/* Constructor and Destructor */
	User(std::string name, unsigned int ip = 0, unsigned short int port = 0);
	User(std::string name, unsigned char ipf1, unsigned char ipf2, unsigned char ipf3, unsigned char ipf4, unsigned short int port = 0);
	//User(const User&);
	User(User &u);
	~User();
	/* operator overload << */
	friend std::ostream& operator<<(std::ostream& outputStream, const User& user);
	/* Quantity of current user */
	static int userCount;
	/* User's name */
	std::string name;
	/* User's connection information */
	Connection connection;
};