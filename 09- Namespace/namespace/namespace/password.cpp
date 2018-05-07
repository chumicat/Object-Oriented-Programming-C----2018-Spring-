/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 14, 2018
 * Last Update: Mar. 14, 2018
 * Version: v1.0
 * Problem statement: NameSpaceTraining
 * Reference:
 */

#include "password.h"

namespace Authenticate
{
	void inputPassword()
	{
		do
		{
			cout << "Enter your password (at least 8 characters " <<
				"and at least one non-letter)" << endl;
			cin >> password;
		} while (!isValid());
	}

	string getPassword()
	{
		return password;
	}
}

namespace {
	bool isValid() {
		return std::regex_match(password, std::regex("[A-Za-z0-9]*[0-9][A-Za-z0-9]*")) && password.size() >= 8;
	}
}
