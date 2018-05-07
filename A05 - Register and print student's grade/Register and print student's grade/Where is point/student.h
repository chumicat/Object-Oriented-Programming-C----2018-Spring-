/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 29, 2018
 * Last Update: Mar. 29, 2018
 * Version: v1.0
 * Problem statement: Register and print student's grade
 * Reference:
 */

#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class student
{
private:
	string name;
	int sid;
	int grade;
	float percentage();
public:
	void setDetails();
	void getDetails();
};

// return percentage
inline float student::percentage()
{
	return grade / 3.0;
}

// read data from cin
inline void student::setDetails() {
	cin >> name >> sid >> grade;
}

// show data on screen (warning included)
inline void student::getDetails() {
	cout
		<< "Student details:" << endl
		<< "Name:" << name << endl
		<< "Student Number:" << sid << endl
		<< "Total:" << grade << endl
		<< (grade > 300 ? "Total scores should be under 300!\n" : "")
		<< "Percentage:" << percentage() << endl;
}

#endif // STUDENT_H