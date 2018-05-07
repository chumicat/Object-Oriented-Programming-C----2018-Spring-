/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID�G B10332030
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
//	form1.SetInputWord("SWIMMING");//�]�wInput
//	form1.ProcessInputWord();//�B�zInput��T
//	form1.SetFileName("word.txt");//�]�w�ɮצW��
//	form1.Load_CompaerWord();//Ū�ɨåB���
//	form1.PrintFoundWords();//�L�X�ŦX���r
//	return 0;
//}

//inputmain2.cpp
int main()
{
	Form form2;
	form2.SetInputWord("calculator");//�]�wInput
	form2.ProcessInputWord();//�B�zInput��T
	form2.SetFileName("word.txt");//�]�w�ɮצW��
	form2.Load_CompaerWord();//Ū�ɨåB���
	form2.PrintFoundWords();//�L�X�ŦX���r
	return 0;
}