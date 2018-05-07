/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * Date: Apr. 21, 2018
 * Languaage: C++
 * Last Update: Apr. 21, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

enum Type {
	MOTORCYCLE,
	CAR,
	BIKE
};

int main() {
	/* Type data */
	unordered_map<string, Type> um = {
		{"motorcycle", MOTORCYCLE},
		{"car", CAR},
		{"bike", BIKE},
		{"bicycle", BIKE}
	};

	/* Read each data */
	string type;
	double ihours;
	int hours;
	while (cin >> type >> ihours) {
		/* Read and change data */
		type[0] = tolower(type[0]);
		hours = ihours == (int)ihours ? (int)ihours : (int)ihours + 1;
		cout << hours << endl;
		
		/* Type check */
		if (!um.count(type)) {
			cout << "System does not support this type of vehicle." << endl;
			continue;
		}
		if (hours <= 0) {
			cout << "System does not support this time number." << endl;
			continue;
		}

		/* Caluclate fee */
		int pay;
		switch (um[type]) {
		case MOTORCYCLE:
			if (hours <= 3)
				pay = hours * 30;
			else
				pay = 90 + (hours - 3) * 40;
			break;
		case CAR:
			if (hours <= 6)
				pay = (100 + 10 * (hours - 1))* hours / 2;
			else
				pay = 450 + (hours - 6) * 100;
			break;
		case BIKE:
			pay = 0;
			break;
		}

		/* Show */
		cout << "The Parking fee is " << pay << endl;
	}
}