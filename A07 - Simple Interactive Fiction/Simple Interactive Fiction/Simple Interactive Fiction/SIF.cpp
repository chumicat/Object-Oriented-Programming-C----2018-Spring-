/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 14, 2018
 * Last Update: Mar. 14, 2018
 * Version: v1.0
 * Problem statement: Simple Interactive Fiction
 * Reference:
 */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#define IFILE "script.txt"
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ostream;
using std::pair;
using std::string;
using std::to_string;
using std::unordered_map;
using std::vector;

/* Node is scene sections */
class Node {
private:
	string _sceneCode;
	string _narration;
	vector<pair<string, string>> _optionPool; // <msg, nextSceneCode>

public:
	/* Store all scene sections */
	static unordered_map<string, Node> nodePool;

	/* Constructor */
	Node() : _sceneCode(""), _narration("") {}
	Node(const string &fakeScCode) { _optionPool.emplace_back("", fakeScCode); }

	/* Get Function */
	string getSceneCode() const { return _sceneCode; }
	string getNarration() const { return _narration; }
	vector<pair<string, string>> getOptionPool () const { return _optionPool; }
	string getOptionMsg() const { 
		string msg;
		for (pair<string, string> p : _optionPool)
			msg += p.first + "\n";
		return msg;
	}
	bool optionEmpty() { return _optionPool.empty(); }

	/* Set Function */
	void setSceneCode(string::iterator it1, string::iterator it2) { _sceneCode.assign(it1, it2); }
	void resetNode() { _sceneCode = ""; _narration = ""; _optionPool.clear(); }
	void appendNarration(const string &s) { _narration += s + "\n"; }
	void addOption(int count, string::iterator msgIt1, string::iterator msgIt2, string::iterator nxtScCodIt1, string::iterator nxtScCodIt2) { _optionPool.emplace_back("(" + to_string(count) + ") " + string(msgIt1, msgIt2), string(nxtScCodIt1, nxtScCodIt2)); }

	/* Debug using to check node store and list are reight */
	friend ostream& operator<<(ostream& os, const Node& n)
	{
		os << "Scene Code: " << n.getSceneCode() << endl
			<< "Narration:" << endl << n.getNarration();
		vector<pair<string, string>> vp = n.getOptionPool();
		for (vector<pair<string, string>>::iterator it = vp.begin(); it != vp.end(); it++)
			os << it->first << ": #" << it->second << endl;
		os << endl;
		
		return os;
	}
	static void showNodePool() {
		for (unordered_map<string, Node>::iterator it = Node::nodePool.begin(); it != Node::nodePool.end(); it++)
			cout << it->second;
	}
};
/* initial static member */
unordered_map<string, Node> Node::nodePool = unordered_map<string, Node>();

int main() {
	/* Variable */
	ifstream ifs = ifstream(IFILE);
	Node node;
	int optionCounter = 0;

	/* Get all scene section data */
	string s;
	while (getline(ifs, s)) {
		if (s.empty()) { /* Empty Situation */
			Node::nodePool.emplace(node.getSceneCode(), node);
			node.resetNode();
			optionCounter = 0;
		} else if (s[0] == '#') { /* Scene Code Situation */
			node.setSceneCode(s.begin() + 1, s.end());
		} else if (s[0] == '-') { /* Options Situation */
			string::iterator sharpIt = find(s.begin() + 1, s.end(), '#');
			node.addOption(++optionCounter, s.begin() + 1, sharpIt - 1, sharpIt + 1, s.end());
		} else { /* Narration */
			node.appendNarration(s);
		}
	}

	/* Push last one since last space line will be ignored by cin */
	Node::nodePool.emplace(node.getSceneCode(), node);

	/* Interact with player */
	int num = 1;
	Node &n = Node("0");
	do {
		/* Set choice */
		string state = n.getOptionPool().at(num - 1).second;

		/* Show narration */
		n = Node::nodePool[state];
		cout << n.getNarration()
			<< n.getOptionMsg();

		/* No option means end scene */
		if (n.optionEmpty())
			break;
	} while (cin >> num);

	system("pause");
}