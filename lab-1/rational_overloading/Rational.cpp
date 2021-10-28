#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational()
{
    n = 0;
    d = 1;
}

Rational::Rational(int nn, int dd)
{
    validate(dd);
    d = dd ? dd : 1;
    n = nn ? nn : 0;
}

Rational::Rational(const Rational &r)
{
    n = r.n;
    d = r.d;
}

void Rational::validate(int d)
{
    if (d == 0)
        throw "Denominatore non può essere zero";
}

int Rational::numerator() const
{
    return n;
}

int Rational::denominator() const
{
    return d;
}

Rational Rational::operator+(const Rational &r)
{
    Rational t((n * r.d) + (d * r.n),
               d * r.d);
    return t.reduction();
}

Rational Rational::operator-(const Rational &r)
{
    Rational t((n * r.d) - (d * r.n),
               d * r.d);
    return t.reduction();
}

Rational Rational::operator*(const Rational &r)
{
    Rational t(n * r.n,
               d * r.d);
    return t.reduction();
}

Rational Rational::operator/(const Rational &r)
{
    Rational t(n * r.d,
               d * r.n);
    return t.reduction();
}

Rational Rational::operator+(int a)
{
    Rational t(n + (d * a), d);
    return t.reduction();
}

Rational Rational::operator-(int a)
{
    Rational t(n - (d * a), d);
    return t.reduction();
}

Rational Rational::operator*(int a)
{
    Rational t(n * a, d);
    return t.reduction();
}

Rational Rational::operator/(int a)
{
    Rational t(n,d * a);
    return t.reduction();
}

bool Rational::operator==(const Rational &r) const
{
    Rational temp1 = r;
    Rational temp2(*this);

    return temp1.reduction().n == temp2.reduction().n &&
           temp1.reduction().d == temp2.reduction().d;
}

// MCD con formula euclidea ricorsiva
int Rational::gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

Rational Rational::reduction()
{
    int _n = n;
    int _d = d;
    // fix se denominatore < 0
    if (_d < 0)
    {
        _n *= -1;
        _d *= -1;
    }

    int denominator = gcd(_n, _d);
    _n /= denominator;
    _d /= denominator;

    return Rational(_n, _d);
}

double Rational::toDouble(Rational &r)
{
    return static_cast<double>(r.numerator()) / static_cast<double>(r.denominator());
}

ostream &operator<<(ostream &out, const Rational &r)
{
    out << r.numerator() << "/" << r.denominator();
    return out;
}
