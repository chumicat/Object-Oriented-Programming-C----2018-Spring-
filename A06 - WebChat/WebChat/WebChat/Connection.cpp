/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 5, 2018
 * Last Update: Apr. 5, 2018
 * Version: v1.0
 * Problem statement: Web Chat_Connection information
 * Reference:
	LDJ
 */

#include "Connection.h"

 /* IP (32bit) and port (16bit), default zero, ex: (2130706433) -> 127.0.0.1 */
Connection::Connection(unsigned int ipAddress, unsigned short port) {
	this->ipAddress = ipAddress;
	this->port = port;
}

/* IP (4*8bit) and port (16bit), default zero, ex: (127,0,0,1) -> 127.0.0.1 */
Connection::Connection(unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4, unsigned short port) {
	this->ipAddress = (ipField1 << 24) + (ipField2 << 16) + (ipField3 << 8) + ipField4;
	this->port = port;
}

/* operator overload << */
std::ostream& operator<<(std::ostream& outputStream, const Connection& connection) {
	/* if 0, unknown, else, show in format scuh as 127.0.0.1 */
	if (connection.ipAddress) {
		outputStream << "IP: " << (connection.ipAddress >> 24 & 0xff) << "." << (connection.ipAddress >> 16 & 0xff) << "." << (connection.ipAddress >> 8 & 0xff) << "." << (connection.ipAddress & 0xff);
	} else {
		outputStream << "IP: unknown";
	}

	/* if 0, unknown, else, show value */
	if (connection.port) {
		outputStream << ", Port: " << connection.port;
	} else {
		outputStream << ", Port: unknown";
	}

	return outputStream;
}
