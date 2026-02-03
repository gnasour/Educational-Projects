#include "CheckbookDynamic.hpp"
#include <iostream>

int main()
{
    CheckbookDynamic<float> cbd(100.0);

    cbd.writeCheck(10);
    cbd.writeCheck(20);
    cbd.writeCheck(30);

    return 0;
}