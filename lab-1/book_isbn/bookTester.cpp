#include <iostream>
#include "Book.cpp"

using namespace std;

int main()
{
    Book b1("123456", "un libro", "mio", Date(2, 3, 1200));
    cout << b1;

    b1.checkOut();

    cout << b1;

    Book b2("654321", "un altro libro", "mio", Date(29, 3, 2018), true);

    cout << b2;

    b2.checkIn();

    cout << b2;

    cout << "> " << (b1 == b2 ? "ISBN coincide" : "ISBN non coincide") << "\n";

    return 0;
}