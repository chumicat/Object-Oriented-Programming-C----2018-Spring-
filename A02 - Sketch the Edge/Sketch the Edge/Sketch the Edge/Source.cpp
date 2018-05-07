/* Name: Russell (Chumicat) (Li-Shuo ZENG)
* SID¡G B10332030
* Date: Mar. 8, 2018
* Last Update: Mar. 8, 2018
* Version: v1.0
* Problem statement: Sketch the Edge
* Reference:
https://kw0006667.wordpress.com/2014/02/06/cstl-vector-erase-%E5%B0%8E%E8%87%B4%E8%BF%B4%E5%9C%88%E9%8C%AF%E8%AA%A4/
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using std::string;
using std::stringstream;
using std::vector;

class Block {
public:
	double left, height, right;
	bool done = false;
	Block(double l, double h, double r) : left(l), height(h), right(r) {}
	bool noIntersection(Block b) { return right <= b.left || b.right <= left; }
	bool leftInRangeOf(Block b) { return b.left <= left && left <= b.right; }
	bool rightInRangeOf(Block b) { return b.left <= right && right <= b.right; }
	bool bothInRangeOf(Block b) { return leftInRangeOf(b) && rightInRangeOf(b); }
	bool containRangeOf(Block b) { return left < b.left && b.right < right; }
	string show() { 
		stringstream ss;
		ss << left << " " << height << " " << right << " " << done;
		return ss.str();
	}
};

void showList(vector<Block> v) {
	for (Block b : v)
		std::cout << b.show() << std::endl;
	std::cout << std::endl << std::endl;
}

int main() 
{
	vector<Block> blockList;
	double d1, d2, d3;
	while (std::cin >> d1 >> d2 >> d3) {
		blockList.push_back(Block(d1, d2, d3));
	}
	//std::ifstream ifs;
	//ifs.open("input.txt");
	//while (ifs >> d1 >> d2 >> d3)
	//	blockList.push_back(Block(d1, d2, d3));

	/* check if nothing here */
	if (blockList.size() == 0) {
		std::cout << "no block, no shadow\n" << std::endl;
		system("pause");
		return 0;
	}

	/* sort with height */
	std::sort(blockList.begin(), blockList.end(), [](Block b1, Block b2) {return b1.height > b2.height; });
	
	/* cut side to finishList */
	std::vector<Block> finishList;
	for (vector<Block>::iterator it1 = blockList.begin(); it1 < blockList.end(); it1++) {
		for (vector<Block>::iterator it2 = finishList.begin(); it2 < finishList.end(); it2++) {
			if (it1->bothInRangeOf(*it2)) 
			{	/* no need situation: erase and continue on next it1 */
				it1 = blockList.erase(it1);
				it1--;
				break;
			} else if (it1->leftInRangeOf(*it2)) 
			{	/* left cut situation */
				it1->left = it2->right;
			} else if (it1->rightInRangeOf(*it2))
			{	/* right cut situation */
				it1->right = it2->left;
			} else if (it1->containRangeOf(*it2))
			{	/* divide situation: erase old one, create new two part and restart on new part */
				double left = it1->left, height = it1->height, right = it1->right;
				it1 = blockList.erase(it1);
				it1 = blockList.insert(it1, Block(left, height, it2->left));
				it1 = blockList.insert(it1, Block(it2->right, height, right));
				it1--;
				break;
			} else 
			{ /* no Intersection */
			}
		}
		if(!it1->done){
			finishList.push_back(*it1);
			it1->done = true;
		}
	}

	/* sort with left */
	std::sort(finishList.begin(), finishList.end(), [](Block b1, Block b2) {return b1.left < b2.left; });
	
	/* fill hole */
	double lastX = finishList.at(0).left;
	for (vector<Block>::iterator it = finishList.begin(); it < finishList.end(); it++) {
		if (lastX != it->left)
			it = finishList.insert(it, Block(lastX, 0, it->left));
		lastX = it->right;
	}

	/* show answer */
	std::cout << finishList.front().left << " 0 ";
	for (Block b : finishList) {
		std::cout << b.left << " " << b.height << " " << b.right << " " << b.height << " ";
	}
	std::cout << finishList.back().right << " 0";

	return 0;
}
