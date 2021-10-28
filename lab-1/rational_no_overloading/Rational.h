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
    void reduction();

public:
    Rational(int n, int d);

    Rational(const Rational &);

    int numerator() const;

    int denominator() const;

    double toDouble();

    void add(const Rational &r);

    void subtract(const Rational &r);

    void multiply(const Rational &r);

    void divide(const Rational &r);

    bool operator==(Rational &r) const;

    void print_double();
};