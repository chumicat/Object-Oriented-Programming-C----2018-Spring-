/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: Mar. 8, 2018
* Last Update: Mar. 8, 2018
* Version: v1.0
* Problem statement: Exchange Foreign Currency
* Reference:
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

typedef struct countryCurrencyPair {
	string country;
	string abb;
	double currency;
}ccPair;

int main() {
	/* Currency vector */
	vector<ccPair> listOfCurrency = {
		{"Taiwan", "TWD", 1}, 
		{"Japan", "JYP", 3.5778 },
		{"America", "USD", 0.0339 },
		{"Korean", "KRW", 34.1180 }
	};

	/* Read data pair by pair */
	string country;
	int cash;
	while (std::cin >> country >> cash) {
		bool exist = false;
		for (ccPair c : listOfCurrency) {
			if (country == c.country) {
				exist = true;
				std::cout
					<< std::setw(6) << "TWD" << std::setw(12) << c.abb << std::endl
					<< std::setw(6) << cash << std::setw(12) << cash*c.currency << std::endl;
			}
		}
		if (!exist)
			std::cout << "We don't provide the exchange of this country." << std::endl;
	}
}