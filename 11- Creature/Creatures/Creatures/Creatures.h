/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID： B10332030
 * Date: May. 23, 2018
 * Last Update: May. 23, 2018
 * Version: v1.0
 * Problem statement: Creature
 * Reference:
https://stackoverflow.com/questions/17663186/initializing-a-two-dimensional-stdvector
https://stackoverflow.com/questions/11415469/setup-stdvector-in-class-constructor
 */

#pragma once
#include <iostream>
#include <random>
#include <string>
using std::cout;
using std::endl;
using std::string;

bool randWithProb(double p);
int randInRange(int lowerBound, int upperBound);

enum CreaturesType {
	HUMAN = 0,
	CYBERDEMON = 1,
	BALROG = 2,
	ELF = 3
};

class Creature
{
protected:
	/*v=v=v=v=v Member v=v=v=v=v*/
	/* 0 human, 1 cyberdemon, 2 balrog, 3 elf */
	CreaturesType type;
	/* How much damage we can inflict */
	int strength;
	/* How much damage we can sustain */
	int hitpoints;

public:
	/*v=v=v=v=v Constructor v=v=v=v=v*/
	/* Default Initialize to human, 10 strength, 10 hit points
	 * Initialize creature to new type, strength, hit points
	 * Also add appropriate accessor and mutator functions
	 * for type, strength, and hit points */
	Creature(CreaturesType type = HUMAN, int strength = 10, int hitpoints = 10);

	/*v=v=v=v=v Get Function v=v=v=v=v*/
	/* Returns type of species */
	virtual string getSpecies();
	/* Returns amount of damage this creature
	 * inflicts in one round of combat */
	virtual int getDamage();
};

class Human : public Creature {
public:
	Human(int strength = 10, int hitpoints = 10);
	string getSpecies();
	int getDamage() override final;
};

class Cyberdemon : public Creature {
public:
	Cyberdemon(int strength = 10, int hitpoints = 10);
	string getSpecies();
	int getDamage() override final;
};

class Balrog : public Creature {
public:
	Balrog(int strength = 10, int hitpoints = 10);
	string getSpecies();
	int getDamage() override final;
};

class Elf : public Creature {
public:
	Elf(int strength = 10, int hitpoints = 10);
	string getSpecies();
	int getDamage() override final;
};