#include <iostream>
#include "Rational.cpp"

using namespace std;

int main()
{
    Rational x(3, 2);
    Rational y(5, 3);
    Rational z(6, 5);

    Rational test1 = x + y;
    cout << "x + y = " << test1 << "\n"
         << "z = " << z << "\n";

    Rational test2 = test1 - z;
    cout << test2 << "\n";

    // expected: 2
    Rational test3 = z * y;
    cout << test3 << "\n";

    Rational xx(2, 5), yy(4, 10);
    xx == yy ? cout << "i due razionali sono uguali\n" : cout << "i due razionali sono diversi\n";

    test2 == y ? cout << "i due razionali sono uguali\n" : cout << "i due razionali sono diversi\n";

    Rational test4 = z + 3;
    cout << "z + 3 = " << test4 << "\n";

    test4 = test4 / 21;
    cout << "z / 21 = " << test4 << "\n";

    return 0;
}