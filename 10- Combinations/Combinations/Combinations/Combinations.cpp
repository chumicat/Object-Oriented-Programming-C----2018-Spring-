/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: Mar. 12, 2018
* Last Update: Mar. 12, 2018
* Version: v1.0
* Problem statement: Combinations
* Reference:
https://stackoverflow.com/questions/6726805/insert-an-element-into-a-specific-position-of-a-vector
*/

#include <iostream>
#include <string>
#include <vector>
#define ELEMENTS_FOR_COMBINATION 5 //i.e., C(5,4)
#define DLEMENTS_FOR_CHOICE 4
using std::string;
using std::vector;

void RecursivePrintCombination(vector<int> &arySet, const size_t &choice, vector<int> &pre) {
	if (choice == 0) {
		/* At the end, show this combination */
		std::cout << "(";
		for (int n : pre) {
			std::cout << n << ", ";
		}std::cout << "\b\b)" << std::endl;
	} else if (choice > 0) {
		/* Hadn't choose enough element */
		int now;
		vector<int> reserve;
		reserve.reserve(arySet.size());
		/* Choose one by one and recursive */
		for (int n=0; n<arySet.size(); ) {
			now = arySet.at(n);
			arySet.erase(arySet.begin() + n);
			pre.push_back(now);
			RecursivePrintCombination(arySet, choice - 1, pre);
			pre.pop_back();
			/* After using the element, do not reuse or it will became R rather than C */
			reserve.push_back(now);
		}
		/* before return, restore element list */
		arySet.insert(arySet.end(), reserve.begin(), reserve.end());
	}
}

/* Call this to print */
void PrintCombination(int *arrayPtr, const size_t &element, const size_t &choice) {
	if (choice == 0) {
		std::cout << "()" << std::endl;
		return;
	}
	
	vector<int> arySet;
	vector<int> pre;
	arySet.reserve(element);
	pre.reserve(element);
	for (int n = 0; n < element; n++)
		arySet.push_back(arrayPtr[n]);
	RecursivePrintCombination(arySet, choice, pre);
}

int main(void)
{
	int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];

	//Get all elements for combination
	for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
		arrayPtr[i] = i + 1;

	PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);

	if (arrayPtr != NULL)
		delete[] arrayPtr;
	return 0;
}