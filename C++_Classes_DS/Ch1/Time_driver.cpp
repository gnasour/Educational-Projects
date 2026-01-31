#include "Time.hpp"
#include <iostream>

int main()
{
    Time time;
    time.setHours(10.0);
    time.setMinutes(11.0);
    time.setSeconds(12.0);
    std::cout << "TIME: " << 10 << ":" << 11 << ":" << 12 << std::endl;
    std::cout << "Total time in hours: " << time.timeInHours() << std::endl;
    std::cout << "Total time in minutes: " << time.timeInMinutes() << std::endl;
    std::cout << "Total time in seconds: " << time.timeInSeconds() << std::endl;

    std::cout << "\nEnd of Program" << std::endl;
    
    return 0;
}