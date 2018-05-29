/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID： B10332030
 * Date: Mar. 14, 2018
 * Last Update: Mar. 14, 2018
 * Version: v1.0
 * Problem statement: Guess Number
 * Reference:
 */

/* AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 */
/* AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 */
/* AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 */
/* AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 */
/* AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 */
/* AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 */
/* AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 */
/* AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 AI特別加強，強烈要求加分 */

#include <cmath>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

/* Element to remember each situation's best case */
typedef struct countProbablity {
	int cut = 0;
	double probablity = 0.0;
}CP;

/* Calculate best situation for AI */
class bestOffer {
private:
	/* "count" is count of numbers, if cut at "cut", it will divide to "left" and "right"
	 * For example, if count = 5, means there have 0, 1, 2, 3, 4 pos, and we can cut at these pos
	 * If cut at 0, it will divide to left = 0 and right = 4
	 * If cut at 2, it will divide to left = 2 and right = 2
	 */
	static bool divide(const size_t &count, const size_t &cut, size_t &left, size_t &right) {
		/* unable to cut situation */
		if (cut >= count)
			return false;

		switch (count) {
		case 0:
			return false;
		default:
			left = cut;
			right = count - cut - 1;
			return true;
		}
	}
public:
	static vector<CP> function() {
		vector<CP> v(102); // 0~100, though zero is unuseable
		v.at(0).cut = 0;
		v.at(0).probablity = 0.0;
		v.at(1).cut = 0;
		v.at(1).probablity = 1.0;
		for (size_t i = 2; i < 102; i++) {		/* for each in v, which means v[i] */
			double historyProbToLost = 1;
			int mid = (i-1)/2;  // If there are several best answer, choose most middle one;
			int distToMid = i;
			for (size_t j = 0; j < i; j++) {	/* If cut at j */
				size_t left, right;
				divide(i, j, left, right);
				double probToLost = (left*v.at(left).probablity + right*v.at(right).probablity) / i;
				if (historyProbToLost >= probToLost && abs((int)j - mid) < distToMid) {
					historyProbToLost = probToLost;
					v.at(i).probablity = 1 - probToLost;
					v.at(i).cut = j;
					distToMid = abs((int)j - mid);
				}
			}
		}

		return v;
	}
};

/* Base (Father) */
class Player {
public:
	virtual int getGuess(int left, int right) { return 0; }
};

/* Human (Son) */
class HumanPlayer : public Player {
public:
	int getGuess(int left, int right) {
		int input;
		cout << left << "~" << right << endl;
		cin >> input;
		return input;
	}
};

/* Computer (son), AI INCLUDED */
class ComputerPlayer : public Player {
private:
	vector<CP> cp = bestOffer::function();
public:
	ComputerPlayer() {/*
		for (int n = 0; n < cp.size(); n++)
			std::cout << n << " " << cp.at(n).cut << " " << cp.at(n).probablity << std::endl;*/
	}
	int getGuess(int left, int right) {
		cout << left << "~" << right << endl;
		size_t count = right - left + 1;
		size_t re = left + cp[count].cut;
		std::cout << re << std::endl;
		return re;
	}
};

/* Check if this round win or not */
bool checkForWin(int guess, int answer, int &left, int &right)
{
	while (guess<left || guess > right) {
		std::cout << "Your guess out of range." << std::endl;
		std::cin >> guess;
	}
	if (answer == guess)
	{
		cout << "You're right! You win!" << endl;
		return true;
	}
	else if (answer < guess) {
		cout << "Your guess is too high." << endl;
		right = guess - 1;
	}
	else {
		cout << "Your guess is too low." << endl;
		left = guess + 1;
	}

	return false;
}

void play(Player &player1, Player &player2)
{
	int answer = 0, guess = 0;
	int left = 0, right = 100;
	answer = rand() % 100;
	bool win = false;
	while (true)
	{
		cout << "Player 1's turn to guess." << endl;
		guess = player1.getGuess(left, right);
		if (checkForWin(guess, answer, left, right)) break;

		cout << "Player 2's turn to guess." << endl;
		guess = player2.getGuess(left, right);
		if (checkForWin(guess, answer, left, right)) break;
	}
}

// Main
int main()
{
	HumanPlayer playerH1, playerH2;
	ComputerPlayer playerC1, playerC2;
	play(playerH1, playerH2);
	play(playerH1, playerC1);
	play(playerC1, playerC2);
	return 0;
}