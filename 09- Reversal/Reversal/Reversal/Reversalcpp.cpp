/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: Mar. 12, 2018
* Last Update: Mar. 12, 2018
* Version: v1.0
* Problem statement: Reversal
* Reference:
https://stackoverflow.com/questions/4951796/how-to-reverse-an-stdstring
https://stackoverflow.com/questions/17243697/reading-a-large-text-file-in-parallel-in-c
*/

#include <algorithm>
#include <functional>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define IFNAME "words.txt"
#define HASHSIZE 8192
using std::string;
using std::vector;

std::hash<string> str_hash;
class Word {
public:
	string forwd;	// set original
	string bakwd;	// set lowercase reversed
	size_t hash;	// set lower case average hash in forward and backward
	Word(string word) : forwd(word) { 
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		bakwd = word;
		std::reverse(bakwd.begin(), bakwd.end());
		hash = (str_hash(word) + str_hash(bakwd))/2;
	}
};

string searchReversal(vector<vector<Word>> &wordList) {
	/* Search for each words group which have same number of letter */
	vector<vector<Word>> vs;
	vs.resize(HASHSIZE);
	for (int n = wordList.size() - 1; n >= 0; n--) {
		// std::cout << "[Dealing " << n+1 << " now, which has " << wordList.at(n).size() << " words]" << std::endl;
		/* Pass to hash table */
		for (int i = 0; i < wordList.at(n).size(); i++) {
			vs.at(wordList.at(n).at(i).hash % HASHSIZE).push_back(wordList.at(n).at(i));
		}
		
		/* check each hash table */
		for (int h = 0; h < HASHSIZE; h++) {
			for (int i = 0; i < vs.at(h).size(); i++) {
				for (int j = i; j < vs.at(h).size(); j++) {
					if (vs.at(h).at(i).hash == vs.at(h).at(j).hash) {
						string word = vs.at(h).at(i).forwd;
						std::transform(word.begin(), word.end(), word.begin(), ::tolower);
						if (word == vs.at(h).at(j).bakwd)
							return vs.at(h).at(i).forwd;
					}
				}
			}
		}
	}
	return "";
}

int main() 
{	/* List of words */
	vector<vector<Word>> wordList;
	
	/* Open file */
	std::ifstream ifs;
	ifs.open(IFNAME);
	
	/* Read words */
	// std::cout << "[Start read " << IFNAME << "]" << std::endl;
	string word;
	while (ifs >> word) {
		if (wordList.size() < word.size()) 
			wordList.resize(word.size());
		wordList.at(word.size() - 1).push_back(Word(word));
	}
	// std::cout << "[Finish read " << IFNAME << "]" << std::endl;

	std::cout << searchReversal(wordList) << std::endl;
	return 0;
}
