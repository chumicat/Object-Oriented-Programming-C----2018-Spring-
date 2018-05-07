/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 5, 2018
 * Last Update: Apr. 5, 2018
 * Version: v1.0
 * Problem statement: Web Chat
 * Reference:
 */

#include "User.h"

int User::userCount = 0;

User::User(std::string name, unsigned int ip, unsigned short int port) : name(name), connection(ip, port) { userCount++; }

User::User(std::string name, unsigned char ipf1, unsigned char ipf2, unsigned char ipf3, unsigned char ipf4, unsigned short int port) : name(name), connection(ipf1, ipf2, ipf3, ipf4, port) { userCount++; }

User::User(User & u) : connection(0, 0) { userCount++; connection = u.connection; }

User::~User() { userCount--; }

std::ostream& operator<<(std::ostream& outputStream, const User& user) { return outputStream << user.connection; }

