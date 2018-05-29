/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 14, 2018
 * Last Update: Mar. 14, 2018
 * Version: v1.0
 * Problem statement: Convert minutes to HMS format
 * Reference:
 */

#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#define IFNAME "name.txt"
#define SIZE 8192
using std::string;
using std::vector;
std::hash<string> str_hash;

template <class T>
class set {
private:
	vector<vector<T>> v;
	vector<T> list;
public:
	set() : v(SIZE){}
	void insert(T t) {
		int index = str_hash(t) % SIZE;

		bool match = false;
		if (!v.at(index).empty())
			for (T s : v.at(index))
				if (s == t) {
					match = true;
					break;
				}

		if (match)
			return;

		v.at(index).push_back(t);
		list.push_back(t);
	}
	T & operator[] (int i) {
		return list[i];
	}
	size_t size() { return list.size(); }
};

int main() {
	std::ifstream ifs(IFNAME);
	set<string> s;
	while (ifs.peek() != EOF)
	{
		string name;
		std::getline(ifs, name);
		s.insert(name);
	}
	for (size_t i = 0; i < s.size(); ++i)
		std::cout << s[i] << std::endl;

	return 0;
}