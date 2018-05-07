/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 22, 2018
 * Last Update: Mar. 22, 2018
 * Version: v1.0
 * Problem statement: Unspoken RR Rules
 * Reference:
 */
//#include "FakeRand.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#define IFNAME "input.txt"
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ostream;
using std::ostream_iterator;
using std::queue;
using std::sort;
using std::string;
using std::stringstream;
using std::vector;

bool Win(const int &targetLv, const int &opponentLv) {
	double rate = pow(2, targetLv - opponentLv);
	return rand() / (RAND_MAX + 1.0) < rate / (rate + 1);
}

class Player {
public:
	string name;
	int level;
	int startTime;
	int restTime;
	int round = 0;
	bool trueMan = true;
	Player() :trueMan(false) {}
	Player(string iName, int iLevel, int iStartTime, int iRestTime)
		: name(iName), level(iLevel), startTime(iStartTime), restTime(iRestTime) {}
	friend ostream& operator<<(ostream& os, const Player& p)
	{
		os << p.name << " " << p.level << " " << p.startTime << " " << p.restTime << endl;
		return os;
	}
	// help to show data
	string nameAndLv() {
		stringstream ss;
		if (trueMan) {
			ss << name << " lv" << level;
			return ss.str();
		}
		else
			return "none";
	}
	static void show(const vector<Player> &v) {
		copy(v.begin(), v.end(), ostream_iterator<Player>(cout, ""));
		cout << endl;
	}
};

class Arcade {
public:
	int time = 0, thisRoundEndTime = 0;
	bool inRound = false;
	Player p1, p2;
	vector<Player> v;
	vector<Player> inLine;
	Arcade() :p1(Player()), p2(Player()){}
	// function to show each line
	void show() {
		cout << time << ": " << p1.nameAndLv() << " vs. " << p2.nameAndLv() << " | ";
		for (Player &p : inLine)
			cout << p.name << " ";
		cout << endl;
	}
	// call with loser
	void continueOrGoHomeLoser(Player &p) {
		if (p.restTime <= 0)
			p.trueMan = false;
		else {
			inLine.push_back(p);
			p.trueMan = false;
		}
	}
	// call with winner
	void continueOrGoHomeWinner(Player &p) {
		if (p.restTime <= 0)
			p.trueMan = false;
		else {
			p1 = p;
			p2.trueMan = false;
		}
	}
	void start() {
		for (time = 0; !v.empty() || !inLine.empty() || (p1.trueMan && p2.trueMan); time++) {
			bool happen = false;

			// add to inLine
			while (!v.empty() && time == v.front().startTime) {
				inLine.push_back(v.front());
				v.erase(v.begin());
				happen = true;
			}

			// end of fight and leave inLine
			if (inRound == true && thisRoundEndTime == time) {
				// calculate answer
				// pop loose player and outtime player
				// move winner to p1 (if didn't leave)
				// each round, change round signal, check if stay, leave or inLine
				p1.restTime -= 5;
				p2.restTime -= 5;
				happen = true;
				if (p1.round+1 == 5 || !Win(p1.level - 1, p2.level)) {
					// p2 win
					p1.round = 0;
					p2.round++;
					continueOrGoHomeLoser(p1);
					continueOrGoHomeWinner(p2);
				} else {
					// p1 win
					p1.round++;
					p2.round = 0;
					continueOrGoHomeLoser(p2);
					continueOrGoHomeWinner(p1);
				}
				inRound = false;
			}

			// push new player to p2 (and p1 if need) and fight (if can)
			if (inRound == false) {
				if (!p1.trueMan && !inLine.empty()) {
					p1 = inLine.front();
					inLine.erase(inLine.begin());
				}
				if (!p2.trueMan && !inLine.empty()) {
					p2 = inLine.front();
					inLine.erase(inLine.begin());
				}
				if (p1.trueMan && p2.trueMan) {
					inRound = true;
					happen = true;
					thisRoundEndTime = time + 5;
				}
			}

			// show if something happen
			if (happen) {
				show();
			}
		}
		return;
	}
};

int main() {
	ifstream ifs(IFNAME);
	int num;

	while (cin >> num) {
		// round variable
		Arcade a;

		// read data
		for (int n = 0; n < num; n++) {
			string name; int level; int startTime; int restTime;
			cin >> name >> level >> startTime >> restTime;
			a.v.emplace_back(name, level, startTime, restTime);
		}

		// sort with start time
		sort(a.v.begin(), a.v.end(), [](const Player &left, const Player &right) {return left.startTime < right.startTime; });
		
		a.start();
	}

	system("pause");
}