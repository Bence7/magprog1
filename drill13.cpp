#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"

#include <string>
#include <iostream>
#include <utility>

using namespace Graph_lib;

int main () {
    try {
        Point t1(300, 50);
        Simple_window win(t1, 1000, 800, "My window");
        win.wait_for_button();
        
        Lines grid;
        int x_size = 800;
        int y_size = 800;
        for(int i=100; i <=x_size; i+=100) {
            grid.add(Point(i,0), Point(i, y_size));
            grid.add(Point(0,i), Point(x_size, i));
            }
        
        win.attach(grid);
        win.wait_for_button();


        Vector_ref<Rectangle> vr;
            for (int i = 0; i<8; ++i) {
                    vr.push_back(new Rectangle{Point{i*100,i*100},100,100});
                    vr[vr.size()-1].set_fill_color(Color::red);
                    win.attach(vr[vr.size()-1]);}


        win.wait_for_button();  


		Image ii {Point{0,200},"index.jpeg"};
		win.attach(ii);
		Image aa {Point{200,500},"index.jpeg"};
		win.attach(aa);
		Image bb {Point{500,100},"index.jpeg"};
		win.attach(bb);
		win.wait_for_button(); 

	   while(true){
            int x = rand()% 7 + 0;
            int y = rand()% 7 + 0;
            Image ii {Point{x*100,y*100},"x.jpg"};
            win.attach(ii);
            win.wait_for_button();
        }
    } catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        return 1;
        
    } catch(...) {
        cerr << "exception" <<endl;
        return 2;
        }        
}