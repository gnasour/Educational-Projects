#include <iostream>


int main()
{
    int birth_year = 1996;

    //printing in dec, oct, & hex
    std::cout << std::showbase;
    std::cout << "Printing birth year in different bases" << std::endl;
    std::cout << "Dec: " << birth_year << " ";
    std::cout << "Oct: " << std::oct << birth_year << " ";
    std::cout << "Hex: " << std::hex << birth_year << std::endl;
    std::cout << std::noshowbase;

    int age = 30;
    std::cout << std::dec << "Age: " << age << std::endl;

    int a, b, c, d;
    //std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
    //std::cout << a << '\t' << b << '\t' << c << '\t' << d << std::endl;

    float val = 1234567.89;
    std::cout << "Defaultfloat: " << val << '\t';
    std::cout << std::fixed << "Fixed: " << val << '\t';
    std::cout << std::scientific << "Scientific: " << val << std::endl;

    std::cout << "Last:\t" << "First:\t" << "Tel#:\t\t" << "Email:\t" << std::endl;
    std::cout << "George\t" << "Nassour\t" << "(818)923-9133" << "\tgnasour@gmail.com" << std::endl;
}