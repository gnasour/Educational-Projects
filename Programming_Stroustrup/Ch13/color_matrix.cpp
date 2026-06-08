#include "../GUI/GUI_headers.h"
#include <vector>


int main()
{
    using namespace Graph_lib;
    Vector_ref<Rectangle> rect;
    Simple_window sw{Point{400, 400}, 600, 400, "color matrix"};
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            rect.push_back(new Rectangle{Point(i * 20, j * 20), 20, 20});
            rect[rect.size() - 1].set_fill_color(Color(i * 16 + j));
            sw.attach(rect[rect.size() - 1]);
        }
    }
    sw.wait_for_button();
}