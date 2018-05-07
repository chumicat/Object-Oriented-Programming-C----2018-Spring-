/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 14, 2018
 * Last Update: Apr. 14, 2018
 * Version: v1.0
 * Problem statement: Array application
 * Reference:
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	int a, b, n;
	while (cin >> a >> b >> n)
	{
		/* Show int part */
		cout << a / b << ".";

		/* Show fraction part*/
		for (int i = 0; i < n; i++) {
			a %= b;
			a *= 10;
			cout << a / b;
		}
		//cout << a << " " << b << " " << n << endl;
		cout << endl;
	}
}