#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

#define KELVIN_FREEZING 273.15

class Temperature
{
public:
    Temperature();
    Temperature(double temp_input, int temp_choice);

    void          set_temp_f(double fahr);
    void          set_temp_c(double cels);
    
    double        get_temp_f() const;
    double        get_temp_c() const;
    
    inline double convert_f_to_k(double fahr) const;
    inline double convert_c_to_k(double cels) const;
private:
    double kelvin; // The temperature will be stored in Kelvin to simplify storage and conversions
};

#endif