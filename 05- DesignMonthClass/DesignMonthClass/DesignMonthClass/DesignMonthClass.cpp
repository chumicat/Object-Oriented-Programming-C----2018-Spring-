/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 7, 2018
 * Last Update: Mar. 7, 2018
 * Version: v1.0
 * Problem statement: Convert minutes to HMS format
 * Reference:
https://stackoverflow.com/questions/201992/how-to-read-until-eof-from-cin-in-c
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Month {
private:
	int month;
	string monthList[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	void intToMonth(int m) { month = (m > 0 && m < 13) ? m : 1; }
	void charToMonth(char c0, char c1, char c2) {
		for (int n = 1; n <= 12; n++) {
			if (c0 == monthList[n - 1][0] && c1 == monthList[n - 1][1] && c2 == monthList[n - 1][2]){
				month = n;
				return;
			}	
		}
		month = 1;
	}
	void stringToMonth(string s) {
		if (s.size() != 3)
			month = 1;
		else
			charToMonth(s[0], s[1], s[2]);
	}
public:
	/* Constructor */
	Month() { month = 1; }
	Month(int m) { intToMonth(m); }
	Month(char c0, char c1, char c2) { charToMonth(c0, c1, c2); }
	Month nextMonth() { return month + 1 <= 12 ? month + 1 : 1; }
	void inputInt() {
		std::cin >> month; 
		intToMonth(month);
	}
	void inputStr() {
		char c1, c2, c3;
		std::cin >> c1 >> c2 >> c3;
		charToMonth(c1, c2, c3);
	}void inputFirstThreeLetters() { inputStr(); }
	void outputInt() {
		cout << month;
	}
	void outputStr() {
		cout << monthList[month - 1];
	}void outputFirstThreeLetters() { outputStr(); }
};

//input-main1.cpp
int main(void)
{
	Month month1, month2(2), month3('M', 'a', 'r'), month4, month5, month6;
	month4 = month3.nextMonth();
	month5.inputInt();
	month6.inputStr();

	cout << "Month1 = ";
	month1.outputInt();
	cout << ' ';
	month1.outputStr();
	cout << endl;

	cout << "Month2 = ";
	month2.outputInt();
	cout << ' ';
	month2.outputStr();
	cout << endl;

	cout << "Month3 = ";
	month3.outputInt();
	cout << ' ';
	month3.outputStr();
	cout << endl;

	cout << "Month4 = ";
	month4.outputInt();
	cout << ' ';
	month4.outputStr();
	cout << endl;

	cout << "Month5 = ";
	month5.outputInt();
	cout << ' ';
	month5.outputStr();
	cout << endl;

	cout << "Month6 = ";
	month6.outputInt();
	cout << ' ';
	month6.outputStr();
	cout << endl;
	return 0;
}

////input-main2.cpp
//int main(void)
//{
//	Month month1, month2(2), month3(13), month4('M', 'a', 'r'), month5('A', 'P', 'R'), month6, month7, month8;
//	month6.inputInt();
//	month7.inputStr();
//
//	cout << "Month1 = ";
//	month1.outputInt();
//	cout << ' ';
//	month1.outputStr();
//	cout << endl;
//
//	cout << "Month2 = ";
//	month2.outputInt();
//	cout << ' ';
//	month2.outputStr();
//	cout << endl;
//
//	cout << "Month3 = ";
//	month3.outputInt();
//	cout << ' ';
//	month3.outputStr();
//	cout << endl;
//
//	cout << "Month4 = ";
//	month4.outputInt();
//	cout << ' ';
//	month4.outputStr();
//	cout << endl;
//
//	cout << "Month5 = ";
//	month5.outputInt();
//	cout << ' ';
//	month5.outputStr();
//	cout << endl;
//
//	cout << "Month6 = ";
//	month6.outputInt();
//	cout << ' ';
//	month6.outputStr();
//	cout << endl;
//
//	cout << "Month7 = ";
//	month7.outputInt();
//	cout << ' ';
//	month7.outputStr();
//	cout << endl;
//
//	cout << "Month8 = ";
//	month8.outputInt();
//	cout << ' ';
//	month8.outputStr();
//	cout << endl;
//
//	for (int times = 0; times < 12; times++)
//	{
//		month8 = month8.nextMonth();
//		cout << "Month8 = ";
//		month8.outputInt();
//		cout << ' ';
//		month8.outputStr();
//		cout << endl;
//	}
//	return 0;
//}