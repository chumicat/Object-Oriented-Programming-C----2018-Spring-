/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: May. 6, 2018
 * Last Update: May. 6, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 */
#include "SudokuSolver.h"
#define IFILE "Question.txt"

int main() {
	SudokuSolver ss;
	ifstream ifs(IFILE);

	while (ifs.peek() != EOF)
	{
		ss.read(ifs, 9, 9);
		//ss.show(TABLE | ROW | COL | BK | PSBNUM | EACHNUM);
		ss.solve();
		ss.show();
		//ss.show(TABLE | ROW | COL | BK | PSBNUM | EACHNUM);
	}
	system("pause");
}