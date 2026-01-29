#ifndef ROAD_HPP
#define ROAD_HPP


class Road
{
public:
    void set_width(double width_ft);
    void set_length(double length_mi);
    double get_width();
    double get_length();
    double asphalt(double road_thickness);
private:
    double width;  // Measured in feet
    double length; // Measured in miles
};

#endif