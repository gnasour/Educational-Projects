#include "my.h"

int foo;
int main()
{
    // foo = 7;
    // print_foo();
    // print(99);

    int x = 7;
    int y = 9;
    swap_r(x, y);
    // swap_r(7, 9); // Won't work, needs a reference from a member variable
    const int x1 = 7;
    const int y1 = 9;
    // swap_r(x1, y1); // Cannot change member variables marked const
    // swap_r(7.7, 9.9); // Same as first error
    double dx = 7.7;
    double dy = 9.9;
    // swap_r(dx, dy); // cannot use double as a reference to int
    // swap_r(7.7, 9.9); // same as first error
}