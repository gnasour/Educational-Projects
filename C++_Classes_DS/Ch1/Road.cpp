#include "Road.hpp"


Road::Road()
{
}

Road::Road(double width_ft, double length_mi)
{
    width = width_ft;
    length = length_mi;
}

void Road::set_width(double width_ft)
{
    width = width_ft;
}

void Road::set_length(double length_mi)
{
    length = length_mi;
}

double Road::get_length() const
{
    return length;
}

double Road::get_width() const
{
    return width;
}

// Computes the cubic feet of asphalt required to build the road
// Length is measured in miles so a conversion factor is used to change the unit to feet (1mi/5280ft)
// Thickness is measured in inches (1ft/12in)
double Road::asphalt(double road_thickness)
{
    return road_thickness*(1.0/12)*get_width()*get_length()*5280;  // Height * (1ft/12in) * Width * Length (in miles) * (1mi/5280ft)
}