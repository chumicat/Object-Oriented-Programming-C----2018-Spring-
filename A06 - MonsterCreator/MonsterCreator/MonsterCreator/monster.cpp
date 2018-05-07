/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 5, 2018
 * Last Update: Apr. 5, 2018
 * Version: v1.0
 * Problem statement: Monster creator
 * Reference:
 */

#include "monster.h"

/*v=v=v=v=v Constructor v=v=v=v=v*/
Monster::Monster(){}

Monster::Monster(string name, float hp, float damage, float defense, float speed): name(name), hp(hp), damage(damage), defense(defense), speed(speed){}

/*v=v=v=v=v Set Function v=v=v=v=v*/
void Monster::SetName(string name)
{
	this->name = name;
}

void Monster::SetHP(float hp)
{
	this->hp = hp;
}

void Monster::SetDamage(float damage)
{
	this->damage = damage;
}

void Monster::SetDefense(float defence)
{
	this->defense = defence;
}

void Monster::SetSpeed(float speed)
{
	this->speed = speed;
}

/*v=v=v=v=v Showing Function v=v=v=v=v*/
void Monster::PrintAllState()
{
	cout <<
		"Name : " << name << endl <<
		"Hp : " << hp << endl <<
		"Damage : " << damage << endl <<
		"Defence : " << defense << endl <<
		"Speed : " << speed << endl;
}

/*v=v=v=v=v Get Function v=v=v=v=v*/
string Monster::GetName()
{
	return name;
}

float Monster::GetHP()
{
	return hp;
}

float Monster::GetDamage()
{
	return damage;
}

float Monster::GetDefence()
{
	return defense;
}

float Monster::GetSpeed()
{
	return speed;
}

/*v=v=v=v=v Destructor v=v=v=v=v*/
Monster::~Monster()
{
}
