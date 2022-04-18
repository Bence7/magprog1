#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <array>
#include <list>

using namespace std;

struct Item {
	string name;
	int iid;
	double value;
	
};

void print_vector(vector<Item>& v) {
	for (auto& a : v) {
		cout << a.name << '\t' << a.iid << '\t' << a.value << endl;
	}
}

void print_list(list<Item>& v) {
	for (auto& a : v) {
		cout << a.name << '\t' << a.iid << '\t' << a.value << endl;
	}
}

struct compname {
	bool operator()(Item& a, Item& b) {
		return a.name < b.name;
	}
};
struct compiid {
	bool operator()(Item& a, Item& b) {
		return a.iid < b.iid;
	}
};

struct compvalue {
	bool operator()(Item& a, Item& b) {
		return a.value > b.value;
	}
};

class Find_name {
public:
	string name;
	Find_name(const string& s) :name(s) { }
	bool operator()(const Item& it) const
	{
		return it.name == name;
	}
};

class Find_iid {
public:
	int iid;
	Find_iid(int i) :iid(i) { }
	bool operator()(const Item& it) const
	{
		return it.iid == iid;
	}
};


int main() {
	try 
	{	
	
		cout << "Vector's Elements:" << endl;

		const string iname{ "file.txt" };
		ifstream ifs{ iname };
		if (!ifs) { throw runtime_error("Couldn't read from the file.:" + iname); }
		vector<Item> vi;

		string name;
		int iid;
		double value;

		while (!ifs.eof()) {
			
			ifs >> name >> iid >> value;
			vi.push_back({ name,iid,value });
		}
		print_vector(vi);
		

		cout << "\nSort by Name:\n";
		std::sort(vi.begin(), vi.end(), compname());
		print_vector(vi);


		cout << "\nSort by IID:\n";
		std::sort(vi.begin(), vi.end(), compiid());
		print_vector(vi);


		cout << "\nSort by Value:\n";
		std::sort(vi.begin(), vi.end(), compvalue());
		print_vector(vi);


		vi.push_back({ "horse_shoe", 99, 12.34 });
		vi.push_back({ "Canon_S400", 9988,499.95 });
		cout << "\nAfter Insert:\n";
		print_vector(vi);


		cout << "\nPlease delete a Name!\n";
		string delet;
		cin >> delet;
		cout << "\nAfter Erase:\n";
		int index;
		for (int i = 0; i < vi.size(); i++) {
			if (vi[i].name == delet) {
				index = i;
			}
		}
		vi.erase(vi.begin() + index);
		print_vector(vi);


		cout << "\nPlease delete a Name!\n";
		cin >> delet;
		cout << "\nAfter Erase:" << endl;
		for (int i = 0; i < vi.size(); i++) {
			if (vi[i].name == delet) {
				index = i;
			}
		}
		vi.erase(vi.begin() + index);
		print_vector(vi);
		

		cout << "\nPlease delete an IID!\n";
		int id;
		cin >> id;
		for (int i = 0; i < vi.size(); i++) {
			if (vi[i].iid == id) {
				index = i;
			}
		}
		vi.erase(vi.begin() + index);
		cout << "\nAfter Erase:\n";
		print_vector(vi);


		cout << "\nPlease delete an IID!\n";
		cin >> id;
		for (int i = 0; i < vi.size(); i++) {
			if (vi[i].iid == id) {
				index = i;
			}
		}
		vi.erase(vi.begin() + index);
		cout << "\nAfter Erase:\n";
		print_vector(vi);

		//list
		
		cout << "\nList's Elements:\n";
		ifstream ifl{ iname };
		if (!ifl) { throw runtime_error("Couldn't read from the file.:" + iname); }
		list<Item>li;

		while (!ifl.eof()) {

			ifl >> name >> iid >> value;
			li.push_back({ name,iid,value });
		}
		print_list(li);


		cout << "\nSort by Name:\n";
		li.sort(compname());
		print_list(li);


		cout << "\nSort by IID:\n";
		li.sort(compiid());
		print_list(li);


		cout << "\nSort by Value:\n";
		li.sort(compvalue());
		print_list(li);


		li.push_back({ "horse_shoe", 99, 12.34 });
		li.push_back({ "Canon_S400", 9988,499.95 });
		cout << "\nAfter Insert:\n";
		print_list(li);

		
		cout << "\nAfter delete A and B:\n";
		list<Item>::iterator li_it = find_if(li.begin(), li.end(), Find_name("A"));
		li.erase(li_it);
		li_it = find_if(li.begin(), li.end(), Find_name("B"));
		li.erase(li_it);
		print_list(li);
		

		cout << "\nAfter delete 19 and 91:\n";
		li_it = find_if(li.begin(), li.end(), Find_iid(91));
		li.erase(li_it);
		li_it = find_if(li.begin(), li.end(), Find_iid(19));
		li.erase(li_it);
		print_list(li);

	}

	catch (exception& e) {cerr << "Exception: " << e.what();}
	catch (...) { cerr << "Unknown error"; }
}