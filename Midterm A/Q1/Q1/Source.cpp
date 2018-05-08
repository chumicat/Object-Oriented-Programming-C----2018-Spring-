#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){
	int num;
	cin >> num;

	// Read Player
	unordered_map<string, int> umsi;
	vector<string> vs;
	string name;
	for (int i = 0; i < num; i++){
		cin >> name;
		umsi.emplace(name, 1000);
		vs.push_back(name);
	}

	// Play
	int value, winnerNum;
	while (cin >> name >> value >> winnerNum){
		if (winnerNum == 0)
			continue;
		int prize = value / winnerNum;
		umsi[name] -= (value / winnerNum) * winnerNum;

		for (int i = 0; i < winnerNum; i++){
			string winner;
			cin >> winner;
			umsi[winner] += prize;
		}
	}

	for (string s : vs){
		cout << s << " " << umsi[s] << endl;
	}

	system("pause");
	return 0;
}