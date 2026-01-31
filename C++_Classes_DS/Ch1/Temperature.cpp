#include "Temperature.hpp"

void Temperature::set_temp_f(double fahr)
{
    kelvin = convert_f_to_k(fahr);
}

void Temperature::set_temp_c(double cels)
{
    kelvin = convert_c_to_k(cels);
}

double Temperature::get_temp_c()
{
    return kelvin - KELVIN_FREEZING;
}

double Temperature::get_temp_f()
{
    return (kelvin-KELVIN_FREEZING)*(9.0/5) + 32;
}

inline double Temperature::convert_c_to_k(double cels)
{
    return cels + KELVIN_FREEZING;
}

inline double Temperature::convert_f_to_k(double fahr)
{
    return (5.0/9)*(fahr-32) + KELVIN_FREEZING;
}