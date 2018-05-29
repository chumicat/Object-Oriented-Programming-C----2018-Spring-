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

#include "Creatures.h"

/*v=v=v=v=v Random v=v=v=v=v*/
/* Random from device */
std::random_device rd;
/* Using Mersenne twister as Random Engine (will set seed with rd) */
std::mt19937 generator(rd());

bool randWithProb(double p){
	/* Set random distribution that set to [0.0, 1.0]*/
	std::uniform_real_distribution<float> unif_r(0.0, 1.0);
	return unif_r(generator) < p;
}

int randInRange(int lowerBound, int upperBound) {
	/* Set random distribution */
	std::uniform_int_distribution<int> unif_i(lowerBound, upperBound);
	return unif_i(generator);
}

Creature::Creature(CreaturesType type, int strength, int hitpoints) : type(type), strength(strength), hitpoints(hitpoints)
{
}

string Creature::getSpecies()
{
	return "Unknown (Base Class didn't offerd this function)";
}

int Creature::getDamage()
{
	int damage = randInRange(1, strength);
	cout << getSpecies() << " attacks for " << damage << " points!" << endl;
	return damage;
}

Human::Human(int strength, int hitpoints) : Creature(HUMAN, strength, hitpoints) 
{
}

string Human::getSpecies()
{
	return "Human";
}

int Human::getDamage()
{	
	int damage = Creature::getDamage();
	return damage;
}

Cyberdemon::Cyberdemon(int strength, int hitpoints) : Creature(CYBERDEMON, strength, hitpoints)
{
}

string Cyberdemon::getSpecies()
{
	return "Cyberdemon";
}

int Cyberdemon::getDamage()
{
	int damage = Creature::getDamage();
	if (randWithProb(0.05)) {
		cout << "Demonic attack inflicts 50  additional damage points!" << endl;
		damage += 50;
	}
	return damage;
}

Balrog::Balrog(int strength, int hitpoints) : Creature(BALROG, strength, hitpoints)
{
}

string Balrog::getSpecies()
{
	return "Balrog";
}

int Balrog::getDamage()
{
	int damage = Creature::getDamage(), damage2;
	if (randWithProb(0.05)) {
		cout << "Demonic attack inflicts 50  additional damage points!" << endl;
		damage += 50;
	}
	damage2 = randInRange(1, strength)/* + 50 * randWithProb(0.05)*/;
	cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
	return	damage + damage2;
}

Elf::Elf(int strength, int hitpoints) : Creature(ELF, strength, hitpoints)
{
}

string Elf::getSpecies()
{
	return "Elf";
}

int Elf::getDamage()
{
	int damage = Creature::getDamage();
	if (randWithProb(0.1)) {
		cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
		damage <<= 1;
	}
	return damage;
}


