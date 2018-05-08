#include "Starve.h"
#include <iostream>
using namespace std;

int main()
{
	//default settings
	char name[10];
	string command;
	Food meat(20, 10);
	Food vegetable(10, 20);
	Food badMeat(10, -10);
	cout << "Please give your character a name" << endl;
	cin >> name;
	Character player(100, 100, name);
	cout << "Your story starts !" << endl;


	while (getline(cin,command))
	{
		int now = -1;
		while (true){
			int j = command.find("jerky", now + 1);
			int c = command.find("carrot", now + 1);
			int m = command.find("monster meat", now + 1);

			if (j == -1 && c == -1 && m == -1)
				break;

			j = j == -1 ? INT_MAX : j;
			c = c == -1 ? INT_MAX : c;
			m = m == -1 ? INT_MAX : m;
			
			now = min(j, min(c, m));
			if (now == j)
				player.feast(meat);
			else if (now == c)
				player.feast(vegetable);
			else if (now == m)
				player.feast(badMeat);
		}


		if (command == "end"||command =="End")
			break;
		player.show();
	
	}

	system("pause");

}