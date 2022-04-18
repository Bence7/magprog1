#include <iostream>
#include <string>
#include <map>
using namespace std;


void print(map<string, int>& m) {
	for (auto& a : m) {
		cout << a.first << '\t' << a.second << endl;
	}
}

void print(map<int, string>& m) {
	for (auto& a : m) {
		cout << a.first << '\t' << a.second << endl;
	}
}

void add_item(map<string, int>& m) {
	
	string name;
	int id;
	while (m.size() != 10) {
		cin >> name >> id;
		m[name] = id;
	}
}

void sum(map<string, int>& m) {
	int szum = 0;
	for (auto& a : m) {
		szum = szum + a.second;
	}
	cout << "Sum of the elements: " << szum << endl;
}


int main() {

	map<string, int> msi;

	msi["a"] = 10;
	msi["b"] = 9;
	msi["c"] = 8;
	msi["d"] = 7;
	msi["e"] = 6;
	msi["f"] = 5;
	msi["g"] = 4;
	msi["h"] = 3;
	msi["i"] = 2;
	msi["j"] = 1;

	cout << "Map's Elements:\n";
	print(msi);
	
	msi.erase(msi.begin(), msi.end());
	cout << "\nMap's size after Delete: " << msi.size() << endl;

	cout << "Please add 10 string-int pairs like this 'car 15'!\n";
	add_item(msi);
	cout << "\nMap' Elements:\n";
	print(msi);

	cout << endl;
	sum(msi);

	map<int,string> mis;
	cout << "\nMIS' elements:\n";
	for (pair<string, int> a : msi) {
		mis[a.second] = a.first;
	}
	print(mis);
		
	
}