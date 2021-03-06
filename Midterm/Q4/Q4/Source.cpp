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
#include <vector>
#include "vector.h"
using namespace std;
int main() {

	VecNf empty;
	float xy[] = { 3.5, 2.0 };
	float xyz[] = { 1.0, 2.0, 3.0 };
	float xyz2[] = { 6.0, 5.0, 4.0 };

	VecNf Vxy(xy, 2);
	VecNf Vxyz(xyz, 3);
	VecNf Vxyz2(xyz2, 3);

	//assign
	VecNf copy = Vxyz;

	//setter
	copy[1] = 10;

	cout << "assign && setter test :" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "dimension  " << i + 1 << " :  " << copy[i] << endl;
	}

	//add , inconsistent dimension test
	cout << "add test :" << endl;
	VecNf add = Vxy + Vxyz;
	cout << add[0] << endl;


	//inner product test
	cout << "inner product test : " << endl;
	cout << Vxyz * Vxyz2 << endl;

	//scale test
	cout << "scale test : " << endl;
	VecNf scale = 5 * Vxyz;

	for (int i = 0; i < 3; i++) {
		cout << "dimension  " << i + 1 << " :  " << scale[i] << endl;
	}

	system("pause");
	return 0;
}