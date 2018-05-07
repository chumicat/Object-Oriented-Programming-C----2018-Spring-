/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 5, 2018
 * Last Update: Apr. 5, 2018
 * Version: v1.0
 * Problem statement: Monster creator
 * Reference:
 */

#include <iostream> 
#include <unordered_map>
#include "monster.h"

using namespace std;

/* declaration */
void menu();

/* main funtion */
int main() {
	/* Variable */
	int features;
	string name;
	float hp, damage, defense, speed;
	unordered_map<string, Monster> monster;

	menu();
	while (cin >> features)
	{
		switch (features) {
		case 0: /* Create monster */
			cout << "Please enter monster state" << endl;
			cin >> name >> hp >> damage >> defense >> speed;
			if (monster.count(name))
				cout << "ERROR!! This monster had exist.\n";
			else
				monster.emplace(name, Monster(name, hp, damage, defense, speed));
			break;

		case 1: /* Check state */
			cout << "Please enter monster name : ";
			cin >> name;
			if (!monster.count(name))
				cout << "ERROR!! This monster didn't exist.\n";
			else
				monster[name].PrintAllState();
			break;

		case 2: /* Change state */
			cout << "Please enter monster name : ";
			cin >> name;
			if (!monster.count(name))
				cout << "ERROR!! This monster didn't exist.\n";
			else {
				string newName;
				cout << "Please enter new state : ";
				cin >> newName >> hp >> damage >> defense >> speed;
				if (monster.count(newName) && (name != newName ))
					cout << "ERROR!! This monster had exist.\n";
				else {
					monster.erase(name);
					monster.emplace(newName, Monster(newName, hp, damage, defense, speed));
				}
			}
			break;
		}

		cout << endl;
		menu();
	}
	return 0;
}

/* print menu */
void menu()
{
	cout << "Create monster enter 0" << endl;
	cout << "Check state enter 1" << endl;
	cout << "Change state enter 2" << endl;
	cout << "Feature : ";
}
