/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: Feb. 28, 2018
* Last Update: March. 6, 2018
* Version: v1.1
* Problem statement: Convert minutes to HMS format
* Reference:
https://dotblogs.com.tw/v6610688/2013/11/08/cplusplus_stringstream_int_and_string_convert_and_clear
http://www.cplusplus.com/reference/sstream/stringstream/str/
https://stackoverflow.com/questions/6320995/why-i-cannot-cout-a-string
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <math.h>
using std::string;
using std::stringstream;

/* Babylonian algorithm */
string hms(long long int value)
{
	long long int hour = value / 3600;
	int minute = (value % 3600) / 60;
	int second = (value % 60);
	stringstream ss;
	ss << hour << " hours " << minute << " minutes and " << second << " seconds";
	return ss.str();
}

int main()
{	/* Read data one by one */
	long long int value;
	while (std::cin >> value) {
		std::cout << std::fixed << std::setprecision(2) << hms(value) << std::endl;
	}

	return 0;
}
