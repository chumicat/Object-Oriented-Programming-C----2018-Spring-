/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Apr. 26, 2018
 * Last Update: Apr. 26, 2018
 * Version: v1.0
 * Problem statement: Draw Board
 * Reference:
 */

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void readAndDrawRect(vector<vector<char>> &canvas) {
	int ux, uy, dx, dy; char c;
	cin >> ux >> uy >> dx >> dy >> c;
	for (int x = 0; x < canvas.size(); x++)
		for (int y = 0; y < canvas[x].size(); y++)
			if (dx <= x && x <= ux && dy <= y && y <= uy)
				canvas[x][y] = c;
	return;
}

void readAndDrawCircle(vector<vector<char>> &canvas) {
	int cx, cy, r; char c;
	cin >> cx >> cy >> r >> c;
	for (int x = 0; x < canvas.size(); x++)
		for (int y = 0; y < canvas[x].size(); y++)
			if (sqrt(pow(cx-x, 2) + pow(cy-y, 2)) <= r)
				canvas[x][y] = c;
	return;
}

void showCanvas(const vector<vector<char>> &canvas) {
	for (int y = 0; y < canvas[0].size(); y++) {
		for (int x = 0; x < canvas.size(); x++)
			cout << canvas[x][y];
		cout << endl;
	} cout << endl;
	return;
}

int main() {
	/* Set square size */
	int xSize, ySize;
	cin >> xSize >> ySize;
	vector<vector<char>> canvas(xSize, vector<char>(ySize, ' '));

	/* Switch type to function */
	string type;
	while (cin >> type) {
		if (type == "RECT") {
			readAndDrawRect(canvas);
		} else if (type == "CIRCLE") {
			readAndDrawCircle(canvas);
		} else if (type == "DRAW") {
			showCanvas(canvas);
		}
	}
}
