/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 17, 2018
 * Last Update: Mar. 17, 2018
 * Version: v1.0
 * Problem statement: NameSpaceTraining
 * Reference:
 */

#include <iostream>
#include "password.h"
#include "user.h"
using namespace Authenticate;
using std::cout;
using std::endl;

int main()
{
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() << " and your password is: "
		<< getPassword() << endl;
	return 0;
}
