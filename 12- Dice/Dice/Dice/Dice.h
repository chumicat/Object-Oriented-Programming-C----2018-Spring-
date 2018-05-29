#pragma once
/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 7, 2018
 * Last Update: Mar. 7, 2018
 * Version: v1.0
 * Problem statement: Convert minutes to HMS format
 * Reference:
 */
#include <cstdlib>
#include <time.h>

class Dice
{
public:
	Dice();
	Dice(int numSides);
	virtual int rollDice() const;
protected:
	int numSides;
};

Dice::Dice()
{
	numSides = 6;
	srand(time(NULL)); // Seeds random number generator
}

Dice::Dice(int numSides)
{
	this->numSides = numSides;
	srand(time(NULL)); // Seeds random number generator
}

int Dice::rollDice() const
{
	return (rand() % numSides) + 1;
}

// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2)
{
	return die1.rollDice() + die2.rollDice();
}

class LoadedDice : public Dice {
public:
	LoadedDice() : Dice() {}
	LoadedDice(int numSides) : Dice(numSides) {}
	int rollDice() const {
		if (rand() % 2)
			return numSides;
		else
			Dice::rollDice();
	}
};