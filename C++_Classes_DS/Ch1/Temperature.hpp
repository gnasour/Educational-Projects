#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

#define KELVIN_FREEZING 273.15

class Temperature
{
public:
    void          set_temp_f(double fahr);
    void          set_temp_c(double cels);
    double        get_temp_f();
    double        get_temp_c();
    inline double convert_f_to_k(double fahr);
    inline double convert_c_to_k(double cels);
private:
    double kelvin; // The temperature will be stored in Kelvin to simplify storage and conversions
};

#endif