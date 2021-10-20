class Rational
{
private:
    /*
        due proprietà:  
        n := numeratore
        d := denominatore

        headers:
        gcd(a,b) := calcolo massimo comune divisore
        reduction() := semplificazione frazione
    */
    int n;
    int d;

    int gcd(int a, int b);
    void reduction();

public:
    //headers member functions
    Rational(int n, int d);

    Rational(const Rational &);

    int numerator() const;

    int denominator() const;

    double toDouble();

    void validate(int d);

    void add(const Rational &r);

    void subtract(const Rational &r);

    void multiply(const Rational &r);

    void divide(const Rational &r);

    bool operator==(Rational &r) const;

    void print_double();
};

Rational::Rational(int nn, int dd)
{
    validate(dd);
    n = nn ? nn : 0;
    d = dd ? dd : 1;
};

Rational::Rational(const Rational &r)
{
    this->n = r.n;
    this->d = r.d;
}

int Rational::numerator() const
{
    return n;
}

int Rational::denominator() const
{
    return d;
}

void Rational::validate(int d)
{
    if (d == 0)
        throw "Denominatore non può essere zero";
}

void Rational::add(const Rational &r)
{
    n = (n * r.denominator()) + (d * r.numerator());
    d *= r.denominator();
    this->reduction();
}

void Rational::subtract(const Rational &r)
{
    n = (n * r.denominator()) - (d * r.numerator());
    d *= r.denominator();
    this->reduction();
}

void Rational::multiply(const Rational &r)
{
    n = this->n * r.numerator();
    d = this->d * r.denominator();
    this->reduction();
}

void Rational::divide(const Rational &r)
{
    n = this->n * r.denominator();
    d = this->d * r.numerator();
    this->reduction();
}

double Rational::toDouble()
{
    return static_cast<double>(n) / static_cast<double>(d);
}

bool Rational::operator==(Rational &r) const
{
    Rational temp1 = r;
    Rational temp2(*this);

    temp1.reduction();
    temp2.reduction();

    return temp1.n == temp2.n && temp1.d == temp2.d;
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

void Rational::reduction()
{
    // fix se denominatore < 0
    if (d < 0)
    {
        n *= -1;
        d *= -1;
    }

    int denominator = gcd(n, d);
    n /= denominator;
    d /= denominator;
}