#include <iostream>
#include "Book.cpp"

using namespace std;

int main()
{
    Book b1("1-2-3-4", "a book", "mine", Date(2, 3, 1200));
    cout << b1;

    b1.checkOut();
    cout << b1;

    Book b2("12-3-2222-X", "another book", "mine", Date(29, 3, 2018), true);
    cout << b2;

    b2.checkIn();
    cout << b2;

    cout << "> " << (b1 == b2 ? "ISBN matches" : "ISBN doesn't matches") << "\n";

    return 0;
}