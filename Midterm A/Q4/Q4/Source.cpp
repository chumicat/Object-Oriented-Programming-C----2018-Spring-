#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class BigNum{
public:
	vector<int> value;
	BigNum(int i){ value.push_back(i); }
	BigNum operator+= (BigNum rhs){
		this->value.resize(max(this->value.size(), rhs.value.size())+1);
		rhs.value.resize(max(this->value.size(), rhs.value.size()));
		transform(this->value.begin(), this->value.end(), rhs.value.begin(), this->value.begin(), plus<int>());
		for (int i = 0; i < this->value.size() - 1; i++){
			//this->value[i] += rhs.value[i];
			if (this->value[i] >= 10){
				this->value[i + 1] += 1;
				this->value[i] %= 10;
			}
		}/*
		if (this->value.back() >= 10){
			this->value.back() = this->value.back() % 10;
			this->value.push_back(1);
		}*/
		while (!this->value.empty()){
			if (this->value.back() == 0)
				this->value.pop_back();
			else
				break;
		}

		return *this;
	}
	friend ostream & operator<< (ostream & out, const BigNum &rhs){
		string s;
		for (int i : rhs.value)
			s += (char)(i + '0');
		reverse(s.begin(), s.end());
		return out << s;
	}
};

int main(){
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	vector<BigNum> fb;
	fb.push_back(0);
	fb.push_back(1);
	int limit = max(max(n1, n2), n3);

	for (int i = 2; i <= limit; i++){
		BigNum bn(fb[i - 2]);
		bn += fb[i - 1];
		fb.push_back(bn);
	}

	cout << n1 << ": " << fb[n1] << endl;
	cout << n2 << ": " << fb[n2] << endl;
	cout << n3 << ": " << fb[n3] << endl;

	system("pause");
	return 0;
}