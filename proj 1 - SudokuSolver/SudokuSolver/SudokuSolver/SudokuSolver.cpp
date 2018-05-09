#include "SudokuSolver.h"
/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: May. 6, 2018
 * Last Update: May. 6, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
 */

unordered_set<Digit> SudokuSolver::digitSet = {
	'1', '2', '3', '4', '5', '6', '7', '8', '9'
};

inline void SudokuSolver::setWith(size_t row, size_t col, Digit value)
{	/* Pre Check */
	VALUE_CHECKER(value);
	OVERWRITE_CHECKER(row, col, value);

	this->pos[row][col] = value;
	if (value != NULLCHAR) {
		auto rowSuc = this->row[row].insert(value);
		auto colSuc = this->col[col].insert(value);
		auto bkSuc = this->bk[BKIDX(row, col)].insert(value);
		
		/* Post Check */
		assert((rowSuc.second && colSuc.second && bkSuc.second) && "Unable to Solve Error");
		if (!(rowSuc.second && colSuc.second && bkSuc.second))
			unableToSolve = true;
	}
	return;
}

inline void SudokuSolver::preProcess(size_t rowSize, size_t colSize)
{	/* Pre Check */
	SIZE_RESTRICTOR(rowSize, colSize);
	SIZE_CHECKER(rowSize, colSize);

	/* Allocate */
	this->pos.clear();
	this->pos.resize(rowSize, vector<Digit>(colSize, NULLCHAR));
	this->row.clear();
	this->row.resize(rowSize);
	this->col.clear();
	this->col.resize(colSize);
	this->bk.clear();
	this->bk.resize(rowSize / ROWDIV * colSize / COLDIV);
}

inline unordered_set<Digit> SudokuSolver::possible(size_t row, size_t col) const
{
	unordered_set<Digit> nearby(this->row[row]), ans;
	nearby.insert(this->col[col].begin(), this->col[col].end());
	nearby.insert(this->bk[BKIDX(row, col)].begin(), this->bk[BKIDX(row, col)].end());
	std::for_each(digitSet.begin(), digitSet.end(), [&](Digit d) {if (!nearby.count(d))ans.insert(d); });
	return ans;
}

/// return -1 for no solution
/// return 0 for already exist d in that grp
/// otherwise, return count of acceptable pos for d in that group 
inline size_t SudokuSolver::countAndList(ShowStyle type, size_t grp, Digit d, vector<pair<size_t, size_t>>& reVec) const
{
	size_t counter = 0;
	bool noSolveError = true;
	reVec.clear();
	switch (type) {
	case TABLE:
		for (size_t row = 0; row < this->pos.size(); row++)
			for (size_t col = 0; col < this->pos[row].size(); col++)
				if (this->pos[row][col] == NULLCHAR && possible(row, col).count(d)) {
					counter++;
					reVec.emplace_back(row, col);
				} else if (this->pos[row][col] == d) 
					noSolveError = false;
		return (((counter == 0) && noSolveError) ? -1 : counter);
	case ROW:
		for (size_t col = 0; col < this->pos[grp].size(); col++)
			if (this->pos[grp][col] == NULLCHAR && possible(grp, col).count(d)) {
				counter++;
				reVec.emplace_back(grp, col);
			} else if (this->pos[grp][col] == d)
				noSolveError = false;
		return (((counter == 0) && noSolveError) ? -1 : counter);
	case COL:
		for (size_t row = 0; row < this->pos.size(); row++)
			if (this->pos[row][grp] == NULLCHAR && possible(row, grp).count(d)) {
				counter++;
				reVec.emplace_back(row, grp);
			} else if (this->pos[row][grp] == d)
				noSolveError = false;
		return (((counter == 0) && noSolveError) ? -1 : counter);
	case BK:
		for (size_t bkRow = (grp / ROWDIV) * ROWDIV; bkRow < (grp / ROWDIV + 1) * ROWDIV; bkRow++)
			for (size_t bkCol = (grp % COLDIV) * COLDIV; bkCol < (grp % COLDIV + 1) * COLDIV; bkCol++)
				if (this->pos[bkRow][bkCol] == NULLCHAR && possible(bkRow, bkCol).count(d)) {
					counter++;
					reVec.emplace_back(bkRow, bkCol);
				} else if (this->pos[bkRow][bkCol] == d)
					noSolveError = false;
		return (((counter == 0) && noSolveError) ? -1 : counter);
	default:
		throw;
	}
}

/// return NOSOLVE (-1) for unable to solve
/// return PARTIALSOLVE (0) for partial solve
/// return TOTALSOLVE (1) for total solve
Solve SudokuSolver::fillOnlyInPos()
{
	bool dirty = true;
	bool allfilled;
	size_t roundCounter = 0;
	/* Keep fill in the only choice for pos until no change anymore */
	while (dirty) {
		dirty = false;
		allfilled = true;
		for (size_t row = 0; row < this->pos.size(); row++) {
			for (size_t col = 0; col < this->pos[row].size(); col++) {
				if (pos[row][col] == NULLCHAR) {
					allfilled = false;
					auto a = possible(row, col);
					if (a.size() == 0) {
						return NOSOLVE;
					} else if (a.size() == 1) {
						dirty = true;
						setWith(row, col, *a.begin());
					}
				}
			}
		}
#ifndef NDEBUG
		std::cout << "===============fillOnlyInPos=================\n";
#endif //NDEBUG
		roundCounter++;
	}
	if (roundCounter == 1)
		noChangeFlag_inPos = true;
	else {
		noChangeFlag_inPos = false;
		noChangeFlag_inGrp = false;
	}
	return allfilled ? TOTALSOLVE : PARTIALSOLVE;
}

/// return NOSOLVE (-1) for unable to solve
/// return PARTIALSOLVE (0) for partial solve
/// return TOTALSOLVE (1) for total solve
Solve SudokuSolver::fillOnlyInGrp()
{
	bool dirty = true;
	size_t roundCounter = 0;
	auto funct = [&](ShowStyle type)->Solve {
		size_t solvedNum = 0;
		for (size_t grp = 0; grp < ROWSIZE; grp++) {
			for (Digit d = '1'; d <= '9'; d++) {
				vector<pair<size_t, size_t>> reVec;
				size_t count = countAndList(type, grp, d, reVec);
				switch (count) {
				case -1:
					return NOSOLVE;
				case 0:
					solvedNum++;
					break;
				case 1:
					dirty = true;
					this->setWith(reVec.front().first, reVec.front().second, d);
					break;
				}
			}
		}
		return (solvedNum == ROWSIZE * COLSIZE) ? TOTALSOLVE : PARTIALSOLVE;
	};

	/* Keep fill in the only choice for grp until no change anymore */
	while (dirty)
	{
		dirty = false;
		Solve r = funct(ROW);
		Solve c = funct(COL);
		Solve b = funct(BK);
		if (r == NOSOLVE || c == NOSOLVE || b == NOSOLVE)
			return NOSOLVE;
		else if (r == TOTALSOLVE || c == TOTALSOLVE || b == TOTALSOLVE)
			return TOTALSOLVE;
#ifndef NDEBUG
		std::cout << "===============fillOnlyInGrp=================\n";
#endif //NDEBUG
		roundCounter++;
	}
	if (roundCounter == 1)
		noChangeFlag_inGrp = true;
	else {
		noChangeFlag_inPos = false;
		noChangeFlag_inGrp = false;
	}
	return PARTIALSOLVE;
}

Solve SudokuSolver::assumeSolve()
{
	size_t minCount = ROWSIZE * COLSIZE;
	Digit targetDigit = 0;
	vector<pair<size_t, size_t>> nextTry;

	/* Choose one number that has least possible pos and try recursively */
	for (Digit d = '1'; d <= '9'; d++) {
		vector<pair<size_t, size_t>> tmp;
		int count = countAndList(TABLE, 0, d, tmp);
		if (count < minCount && count != 0) {
			targetDigit = d;
			minCount = count;
			nextTry = tmp;
		}
	}

	for (auto posPair : nextTry) {
#ifndef NDEBUG
		std::cout << "===============assume(" << posPair.first << "," << posPair.second << ")=" << targetDigit << "=================\n";
#endif //NDEBUG
		SudokuSolver ss(this->pos);
		ss.setWith(posPair.first, posPair.second, targetDigit);
		Solve result = ss.solve();
		if (result == TOTALSOLVE) {
#ifndef NDEBUG
			std::cout << "=============assume(" << posPair.first << "," << posPair.second << ")=" << targetDigit << " success===========\n";
#endif //NDEBUG
			this->pos = ss.pos;
			return TOTALSOLVE;
		} else if (result == NOSOLVE){
#ifndef NDEBUG
			std::cout << "=============assume(" << posPair.first << "," << posPair.second << ")=" << targetDigit << " fail==============\n";
#endif //NDEBUG
			continue;
		}
	}
	return NOSOLVE;
}

SudokuSolver::SudokuSolver()
{
}

SudokuSolver::SudokuSolver(const vector<vector<Digit>>& pos)
{
	read(pos);
}

Solve SudokuSolver::solve()
{	
	if (unableToSolve) {
		std::cout << "Unable to solve\n";
		return NOSOLVE;
	}
	bool finish = false;
	size_t state = 0;
	Solve s;
	while (!finish) {
		switch (state) {
		case 0:
			if (s = fillOnlyInPos()) finish = true;
			if (s = fillOnlyInGrp()) finish = true;
			if (noChangeFlag_inPos && noChangeFlag_inGrp) state = 1;
			break;
		case 1:
			return assumeSolve();
		}
	}
	return s;
}

void SudokuSolver::read(istream & input, size_t rowSize, size_t colSize)
{	/* Pre Process */
	preProcess(rowSize, colSize);

	/* Read and pass to pos */
	for (size_t row = 0; row < rowSize; row++) {
		for (size_t col = 0; col < colSize; col++) {
			Digit value;
			input >> value;
			setWith(row, col, value);
		}
	}
}

void SudokuSolver::read(const vector<vector<Digit>>& pos)
{	/* Pre Process */
	preProcess(pos.size(), pos.at(0).size());

	/* Check element one by one and constructor set */
	for (size_t row = 0; row < this->pos.size(); row++)
		for (size_t col = 0; col < this->pos.size(); col++)
			setWith(row, col, pos.at(row).at(col));
}

void SudokuSolver::show(size_t ss) const
{
	bitset<SHOWSTYLESIZE> b(ss);
	if (b[TABLEIDX]) {
		for (size_t row = 0; row < this->pos.size(); row++) {
			std::cout << " ---------  ---------  ---------\n";
			for (size_t col = 0; col < this->pos[row].size(); col++)
				std::cout << "¡U" << pos[row][col] << ((col % COLDIV == COLDIV - 1) ? "¡U" : "");
			std::cout << std::endl << ((row % ROWDIV == ROWDIV - 1) ? " ---------  ---------  ---------\n" : "");
		}
	}
	if (b[ROWIDX]) {
		std::cout << "Row:123456789\n";
		for (size_t row = 0; row < this->row.size(); row++) {
			std::cout << "  " << row << ":";
			for (char c = '1'; c <= '9'; c++)
				std::cout << (this->row[row].count(c) ? MARKSTR : " ");
			std::cout << std::endl;
		}
	}
	if (b[COLIDX]) {
		std::cout << "Col:123456789\n";
		for (size_t col = 0; col < this->col.size(); col++) {
			std::cout << "  " << col << ":";
			for (char c = '1'; c <= '9'; c++)
				std::cout << (this->col[col].count(c) ? MARKSTR : " ");
			std::cout << std::endl;
		}
	}
	if (b[BKIDX]) {
		std::cout << "Bk: 123456789\n";
		for (size_t bk = 0; bk < this->bk.size(); bk++) {
			std::cout << "  " << bk << ":";
			for (char c = '1'; c <= '9'; c++)
				std::cout << (this->bk[bk].count(c) ? MARKSTR : " ");
			std::cout << std::endl;
		}
	}
	if (b[PSBNUMIDX]) {
		std::cout << "Psb:012345678\n";
		for (size_t row = 0; row < this->pos.size(); row++) {
			std::cout << "  " << row << ":";
			for (size_t col = 0; col < this->pos[row].size(); col++)
				if (this->pos[row][col] == NULLCHAR)
					std::cout << possible(row, col).size();
				else
					std::cout << " ";
			std::cout << std::endl;
		}
	}
	if (b[EACHNUMIDX]) {
		size_t tmp;
		std::cout << "Num: 123456789\n";
		for (size_t row = 0; row < this->pos.size(); row++) {
			std::cout << "row" << row << ":";
			for (Digit d = '1'; d <= '9'; d++)
				std::cout << countAndList(ROW, row, d, vector<pair<size_t, size_t>>());
			std::cout << std::endl;
		}
		for (size_t col = 0; col < this->pos.size(); col++) {
			std::cout << "col" << col << ":";
			for (Digit d = '1'; d <= '9'; d++)
				std::cout << countAndList(COL, col, d, vector<pair<size_t, size_t>>());
			std::cout << std::endl;
		}
		for (size_t bk = 0; bk < this->pos.size(); bk++) {
			std::cout << "bk" << bk << ": ";
			for (Digit d = '1'; d <= '9'; d++)
				std::cout << countAndList(BK, bk, d, vector<pair<size_t, size_t>>());
			std::cout << std::endl;
		}
	}
}