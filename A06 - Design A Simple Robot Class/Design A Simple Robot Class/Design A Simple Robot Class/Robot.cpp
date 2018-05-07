/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 4, 2018
 * Last Update: Apr. 4, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 */

#include "Robot.h"

bool Robot::subToZero(double subValue)
{
	if (power >= subValue) {
		power -= subValue;
		return true;
	} else {
		power = 0;
		return false;
	}
}

Robot::Robot(double x, double y, double power) : x(x), y(y), power(power) { this->power = max(0.0, power); }

double Robot::getX() { return this->x; }

double Robot::getY() { return this->y; }

double Robot::getPower() { return this->power; }

void Robot::move(double x, double y)
{	/* Calculate distance between target and robot */
	double targetDistance = sqrt(x*x + y*y);

	/* Check if it has enough energy to the target. */
	if (targetDistance <= power) { /* Power Enough */
		this->x += x;
		this->y += y;
		this->power -= targetDistance;
	} else { /* Power didn't enough */
		this->x += power / targetDistance * x;
		this->y += power / targetDistance * y;
		this->power = 0;
	}
	return;
}

string Robot::speak(string content)
{
	string ans;
	for (char c : content) {
		/* Expected consume */
		double consume;
		if (isupper(c)) { /* [A-Z], consume 2 */
			consume = 2.0;
			c = tolower(c);
		} else if (islower(c)) { /* [a-z], consume 1 */
			consume = 1.0;
			c = toupper(c);
		} else { /* [^A-Za-z], consume 0.5 */
			consume = 0.5;
		}
		/* Sub it */
		if (subToZero(consume))
			ans += c;
		else
			break;
	}
	return ans;
}

void Robot::charge(double p)
{
	this->power += p;
}
