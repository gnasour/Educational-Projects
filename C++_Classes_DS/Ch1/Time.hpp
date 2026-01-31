#ifndef TIME_HPP
#define TIME_HPP

class Time
{
public:
    void setHours(double hours);
    void setMinutes(double minutes);
    void setSeconds(double seconds);

    double timeInHours();
    double timeInMinutes();
    double timeInSeconds();
private:
    int hours, minutes, seconds;
};

#endif