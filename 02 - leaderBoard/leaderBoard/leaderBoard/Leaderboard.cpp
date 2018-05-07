/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: Mar. 6, 2018
* Last Update: Mar. 6, 2018
* Version: v1.1
* Problem statement: Leader board
* Reference:
http://www.cplusplus.com/reference/algorithm/sort/
https://dotblogs.com.tw/v6610688/2013/11/27/introduction_inline_function
http://en.cppreference.com/w/cpp/language/lambda
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#define IFNAME "scores.txt"
#define SHOWNUM 3
using std::ifstream;
using std::string;
using std::vector;

/* Babylonian algorithm */
typedef struct scoreboard {
	string name;
	int score;
}scoreBoard;

int getHighScores(string name[SHOWNUM], int score[SHOWNUM]) {
	ifstream ifs;
	ifs.open(IFNAME);

	/* Check if file end or not in a good format */
	vector<scoreBoard> sb;
	string iName;
	int iScore;
	while (ifs >> iName >> iScore) {
		if (sb.size() < 3) {
			sb.push_back({ iName,iScore });
			std::sort(sb.begin(), sb.end(), [](scoreBoard sb1, scoreBoard sb2) {return sb1.score > sb2.score; });
		} else if (sb.at(2).score < iScore) {
			sb.at(2) = { iName, iScore };
			std::sort(sb.begin(), sb.end(), [](scoreBoard sb1, scoreBoard sb2) {return sb1.score > sb2.score; });
		}
	}
	
	for (int n = 0; n < SHOWNUM && n < sb.size(); n++) {
		name[n] = sb[n].name;
		score[n] = sb[n].score;
	}

	ifs.close();
	return sb.size();
}

int main()
{
	string names[SHOWNUM];
	int scores[SHOWNUM];
	int size = getHighScores(names, scores);
	if (size == 0) {
		std::cout << "test";
	}
	for (int n = 0; n < SHOWNUM && n < size; n++) {
		std::cout << names[n] << std::endl << scores[n] << std::endl;
	}
	system("pause");
	return 0;
}
