/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 26, 2018
 * Last Update: Apr. 26, 2018
 * Version: v1.0
 * Problem statement: Hungry Catpillar
 * Reference:
 */

#include "caterpillar.h"

void Caterpillar::eat()
{
	string s;
	cin >> s;
	for (char c : s)
		body.insert(body.begin(), c);
	return;
}

void Caterpillar::pull()
{
	int n;
	cin >> n;
	if (n >= body.size())
		body.clear();
	else
		body.erase(body.end()-n, body.end());
	return;
}

void Caterpillar::throws()
{
	int n;
	cin >> n;
	if (n >= body.size())
		body.clear();
	else
		body.erase(body.begin(), body.begin()+n);
	return;
}

void Caterpillar::consume()
{
	string s;
	cin >> s;
	int found = 0;
	while ((found = body.find_first_of(s, found)) != string::npos)
		body.erase(body.begin()+found);
	return;
}

void Caterpillar::sort()
{
	std::sort(body.begin(), body.end(), std::greater<char>());
}

void Caterpillar::show()
{
	cout << "@-";
	for (char c : body)
		cout << c << "-";
	cout << "*" << endl;
}
