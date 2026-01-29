#include "Road.hpp"
#include <iostream>

int main()
{
    Road main_road;
    main_road.set_length(5.5);
    main_road.set_width(40.1);
    double thickness = 11.1;
    double cu_ft_req = main_road.asphalt(thickness);

    std::cout << "A road with a length of " << main_road.get_length() << " miles," << std::endl;
    std::cout << "a width of " << main_road.get_width() << " feet," << std::endl;
    std::cout << "and a thickness of " << thickness << " inches ";
    std::cout << "will require " << cu_ft_req << " cubic feet of asphalt to build." << std::endl;

    return 0;
}