/*
    Design and implement a Book class similar to the one you would find in a software
    developed for a library. Class Book should have members for the ISBN, title, author and
    copyright date. Also store data on whether or not the book has been checked out. Do the
    following:
    a. Create functions for returning those data values.
    b. Create a function for creating a new book (constructor).
    c. Create functions for checking books in and out.
    d. Do simple validation of data entered into a Book. Store an ISBN as a string, accepting
    any string configuration.
    e. Implement the == operator that checks whether the ISBN strings are the same for
    two books.
    f. Have != also compare the ISBN strings.
    g. Have a << operator print out the title, author and ISBN on separate lines.
*/
#include <iostream>
#include "Date.cpp"

using namespace std;

class Book
{
private:
    string _isbn;
    string _title;
    string _author;
    Date _copyrightDate;
    bool _chekedOut;

    bool isValid(string isbn, string title, string author);

public:
    Book(string isbn, string title, string author, Date copyrightDate);
    Book(string isbn, string title, string author, Date copyrightDate, bool checkedOut);

    string getIsbn() { return _isbn; }
    string getTitle() { return _title; }
    string getAuthor() { return _author; }
    Date getCopyrightDate() { return _copyrightDate; }
    bool getCheckedOut() { return _chekedOut; }

    void checkIn();
    void checkOut();

    bool operator==(Book &b);
    bool operator!=(Book &b);

    friend ostream &operator<<(ostream &out, const Book &b);
};

Book::Book(string isbn, string title, string author, Date copyrightDate)
{
    if (!isValid(isbn, title, author))
        throw "check failed!";
    _isbn = isbn;
    _title = title;
    _author = author;
    _copyrightDate = copyrightDate;
    _chekedOut = false;
}

Book::Book(string isbn, string title, string author, Date copyrightDate, bool checkedOut)
{
    _isbn = isbn;
    _title = title;
    _author = author;
    _copyrightDate = copyrightDate;
    _chekedOut = checkedOut;
}

bool Book::isValid(string isbn, string title, string author)
{
    return isbn.size() != 0 && title.size() != 0 && author.size() != 0;
}

void Book::checkIn()
{
    _chekedOut = false;
}

void Book::checkOut()
{
    _chekedOut = true;
}

bool Book::operator==(Book &b)
{
    return _isbn.compare(b._isbn) == 0;
}

bool Book::operator!=(Book &b)
{
    return _isbn.compare(b._isbn) != 0;
}

ostream &operator<<(ostream &out, const Book &r)
{
    out << "Informazioni libro\n"
        << "------------------\n"
        << "Titolo: " << r._title << "\n"
        << "Autore: " << r._author << "\n"
        << "Data: " << r._copyrightDate << "\n"
        << "ISBN: " << r._isbn << "\n"
        << "Disponibilità: " << (r._chekedOut ? "non disponibile" : "disponibile")
        << "\n------------------\n";

    return out;
}