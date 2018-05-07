/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: Mar. 6, 2018
* Last Update: Mar. 6, 2018
* Version: v1.1
* Problem statement: Square Code
* Reference:
https://www.ptt.cc/bbs/C_and_CPP/M.1318588487.A.83D.html
*/

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

/* Babylonian algorithm */
string squareCode(string msg)
{	/* Calculate square size */
	double sideInDouble = sqrt(msg.size());
	int side = (int)sideInDouble == sideInDouble ? (int)sideInDouble : (int)sideInDouble + 1;
	
	/* Seperate message */
	vector<string>* sc = new vector<string>(side);
	for (int n = 0; n < msg.size(); n++)
		sc->at(n%side) = sc->at(n%side) + msg[n];

	/* Pending answer */
	string ans;
	for (int n = 0; n < sc->size(); n++)
		ans += sc->at(n) + "\n";

	return ans;
}

int main()
{	/* Read data one by one */
	string msg;
	while (std::cin >> msg) {
		std::cout << squareCode(msg);
	}

	return 0;
}
