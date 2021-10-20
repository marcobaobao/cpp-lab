using namespace std;

#include "Rational.cpp"
#include <iostream>

int main()
{
    Rational x(3, 2);
    Rational y(5, 3);
    Rational z(6, 5);

    x.add(y);
    cout << x.toDouble() << "\n"
         << z.toDouble() << "\n";

    x.subtract(z);
    cout << x.toDouble() << "\n";

    // expected: 2
    z.multiply(y);
    cout << z.toDouble() << "\n";

    Rational xx(2, 5), yy(4, 10);
    xx == yy ? cout << "i due razionali sono uguali\n" : cout << "i due razionali sono diversi\n";

    x == y ? cout << "i due razionali sono uguali\n" : cout << "i due razionali sono diversi\n";

    return 0;
}