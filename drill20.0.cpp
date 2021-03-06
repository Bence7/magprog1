#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <array>
#include <string>
using namespace std;

template<typename T>
void increase(T& inc, int n) {
	for (int& a : inc) {
		a += n;
	}
}

template<typename T>
void print(T& p) {
	for (int& a : p) {
		cout << a << " ";
	}
	cout << endl;
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2) {
	for (Iter1 p = f1; p != e1; ++p) {
		*f2 = *p;
		f2++;
	}
	return f2;
}

int main() {
	constexpr int size = 10;
	int ar[size];
	array<int, size> arr;
	vector<int> vec;
	list<int> ls;

	for (int i = 0; i < size; ++i)
	{
		ar[i] = i;
		arr[i] = i;
		vec.push_back(i);
		ls.push_back(i);
	}
	cout << "Ar elements: ";
	for (auto& a : ar) {
		cout << a << " ";
	}
	cout << endl;

	cout << "Array elements: ";
	for (auto& a : arr) {
		cout << a << " ";
	}
	cout << endl;

	cout << "Vector elements: ";
	for (auto& a : vec) {
		cout << a << " ";
	}
	cout << endl;

	cout << "List elements: ";
	for (auto& a : ls) {
		cout << a << " ";
	}
	cout << endl << endl;

	array<int, size> arr2 = arr;
	vector<int> vec2 = vec;
	list<int> ls2 = ls;
	/*
		copy(begin(arr), end(arr), begin(arr2));
		copy(vec.begin(), vec.end(), back_inserter(vec2));
		copy(ls.begin(), ls.end(), back_inserter(ls2));
	*/
	cout << "Second array elements: ";
	for (auto& a : arr2) {
		cout << a << " ";
	}
	cout << endl;

	cout << "Second vector elements: ";
	for (auto& a : vec2) {
		cout << a << " ";
	}
	cout << endl;

	cout << "Second list elements: ";
	for (auto& a : ls2) {
		cout << a << " ";
	}
	cout << endl << endl;

	increase(arr2, 2);
	increase(vec2, 3);
	increase(ls2, 5);

	cout << "Array increased by 2: ";
	print(arr2);
	cout << "Vector increased by 3: ";
	print(vec2);
	cout << "List increased by 5: ";
	print(ls2);
	cout << endl;

	my_copy(arr2.begin(), arr2.end(), vec2.begin());
	my_copy(ls2.begin(), ls2.end(), arr2.begin());

	cout << "Array after the copy: ";
	print(arr2);
	cout << "Vector after the copy: ";
	print(vec2);
	cout << "List after the copy: ";
	print(ls2);
	cout << endl;

	vector<int>::iterator vit;
	vit = find(vec2.begin(), vec2.end(), 3);
	cout << "Does the vector contain number 3?\n";

	if (vit != vec2.end()) {
		cout << "Yes, found at index " << distance(vec2.begin(), vit) << "." << endl << endl;
	}

	else {
		cout << "Not found!\n\n";
	}

	cout << "Does the list contain number 27?\n";
	list<int>::iterator lit;
	lit = find(ls2.begin(), ls2.end(), 27);

	if (lit != ls2.end()) {
		cout << "Yes, found at index " << distance(ls2.begin(), lit)<< "." << endl << endl;
	}
	else {
		cout << "Not found!\n\n";
	}
}