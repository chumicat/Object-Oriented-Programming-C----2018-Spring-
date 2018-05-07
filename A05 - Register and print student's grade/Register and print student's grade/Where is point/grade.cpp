/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 29, 2018
 * Last Update: Mar. 29, 2018
 * Version: v1.0
 * Problem statement: Register and print student's grade
 * Reference:
 */
#include <iostream>
#include "student.h"
using namespace std;

#define MAX 10


/*
Please implement your class "student" and functions here.
*/
int main()
{
	student std[MAX];       //array of objects creation
	int numberOfStudents;

	cout << "Enter total number of students: ";
	cin >> numberOfStudents;

	for (int i  = 0; i< numberOfStudents; i++) {
		cout << "Enter details of student " << i + 1 << ":\n";
		std[i].setDetails();
	}

	cout << endl;

	for (int i = 0; i < numberOfStudents; i ++) {
		cout << "Details of student " << (i + 1) << ":\n";
		std[i].getDetails();
		cout << endl;
	}

	system("pause");
	return 0;
}