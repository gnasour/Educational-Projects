#include "Time.hpp"

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

double Time::timeInHours()
{
    return hours + (minutes/60.0) + (seconds/3600.0);
}

double Time::timeInMinutes()
{
    return (hours*60.0) + minutes + (seconds/60.0);
}

double Time::timeInSeconds()
{
    return (hours*3600.0) + (minutes*60.0) + seconds;
}