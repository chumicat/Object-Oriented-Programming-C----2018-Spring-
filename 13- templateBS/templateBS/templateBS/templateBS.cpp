/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 14, 2018
 * Last Update: Mar. 14, 2018
 * Version: v1.0
 * Problem statement: templateBS
 * Reference:
 */
#include <iostream>
#define ARRAY_SIZE 300
using std::cin;
using std::cout;
using std::endl;

template <class T>
void ItrSearch(T a[], int startIndex, int finalIndex, const T &key, bool &found, int &location) {
	for(int n= startIndex; n <= finalIndex && key >= a[n]; n++)
		if (a[n] == key) {
			found = true;
			location = n;
			return;
		}
	found = false;
	return;
}

template <class T>
void recBinSrch(T a[], int startIndex, int finalIndex, const T &key, bool &found, int &location) {
	int mid = (startIndex + finalIndex) / 2;
	if (startIndex > finalIndex) {
		return;
	} else if (startIndex + 1 == finalIndex) { //edge and none
		if (a[startIndex] == key || a[finalIndex] == key) {
			found = true;
			location = (a[startIndex] == key) ? startIndex : finalIndex;
		}
	} else if (a[mid] == key) {
		found = true;
		location = mid;
		return;
	} else if (a[mid] > key) {
		recBinSrch(a, startIndex, mid, key, found, location);
	} else if (a[mid] < key){
		recBinSrch(a, mid, finalIndex, key, found, location);
	}
	return;
}
#include <string>
using std::string;

int main()
{
	int a[ARRAY_SIZE];
	const int finalIndex = ARRAY_SIZE - 1;
	int i;
	for (i = 0; i < ARRAY_SIZE; i++)
		a[i] = 3 * i;
	cout << "Array contains:\n";
	for (i = 0; i < ARRAY_SIZE; i++)
		cout << a[i] << " ";
	cout << endl;
	int key, location;
	bool found;
	cout << "Enter number to be located: ";
	cin >> key;
	cout << "\nTesting Template Iterative Binary Search\n";
	ItrSearch(a, 0, finalIndex, key, found, location);
	if (found)
		cout << key << " is in index location "
		<< location << endl;
	else
		cout << key << " is not in the array." << endl;
	cout << "\nTesting Template Recursive Binary Search\n";
	recBinSrch(a, 0, finalIndex, key, found, location);
	if (found)
		cout << key << " is in index location "
		<< location << endl;
	else
		cout << key << " is not in the array." << endl;
	return 0;
}