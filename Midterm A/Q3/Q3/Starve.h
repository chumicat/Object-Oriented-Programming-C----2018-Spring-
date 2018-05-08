#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Food{
public:
	int satisfaction;
	int sanity;
	Food(int sat, int san) : satisfaction(sat), sanity(san){}
};

class Character{
public:
	int satisfaction;
	int sanity;
	string name;
	Character(int sat, int san, const string &name) : satisfaction(sat), sanity(san), name(name){}
	void feast(Food f){
		satisfaction += f.satisfaction;
		sanity += f.sanity;
	}
	void show(){
	cout.width(10);
	cout << "name";
	cout.width(20);
	cout << "satisfaction";
	cout.width(20);
	cout << "sanity";
	cout << endl;
	cout.width(10);
	cout << name;
	cout.width(20);
	cout << satisfaction;
	cout.width(20);
	cout << sanity;
	cout << endl;
	}

};