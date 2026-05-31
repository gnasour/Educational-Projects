#include "my.h"
#include "../std_lib_facilities.h"

void print_foo()
{
    cout << foo << "\n";
}

void print(int i)
{
    cout << i << "\n";
}

void swap(int a, int b)
{
    int temp;
    temp = a, a = b;
    b = temp;

    cout << "a: " << a << " b: " << b << endl;
}

void swap_r(int &a, int &b)
{
    int temp;
    temp = a, a = b;
    b = temp;

    cout << "a: " << a << " b: " << b << endl;
}

void swap_cr(const int &a, const int &b)
{
    int temp;
    // temp = a, a = b;  // These two statements won't compile
    // b = temp;         // Reason: changing const ref
}