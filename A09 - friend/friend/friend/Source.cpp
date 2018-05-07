/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 26, 2018
 * Last Update: Apr. 26, 2018
 * Version: v1.0
 * Problem statement: Draw Board
 * Reference:
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
	/* Read num */
	int N, M, Q;
	cin >> N >> M >> Q;

	/* Read N lines connection and M lines testing */
	vector<unordered_set<int>> group;
	int A, B;
	for (int n = 0; n < M; n++) {
		/* Read this pair */
		vector<int> inGroupIdx;
		cin >> A >> B;

		/* Remember each possible connection */
		for (int num = 0; num < group.size(); num++) 
			if (group[num].count(A) || group[num].count(B))
				inGroupIdx.push_back(num);

		/* action */
		if (inGroupIdx.empty()) { /* create new since no firend */
			group.push_back(unordered_set<int>({ A, B }));
		} else if (inGroupIdx.size() == 1) { /* join the only one group */
			group[inGroupIdx.front()].insert(A);
			group[inGroupIdx.front()].insert(B);
		} else { /* Merge multiple into one */
			for (int i = inGroupIdx.size()-1; i > 0; i--) {
				group[inGroupIdx.front()].insert(group[inGroupIdx[i]].begin(), group[inGroupIdx[i]].end());
				group.erase(group.begin()+inGroupIdx[i]);
			}
		}
	}
	for (int n = 0; n < Q; n++) {
		/* Read this pair */
		cin >> A >> B;
		for (auto &s : group)
			if (s.count(A) != s.count(B)) {
				cout << ":(" << endl;
				break;
			} else if (s.count(A) == true && s.count(B) == true) {
				cout << ":)" << endl;
			}
	}
}