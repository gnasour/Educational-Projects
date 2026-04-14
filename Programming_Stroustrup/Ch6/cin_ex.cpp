#include <iostream>

int main()
{
    int x;
    char c;
    double d;
    std::cout << "Enter an integer" << std::endl;
    std::cin >> x;
    std::cout << "Enter a character" << std::endl;
    std::cin >> c;
    std::cout << "Enter a double" << std::endl;
    std::cin >> d;

    std::cout << "Int: " << x << " Char: " << c << " Double: " << d << std::endl;
    return 0;
}