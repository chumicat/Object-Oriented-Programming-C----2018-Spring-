/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 17, 2018
 * Last Update: Mar. 17, 2018
 * Version: v1.0
 * Problem statement: NameSpaceTraining
 * Reference:
 */

#include "user.h"

namespace Authenticate
{
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}

	string getUserName()
	{
		return username;
	}
}	

namespace {
	bool isValid() {
		return std::regex_match(username, std::regex("[A-Za-z]{8}"));
	}
}

