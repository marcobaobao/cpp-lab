#include <iostream>

using namespace std;

/*
    Semplicissima implmementazione della classe date
*/

class Date
{
private:
    int _d;
    int _m;
    int _y;

public:
    Date();
    Date(int d);
    Date(int d, int m);
    Date(int d, int m, int y);

    friend ostream &operator<<(ostream &out, const Date &date);
};

Date::Date()
{
    _d = 1;
    _m = 1;
    _y = 0;
}

Date::Date(int d)
{
    _d = d > 0 ? d : 1;
    _m = 1;
    _y = 0;
}

Date::Date(int d, int m)
{
    _d = d > 0 ? d : 1;
    _m = m > 0 && m <= 12 ? m : 1;
    _y = 0;
}

Date::Date(int d, int m, int y)
{
    _d = d > 0 ? d : 1;
    _m = m > 0 && m <= 12 ? m : 1;
    _y = y ? y : 0;
}

ostream &operator<<(ostream &out, const Date &date)
{
    out << date._d << "/" << date._m << "/" << date._y;
    return out;
}
