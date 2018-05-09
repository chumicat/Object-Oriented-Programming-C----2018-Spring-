#pragma once
/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: May. 6, 2018
 * Last Update: May. 6, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 */

/*=v=v=v=v=v= Include =v=v=v=v=v=*/
#include <algorithm> /* for_each() */
#include <assert.h> /* assert() */
#include <bitset> /* bitset */
#include <fstream> /* ifstream */
#include <iostream> /* istream, cin, cout, endl */
#include <string> /* string */
#include <unordered_map> /* unordered_map */
#include <unordered_set> /* unordered_set */
#include <utility> /* pair */
#include <vector> /* vector */

/*=v=v=v=v=v= Define =v=v=v=v=v*/
#define NDEBUG /* not using assert and do not show debug message. (Release Mode will define this automatically) */
#define ROWSIZE 9 /* size of row */
#define COLSIZE 9 /* size of column */
#define ROWDIV 3 /* number to depart row into block */
#define COLDIV 3 /* number to depart column into block */
#define NULLCHAR 'n' /* This character means the pos hadn't been set number */
#define MARKSTR "@" /* Showing mark in show function */
#define BKIDX(row, col) (ROWDIV * (row / ROWDIV) + (col / COLDIV)) /* Calculate index of block with row and column */
/* All kinds of assert */
#define SIZE_RESTRICTOR(rowSize, colSize) \
	assert((rowSize == ROWSIZE) && "Row Size Restrict Error"); \
	assert((colSize == COLSIZE) && "Col Size Restrict Error");
#define SIZE_CHECKER(rowSize, colSize) \
	assert((rowSize > 0) && "Row Size Error"); \
	assert((colSize > 0) && "Cow Size Error"); \
	assert((rowSize % ROWDIV == 0) && "Row Size DIV Error"); \
	assert((colSize % COLDIV == 0) && "Col Size DIV Error");
#define VALUE_CHECKER(value) \
	assert(((value >= '1' && value <= '9') || value == NULLCHAR) && "Value Error");
#define OVERWRITE_CHECKER(row, col, value) \
	assert((pos.at(row).at(col)==NULLCHAR) && "Overwrite Error");

/*=v=v=v=v=v= Typedef, namespace, enumeration =v=v=v=v=v=*/
typedef char Digit;
using std::bitset;
using std::istream;
using std::ifstream;
using std::pair;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
enum ShowIdx {
	TABLEIDX = 0,
	ROWIDX = 1,
	COLIDX = 2,
	BKIDX = 3,
	PSBNUMIDX = 4,
	EACHNUMIDX = 5,
	SHOWSTYLESIZE = 6
};
enum ShowStyle {
	TABLE = 1,
	ROW = 2,
	COL = 4,
	BK = 8,
	PSBNUM = 16,
	EACHNUM = 32
};
enum Solve{
	NOSOLVE = -1,
	PARTIALSOLVE = 0,
	TOTALSOLVE = 1
};

/// pos construct diagram:
///       col col col
///       012 345 678   vec
///                      v 
/// row 0 b   b   b      v>>>>>>>>>
/// row 1  k   k   k     v>>>>>>>>>
/// row 2   0   1   2    v>>>>>>>>>
///                      v
/// row 3 b   b   b      v>>>>>>>>>
/// row 4  k   k   k     v>>>>>>>>>
/// row 5   3   4   5    v>>>>>>>>>
///                      v
/// row 6 b   b   b      v>>>>>>>>>
/// row 7  k   k   k     v>>>>>>>>>
/// row 8   6   7   8    v>>>>>>>>>
class SudokuSolver {
private:
	/*=v=v=v=v= Member =v=v=v=v=*/
	bool noChangeFlag_inPos = false, noChangeFlag_inGrp = false, unableToSolve = false; /* Flag */
	static unordered_set<Digit> digitSet; /* All digit that you will use. Used when we calcualate diff between set */
	vector<vector<Digit>> pos; /* Plane of sudoku, (row, col) */
	vector<unordered_set<Digit>> row; /* Store each row exist Digit */
	vector<unordered_set<Digit>> col; /* Store each column exist Digit */
	vector<unordered_set<Digit>> bk; /* Store each block exist Digit */


	/*=v=v=v=v= Function =v=v=v=v=*/
	/* Set value to (row, col) wich checking and set to set automatically. */
	inline void setWith(size_t row, size_t col, Digit value); 
	/* This function should be called before read now data */
	inline void preProcess(size_t rowSize, size_t colSize); 
	/* Return all possible Digit in (row, col) */
	inline unordered_set<Digit> possible(size_t row, size_t col) const; 
	/* Count how many acceptable pos for d in number grp(0~8) of (TABLE/ROW/COL/BK) and return pos pair set */
	inline size_t countAndList(ShowStyle type, size_t grp, Digit d, vector<pair<size_t, size_t>> &reVec) const; 
	/* Fill the only choice for specific pos */
	Solve fillOnlyInPos(); 
	/* Fill the only choice for specific group */
	Solve fillOnlyInGrp(); 
	/* Assum value and recursive solve the problem */
	Solve assumeSolve(); /* Assum value and recursive solve the problem */

public:
	/* Default constructor */
	SudokuSolver();
	/* Constructor that set with another pos (just call read) */
	SudokuSolver(const vector<vector<Digit>>& pos);
	/* Solve the problem */
	Solve solve(); 
	/* Read from istream */
	void read(istream &input, size_t rowSize = ROWSIZE, size_t colSize = COLSIZE); 
	/* Read from another pos */
	void read(const vector<vector<Digit>>& pos);
	/* Show the plane */
	void show(size_t ss = TABLE) const; 
};