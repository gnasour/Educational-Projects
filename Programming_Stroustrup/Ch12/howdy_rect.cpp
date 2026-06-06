#include "../GUI/GUI_headers.h"



int main()
{
    using namespace Graph_lib;
    Point tl{400, 400};
    Simple_window win{tl, 1200, 800, "Howdy Rectangle"};

    Rectangle r{Point{400, 400}, 100, 30};

    Text t{Point{425, 420}, "Howdy!"};

    win.attach(r);
    win.attach(t);
    win.wait_for_button();
}