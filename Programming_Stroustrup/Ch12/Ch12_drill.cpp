#include "../GUI/GUI_headers.h"

int main()
{
    using namespace Graph_lib;
    Point *p = new Point{100, 100};
    Simple_window win{*p, 600, 400, ""};

    // Axes 
    Axis xa{Axis::x, Point{20, 300}, 280, 20, "x axis"};
    Axis ya{Axis::y, Point{20, 300}, 280, 20, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_yellow);

    // sine object
    Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50};
    sine.set_color(Color::blue);

    // Polygon object
    Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    poly.set_style(Line_style(Line_style::dash, 4));
    
    // Rectangle object
    Rectangle r{Point{200, 200}, 100, 50};
    r.set_fill_color(Color::yellow);

    // Closed_polyline object
    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);

    // Text object
    Text t{Point{150, 150}, "Hello, graphical world!"};
    t.set_font(Font::times_bold);
    t.set_font_size(20);

    // Image object
    Image ii{Point{100, 50}, "/home/code/Desktop/image.jpg"};
    ii.move(100,200);

    // More code
    Circle c{Point{100,200}, 50};
    Ellipse e{Point{100, 200}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m{Point{100, 200}, 'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes{Point{100, 20}, oss.str()};

    Image cal{Point{0, 0}, "/home/code/Desktop/funny.gif"};
    cal.set_mask(Point{40, 40}, 400, 400);

    // Window modifications
    win.attach(cal);
    win.attach(sizes);
    win.attach(m);
    win.attach(e);
    win.attach(c);
    win.attach(ii);
    win.attach(t);
    win.attach(poly_rect);
    win.attach(r);
    win.attach(poly);
    win.attach(sine);
    win.attach(xa);
    win.attach(ya);
    win.set_label("Graph ex");
    win.wait_for_button();
}