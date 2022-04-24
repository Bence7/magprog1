#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Person {
public:
	Person() {};
	Person(string F, string L, int A){
		if (A < 0 || A >= 150) { throw runtime_error("Invalid age"); }
		else { a = A; }
		string Name = F + L;
		for (int i = 0; i < Name.length(); ++i)
		{
			if (Name[i] == ';' || Name[i] == ':' || Name[i] == '[' || Name[i] == ']' || Name[i] == '"' || Name[i] == '*' || Name[i] == '\'' || Name[i] == '&' || Name[i] == '^' || Name[i] == '%' || Name[i] == '$' || Name[i] == '#' || Name[i] == '@' || Name[i] == '!')
				throw runtime_error("Invalid Name");
			{
				f = F;
				l = L;
			}
		}
	};
	string first() const { return f; }
	string last() const { return l; }
	int age() const { return a; }
private:

	string f;
	string l;
	int a;
};

ostream& operator<< (ostream& os, const Person& p) {
	return os << p.first() << ' ' << p.last() << " " << p.age();
}

istream& operator>> (istream& is, Person& p) {
	string f;
	string l;
	int a;
	is >> f >> l >> a;

	p = Person(f, l, a);
	return is;
}

int main() {
	cout << "Person p:\n";
	Person p = Person("Goofy", "a", 63);
	cout << p.first() << " " << p.last() << " " << p.age() << endl;


	cout << "\nPlease enter first name, last name and age!\n";
	Person p2;
	cin >> p2;
	cout << p2 << endl;

	cout << "\nPlease enter first name, last name and age!(If you want to quit, write 'end' first name!)\n";
	vector<Person> vec;
	for (Person p; cin >> p;)
	{
		if (p.first() == "end") break;
		vec.push_back(p);
	}

	cout << "\nVector's Persons:\n";
	for (Person p : vec) {
		cout << p << endl;
	}
}