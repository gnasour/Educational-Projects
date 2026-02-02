#ifndef TIME_HPP
#define TIME_HPP

class Time
{
public:
    Time();
    Time(double hours, double minutes, double seconds);

    void setHours(double hours);
    void setMinutes(double minutes);
    void setSeconds(double seconds);

    double timeInHours() const;
    double timeInMinutes() const;
    double timeInSeconds() const;
private:
    int hours, minutes, seconds;
};

#endif