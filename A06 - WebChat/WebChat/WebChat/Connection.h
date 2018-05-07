/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 5, 2018
 * Last Update: Apr. 5, 2018
 * Version: v1.0
 * Problem statement: Web Chat_Connection information
 * Reference:
	LDJ
 */

#pragma once
#include <iostream>

class Connection {
public:
	/* Copy constructor */
	/* IP (32bit) and port (16bit), default zero, ex: (2130706433) -> 127.0.0.1 */
	Connection(unsigned int ipAddress, unsigned short port);
	/* IP (4*8bit) and port (16bit), default zero, ex: (127,0,0,1) -> 127.0.0.1 */
	Connection(unsigned char ipField1, unsigned char ipField2, unsigned char ipField3, unsigned char ipField4, unsigned short port);
	/* operator overload << */
	friend std::ostream& operator<<(std::ostream& outputStream, const Connection& connection);
private:
	// this device IP, 0 implies unknown
	unsigned int ipAddress;
	// this device port, 0 implies unknown
	unsigned short port;
};
