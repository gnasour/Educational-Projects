#ifndef DATE_H
#define DATE_H

#include <ostream>
#include <istream>

namespace Chrono
{

    enum class Month
    {
        jan = 1,
        feb,
        mar,
        apr,
        may,
        jun,
        jul,
        aug,
        sept,
        oct,
        nov,
        dec
    };

    enum class Day
    {
        monday,
        tuesday,
        wedenesday,
        thursday,
        friday,
        saturday,
        sunday
    };

    class Date
    {
    public:
        class Invalid
        { // Used for Date exceptions
        };
        Date(int y, Month m, int d);
        Date();

        Month month() const { return m; }
        int day() const { return d; }
        int year() const { return y; }

        void add_day(int n);
        void add_month(int n);
        void add_year(int n);

    private:
        int y, d;
        Month m;
    };

    bool is_date(int y, Month m, int d);
    bool leapyear(int y);
    bool operator==(const Date &a, const Date &b);
    bool operator!=(const Date &a, const Date &b);

    std::ostream &operator<<(std::ostream &os, const Date &d);

    std::istream &operator>>(std::istream &is, Date &dd);

}
#endif