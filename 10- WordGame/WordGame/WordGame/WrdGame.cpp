/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 12, 2018
 * Last Update: Mar. 12, 2018
 * Version: v1.0
 * Problem statement: WordGame
 * Reference:
https://stackoverflow.com/questions/17663186/initializing-a-two-dimensional-stdvector
https://stackoverflow.com/questions/11415469/setup-stdvector-in-class-constructor
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define IFNAME "words.txt"
using std::ifstream;
using std::string;
using std::vector;

class WordGame {
private:
	/* Use one-deminsion vector to store char */
	vector<char> table;
	string fileName;
	/* Store neighbor offset directly */
	vector<vector<int>> nearList = {
		{ 1, 4, 5 },
		{ 0, 2, 4, 5, 6 },
		{ 1, 3, 5, 6, 7 },
		{ 2, 6, 7 },
		{ 0, 1, 5, 8, 9 },
		{ 0, 1, 2, 4, 6, 8, 9, 10 },
		{ 1, 2, 3, 5, 7, 9, 10, 11 },
		{ 2, 3, 6, 10, 11 },
		{ 4, 5, 9, 12, 13 },
		{ 4, 5, 6, 8, 10, 12, 13, 14 },
		{ 5, 6, 7, 9, 11, 13, 14, 15 },
		{ 6, 7, 10, 14, 15 },
		{ 8, 9, 13 },
		{ 8, 9, 10, 12, 14 },
		{ 9, 10, 11, 13, 15 },
		{ 10, 11, 14 }
	};
public:
	WordGame(string inputFileName) :table(vector<char>(16)), fileName(inputFileName) { }
	/* Read input from keyboard */
	void ReadTable() {
		string s;
		for (int n = 0; n < 4; n++) {
			std::cin >> s;
			table[4 * n + 0] = s[0];
			table[4 * n + 1] = s[1];
			table[4 * n + 2] = s[2];
			table[4 * n + 3] = s[3];
		}
		//std::cout << "[finish reading table]" << std::endl;
	}
	/* showing table with 4*4 */
	void ShowTable() {
		int newLineCounter = 0;
		for (int i = 0; i < 16; i++) {
			if (i / 4 != newLineCounter) {
				std::cout << std::endl;
				newLineCounter++;
			}
			std::cout << table[i] << " ";
		}
	}
	template <class T>
	void ShowVec(vector<T> v) {
		for (T t : v)
			std::cout << t << std::endl;
	}
	void ShowMap(bool map[16]) {
		int newLineCounter = 0;
		for (int i = 0; i < 16; i++) {
			if (i / 4 != newLineCounter) {
				std::cout << std::endl;
				newLineCounter++;
			}
			std::cout << map[i] << " ";
		}
	}
	/* list each c mit in table */
	vector<int> InTable(char c) {
		vector<int> posList;
		for (int n=0;n<table.size(); n++)
			if (table.at(n) == c)
				posList.push_back(n);
		return posList;
	}
	/* list each c availabe around index */
	vector<int> InNear(char c, const int &index, bool map[16]) {
		vector<int> posList;
		for (int n : nearList[index])
			if (!map[n] && c == table[n])
				posList.push_back(n);
		return posList;
	}
	bool Search(string s) {
		/* Prepare map(false for unused) and get first char(reverse direction) */
		bool map[16] = {false};
		char now = s.back();
		s.pop_back();

		/* Check if need to search */
		vector<int> startPos = InTable(now);
		if (startPos.empty())
			return false;

		/* Start in each possible pos */
		for (int n : startPos) {
			map[n] = true;
			if (RecursiveSearch(s, n, map))
				return true;
			map[n] = false;
		}
		return false;
	}
	bool RecursiveSearch(string s, const int &index, bool map[16]) {
		/* If nothing in s means target finish */
		if (s.empty())
			return true;

		/* Prepare map(false for unused) and get char(reverse direction) */
		char now = s.back();
		s.pop_back();

		/* Check if nearby */
		vector<int> nextPos = InNear(now, index, map);
		if (nextPos.empty())
			return false;

		/* Start in each possible pos */
		for (int n : nextPos) {
			map[n] = true;
			if (RecursiveSearch(s, n, map))
				return true;
			map[n] = false;
		}
		return false;
	}
	/* Search file and print at the same time */
	void SearchAndPrintFile() {
		ifstream ifs;
		ifs.open(fileName);

		string word;
		while (ifs >> word) {
			if (Search(word))
				std::cout << word << std::endl;
		}
	}
};

int main() {
	WordGame wg(IFNAME);
	bool flag = true;
	while (flag) {
		std::cout << "[Input:]" << std::endl;
		wg.ReadTable();
		std::cout << "[Fit:]" << std::endl;
		wg.SearchAndPrintFile();
		std::cout << "[Finish]" << std::endl << "[Continue?(1 for yes/0 for no)]: ";
		std::cin >> flag;
	}
}

