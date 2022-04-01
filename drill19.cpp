#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T> struct S {
private:
	T val;
public:	
	S(T v) { val = v; }
	T& get();
	const T& get() const;
	void operator = (const T&);
	void set(T v) { val = v; }
};

template<typename T>
T& S<T>::get() {return val;}


template<typename T>
const T& S<T>::get() const {return val;}


template<typename T>
void S<T>::operator=(const T& v) {
	val = v;
}

template<typename T> void read_val(T& v) {cin >> v; }



int main() {

	S<int> s{2};
	S<int> si{ 37 };
	S<char> sc{ 'c' };
	S<double> sd{ 3.2 };
	S<string> ss{ "Hello!" };
	S<vector<int>> svi{ vector<int>{1, 2, 3, 4, 5, 8} };

	cout << "S<int>: " << s.get() << endl
		<< "S<int>: " << si.get() << endl
		<< "S<char>: " << sc.get() << endl
		<< "S<double>: " << sd.get() << endl
		<< "S<string>: " << ss.get() << endl;

	cout << "S<vector<int>> svi: ";
	for (auto a : svi.get()) {
		cout << a << ' ';
	}
	cout << endl << endl;

	sc.set('s');
	cout << "sc.get(): " << sc.get() << endl;

	si.set(30);
	cout << "si.get(): " << si.get() << endl;

	sd.set(6.4);
	cout << "sd.get(): " << sd.get() << endl;

	cout << endl << "Please write an int, a double and a string." << endl;
	int ii;
	cout << "int: ";
	read_val(ii);
	S<int>si2{ ii };

	double dd;
	cout << "double: ";
	read_val(dd);
	S<double>sd2{ dd };

	string sss;
	cout << "string: ";
	read_val(sss);
	S<string>ss2{ sss };

	cout << "si2.get(): " << si2.get() << endl;
	cout << "sd2.get(): " << sd2.get() << endl;
	cout << "ss2.get(): " << ss2.get() << endl;

}