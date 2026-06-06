#include "../GUI/GUI_headers.h"



int main()
{

    Point *p = new Point{100, 100};
    Simple_window sw{*p, 800, 800, "Initials"};

    Text initials_first{Point{200, 200}, "G"};
    Text initials_middle{Point{300, 300}, "M"};
    Text initials_last{Point{420, 420}, "N"};

    // Font
    initials_first.set_font(Font::courier_bold);

    // Size
    initials_first.set_font_size(150);
    initials_middle.set_font_size(150);
    initials_last.set_font_size(150);

    // Colors
    initials_first.set_color(Color::green);
    initials_middle.set_color(Color::magenta);
    initials_last.set_color(Color::blue);

    // Line thickness
    initials_first.set_style(Line_style{4});
    initials_middle.set_style(Line_style{4});
    initials_last.set_style(Line_style{4});

    sw.attach(initials_first);
    sw.attach(initials_middle);
    sw.attach(initials_last);

    sw.wait_for_button();
}