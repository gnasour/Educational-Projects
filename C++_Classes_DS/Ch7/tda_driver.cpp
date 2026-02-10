#include "TwoDArr.hpp"
#include <iostream>

int main()
{
    TwoDArr<int> tda(5,5);
    std::cout << "Swapping columns" << std::endl;
    tda.swapCol(2,4);
    tda.printArr();
    std::cout << "Deleting a column" << std::endl;
    tda.delCol(1);
    tda.printArr();

    return 0;
}