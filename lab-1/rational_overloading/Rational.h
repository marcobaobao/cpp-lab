class Rational
{
private:
    /*
        n := numeratore
        d := denominatore

        gcd(a,b) := calcolo massimo comune divisore
        reduction() := semplificazione frazione
    */
    int n;
    int d;

    void validate(int d);
    int gcd(int a, int b);
    Rational reduction();

public:
    Rational();

    Rational(int n, int d);

    Rational(const Rational &);


    int numerator() const;

    int denominator() const;

    double toDouble(Rational &r);

    Rational operator+(const Rational &r);

    Rational operator-(const Rational &r);

    Rational operator*(const Rational &r);

    Rational operator/(const Rational &r);

    Rational operator+(int a);

    Rational operator-(int a);

    Rational operator*(int a);

    Rational operator/(int a);

    bool operator==(const Rational &r) const;

    friend ostream &operator<<(ostream &out, const Rational &r);
};