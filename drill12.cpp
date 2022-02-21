#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"
#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
	try{
	
	Simple_window win {Point{100,100},800,800,"Canvas"};

	win.wait_for_button(); 

	Axis xa {Axis::x, Point{20,300}, 200, 20, "x axis"};  

	win.attach(xa);
	win.set_label("Canvas #2");       
	win.wait_for_button();   


	Axis ya {Axis::y, Point{20,300}, 280, 20, "y axis"};
	ya.set_color(Color::magenta);
	ya.label.set_color(Color::magenta);
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button();  


	Function sine {sin,0,100,Point{20,150},700,50,50};
	win.attach(sine);
	win.set_label("Canvas #4");
	win.wait_for_button();
	

	sine.set_color(Color::blue);
	Polygon poly;
	poly.add(Point{300,200}); 
	poly.add(Point{350,300});
	poly.add(Point{400,600});
	poly.add(Point{600,200});
	poly.set_color(Color::magenta);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");
	win.wait_for_button();


	Rectangle r {Point{200,200}, 100, 150};
	win.attach(r);
	win.set_label("Canvas #6");
	win.wait_for_button();


	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	poly_rect.add(Point{50,75});


	r.set_fill_color(Color::green);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,7));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");
	win.wait_for_button();
	

	Text t {Point{130,150}, "Hello, graphical world!"};
	win.attach(t);
	win.set_label("Canvas #8");
	win.wait_for_button();


	t.set_font(Font::times_bold);
	t.set_font_size(30);
	win.set_label("Canvas #9");
	win.wait_for_button();


	Image ii {Point{100,50},"minion.jpg"};
	win.attach(ii);
	win.set_label("Canvas #10");
	win.wait_for_button();

	
	ii.move(100,200);
	win.set_label("Canvas #11");
	win.wait_for_button();


	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::red);
	Mark m {Point{100,200},'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	          << "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	Image cal {Point{225,225},"lion.jpg"};  
	cal.set_mask(Point{40,40},200,150);                     
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #12");
	win.wait_for_button();


	} catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	} catch (...) {
	cerr << "error\n";
	return 2;
	}
}
	