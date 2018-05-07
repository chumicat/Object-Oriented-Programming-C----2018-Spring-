/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID： B10332030
 * Date: Mar. 7, 2018
 * Last Update: Mar. 7, 2018
 * Version: v1.0
 * Problem statement: Form word
 * Reference:
https://stackoverflow.com/questions/201992/how-to-read-until-eof-from-cin-in-c
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define SIZE 256
using std::string;
using std::vector;

class Form {
private:
	string word;
	string fileName;
	int alphabetTable[SIZE] = {0};
	std::vector<string> foundedWord;
	/* Count each char in string to table */
	void counting(int inputTable[SIZE], string s) {
		for (char c : s) 
			inputTable[toupper(c)/* - 'A'*/]++;
	}
	/* If alphabetTable's each value is larger than this one than return true */
	bool below(int inputTable[SIZE]) {
		for (int n=0; n<SIZE; n++)
			if (alphabetTable[n] < inputTable[n])
				return false;
		return true;
	}
public:
	/* Showing table */
	void show(int inputTable[SIZE]) {
		for (int n = 0; n < SIZE; n++)
			std::cout << inputTable[n] << " ";
		std::cout << std::endl;
	}

	/* Sequential function */
	void SetInputWord(string s) { word = s; }
	void ProcessInputWord() { counting(alphabetTable, word); }
	void SetFileName(string s) { fileName = s; }
	void Load_CompaerWord() {
		std::ifstream ifs;
		ifs.open(fileName);
		string word;
		while (ifs >> word) {
			int inputTable[SIZE] = { 0 };
			counting(inputTable, word);
			if (below(inputTable))
				foundedWord.push_back(word);
		}
	}
	void PrintFoundWords() {
		for (string s : foundedWord)
			std::cout << s << std::endl;
	}
};

//FormWord-inputmain1.cpp
//int main()
//{
//	Form form1;
//	form1.SetInputWord("SWIMMING");//設定Input
//	form1.ProcessInputWord();//處理Input資訊
//	form1.SetFileName("word.txt");//設定檔案名稱
//	form1.Load_CompaerWord();//讀檔並且比較
//	form1.PrintFoundWords();//印出符合的字
//	return 0;
//}

//inputmain2.cpp
int main()
{
	Form form2;
	form2.SetInputWord("calculator");//設定Input
	form2.ProcessInputWord();//處理Input資訊
	form2.SetFileName("word.txt");//設定檔案名稱
	form2.Load_CompaerWord();//讀檔並且比較
	form2.PrintFoundWords();//印出符合的字
	return 0;
}