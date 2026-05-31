

class Date
{
public:
    class Invalid
    { // Used for Date exceptions
    };
    Date(int y, int m, int d);
    void add_day(int n);
    int month() { return m; }
    int day() { return d; }
    int year() { return y; }

private:
    int y, m, d;
    bool is_valid();
};

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

Date::Date(int yy, int mm, int dd)
    : y{yy}, m{mm}, d{dd}
{
    if (!is_valid())
    {
        throw Invalid();
    }
}

bool Date::is_valid()
{
    if (m < 1 || m > 12)
    {
        return false;
    }

    return true;
}