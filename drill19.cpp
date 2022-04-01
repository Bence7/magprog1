#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T> struct S {
	S(T vv = 0) : val{ vv } {}
	T& get();
	const T& get() const;
	void set(T new_t) { val = new_t; }
	void operator = (const T&);
private:
	T val;
};

template<typename T>
T& S<T>::get() {
	return val;
}


template<typename T>
const T& S<T>::get() const {
	return val;
}


template<typename T>
void S<T>::operator=(const T& s) {
	val = s;
}

template<typename T> void read_val(T& s) {}



int main() {

	S<int> s;
	S<int> si{ 37 };
	S<char> sc{ 'c' };
	S<double> sd{ 3.2 };
	S<std::string> ss{ "Hello!" };
	S<vector<int>> svi{ std::vector<int>{1, 2, 3, 4, 5, 8} };

	cout << "S<int> : " << s.get() << endl
		<< "S<int> : " << si.get() << endl
		<< "S<char> : " << sc.get() << endl
		<< "S<double> : " << sd.get() << endl
		<< "S<string> : " << ss.get() << endl;

	// << "S<vector<int>> : " << svi.val << endl

	for (auto a : svi.get()) {
		cout << a << ' ';
	}
	cout << endl;

	sc.set('s');
	cout << "S<char> : " << sc.get() << endl;


	si = 30;
	cout << "Si.get : " << si.get() << endl;


	int ii = 12;
	read_val(ii);
	S<int>si2{ ii };

	double dd = 23.5;
	read_val(dd);
	S<double>sd2{ dd };

	string sss = "football";
	read_val(sss);
	S<string>ss2{ sss };

	cout << "Si2.get() : " << si2.get() << endl;
	cout << "Sd2.get() : " << sd2.get() << endl;
	cout << "Ss2.get() : " << ss2.get() << endl;

}