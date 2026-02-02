#include "Temperature.hpp"

Temperature::Temperature()
{
}

Temperature::Temperature(double temp_input, int temp_choice)
{
    switch(temp_choice){
        case 0: // Celsius
            kelvin = convert_c_to_k(temp_input);
            break;
        case 1: // Fahrenheit
            kelvin = convert_f_to_k(temp_input);
            break;
    }
}

void Temperature::set_temp_f(double fahr)
{
    kelvin = convert_f_to_k(fahr);
}

void Temperature::set_temp_c(double cels)
{
    kelvin = convert_c_to_k(cels);
}

double Temperature::get_temp_c() const
{
    return kelvin - KELVIN_FREEZING;
}

double Temperature::get_temp_f() const
{
    return (kelvin-KELVIN_FREEZING)*(9.0/5) + 32;
}

inline double Temperature::convert_c_to_k(double cels) const
{
    return cels + KELVIN_FREEZING;
}

inline double Temperature::convert_f_to_k(double fahr) const
{
    return (5.0/9)*(fahr-32) + KELVIN_FREEZING;
}