/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 9, 2018
 * Last Update: Mar. 9, 2018
 * Version: v1.0
 * Problem statement: Convert minutes to HMS format
 * Reference:
 */

#pragma once
#include <iostream>
using std::endl;
using std::cout;

class PrimeNumber {
private:
	unsigned int prime;
public:
	/* Constructor */
	PrimeNumber() { prime = 1; }
	PrimeNumber(unsigned int p) : prime(p) { if (!isPrime(p)) std::cout << "Warning: This Value is not a prime\n"; }

	/* get and set function */
	unsigned int get() { return prime; }

	/* function */
	static bool isPrime(unsigned int p) {
		unsigned int limit = (unsigned int)sqrt((double)p);
		for (unsigned int n = 2; n <= limit; n++) {
			if (p % n == 0)
				return false;
		}
		return true;
	}
	unsigned int next() {
		for (unsigned int n = prime + 1; ; n++) {
			if (isPrime(n)) {
				return n;
			}
		}
	}
	unsigned int pre() {
		for (unsigned int n = prime - 1; n>1; n--) {
			if (isPrime(n)) {
				return n;
			}
		}
		return 1;
	}

	/* operator */
	unsigned int operator++(int) {
		unsigned int tmp = prime;
		prime = next();
		return tmp;
	}
	unsigned int operator--(int) {
		unsigned int tmp = prime;
		prime = pre();
		return tmp;
	}
	unsigned int &operator++() { return prime = next(); }
	unsigned int &operator--() { return prime = pre(); }
};