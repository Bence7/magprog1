#include <string>
#include <iostream>

using namespace std;

class B1 {
public:
	void f() {
		cout << "B1::f()" << endl;
	}

	virtual void vf() {
		cout << "B1::vf()\n";
	}

	virtual void pvf() = 0;
};


class D1 : public B1 {
public:
	void vf() {
		cout << "D1::vf()\n";
	}

	void f() { 
		cout << "D1::f()\n";
	}
};


class D2 : public D1 {
public:
	void pvf() {
		cout << "D2::pvf()\n";
	}
};


class B2 {
public:
	virtual void pvf() = 0;
};


class D21 : public B2 {
public:
	string animal;
	void pvf() {
		cout << animal << endl;
	}
};


class D22 : public B2 {
public:
	int number;
	void pvf() {
		cout << number << endl;
	}
};

void f(B2& a) {
		a.pvf();
}

int main()
{
/*	B1 b1;
	b1.f();
	b1.vf();

	D1 d1;
	d1.vf();
	d1.B1::vf();
	d1.f();

	B1& b1ref = d1;
	b1ref.f();
	b1ref.vf();

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf(); */

	D21 d21;
	d21.animal = "shark";
	d21.pvf();

	D22 d22;
	d22.number = 20;
	d22.pvf(); 

	f(d21);
	f(d22);

}