/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 4, 2018
 * Last Update: Apr. 4, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 */

#pragma once
#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
using std::max;
using std::string;

class Robot{
private:
	double x, y, power;
	/* Sub and check if power is positive, return true if success */
	bool subToZero(double subValue);

public:
	/*v=v=v=v=v Constructor v=v=v=v=v*/
	Robot(double x = 0, double y = 0, double power = 100);

	/*v=v=v=v=v Get Function v=v=v=v=v*/
	double getX();
	double getY();
	double getPower();

	/*v=v=v=v=v Robot Function v=v=v=v=v*/
	/* Move to direct(x, y), move 1 unit distance per power */
	void move(double x, double y);
	/* Speak */
	string speak(string content);
	/* charge the battery(power) */
	void charge(double p);
};