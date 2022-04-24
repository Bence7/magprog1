#include <iostream>
#include <string>
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;


double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return slope(x)+cos(x); }

int main(){
	
//1.rész
	Point t{0,0};
	Simple_window win{t, 600, 600, "Function graphs"};
	win.wait_for_button();


	Point origo{300,300};
	Axis xa {Axis::x, Point{100,300}, 400, 20, "x axis"};  
	win.attach(xa);
	xa.set_color(Color::red);
	Axis ya {Axis::y, Point{300, 500}, 400, 20, "y axis"};
	ya.set_color(Color::red);
	win.attach(ya);      
	win.set_label("Function graphs");
	win.wait_for_button(); 

//2.rész
	constexpr int range1 = -10;
	constexpr int range2 = 11;
	constexpr int length = 400;
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;
	Point label{100, 380};


	Function egy(one, range1, range2, origo, length, x_scale, y_scale);
	win.attach(egy);
	win.set_label("Function graphs");
	win.wait_for_button();


	Function ketto(slope, range1, range2, origo, length, x_scale, y_scale);
	win.attach(ketto);


	Text teletext(label, "X/2");
	win.attach(teletext);
	win.set_label("Function graphs");
	win.wait_for_button();


	Function harom(square, range1, range2, origo, length, x_scale, y_scale);
	win.attach(harom);
	win.set_label("Function graphs");
	win.wait_for_button();


	Function cosinus{cos,range1,range2,origo,length,x_scale,y_scale};
	win.attach(cosinus);
	cosinus.set_color(Color::blue);
	win.set_label("Function graphs");
	win.wait_for_button();


	Function sloping{sloping_cos,range1,range2,origo,length,x_scale,y_scale};
	win.attach(sloping);
	win.set_label("Function graphs");
	win.wait_for_button();
}

