#include "Temperature.hpp"
#include <iostream>

int main()
{
    Temperature temp;
    temp.set_temp_c(32);
    std::cout << "32C in F is: " << temp.get_temp_f() << std::endl;
    temp.set_temp_f(85);
    std::cout << "85F in C is: " << temp.get_temp_c() << std::endl;
    std::cout << "End of Program" << std::endl;
}