#include "Time.hpp"

Time::Time()
{

}

Time::Time(double hours, double minutes, double seconds)
{
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

void Time::setHours(double hours)
{
    this->hours = hours;
}

void Time::setMinutes(double minutes)
{
    this->minutes = minutes;
}

void Time::setSeconds(double seconds)
{
    this->seconds = seconds;
}

double Time::timeInHours() const
{
    return hours + (minutes/60.0) + (seconds/3600.0);
}

double Time::timeInMinutes() const
{
    return (hours*60.0) + minutes + (seconds/60.0);
}

double Time::timeInSeconds() const
{
    return (hours*3600.0) + (minutes*60.0) + seconds;
}