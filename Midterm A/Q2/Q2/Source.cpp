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
	while (cin >> num){
		vector<int> vi;
		bool allTheSame = true;

		int first;
		cin >> first;
		vi.push_back(first);
		int input;
		for (int i = 1; i < num; i++){
			cin >> input;
			if (input != first)
				allTheSame = false;
			vi.push_back(input);
		}

		if (allTheSame){
			cout << "Yes\nAll same\n";
			continue;
		}

		vector<int> viCopy(vi);
		sort(viCopy.begin(), viCopy.end());
		if (viCopy == vi){
			cout << "Yes\nAscending order\n";
			continue;
		}

		reverse(viCopy.begin(), viCopy.end());
		if (viCopy == vi){
			cout << "Yes\nDescending order\n";
			continue;
		}
		cout << "No\n";
	}

	system("pause");
	return 0;
}