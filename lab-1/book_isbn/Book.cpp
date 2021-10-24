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
#include <vector>
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
    bool validateISBN(string isbn);

public:
    Book(string isbn, string title, string author, Date copyrightDate);
    Book(string isbn, string title, string author, Date copyrightDate, bool checkedOut);

    string getIsbn()
    {
        return _isbn;
    }
    string getTitle()
    {
        return _title;
    }
    string getAuthor()
    {
        return _author;
    }
    Date getCopyrightDate()
    {
        return _copyrightDate;
    }
    bool getCheckedOut()
    {
        return _chekedOut;
    }

    void checkIn();
    void checkOut();

    bool operator==(Book &b);
    bool operator!=(Book &b);

    friend ostream &operator<<(ostream &out, const Book &b);
};

Book::Book(string isbn, string title, string author, Date copyrightDate)
{
    if (!isValid(isbn, title, author))
        throw runtime_error("check failed!");
    _isbn = isbn;
    _title = title;
    _author = author;
    _copyrightDate = copyrightDate;
    _chekedOut = false;
}

Book::Book(string isbn, string title, string author, Date copyrightDate, bool checkedOut)
{
    if (!isValid(isbn, title, author))
        throw runtime_error("check failed!");
    _isbn = isbn;
    _title = title;
    _author = author;
    _copyrightDate = copyrightDate;
    _chekedOut = checkedOut;
}

bool Book::isValid(string isbn, string title, string author)
{
    return validateISBN(isbn) && title.size() > 0 && author.size() > 0;
}

bool Book::validateISBN(string isbn)
{
    bool validIsbn = false;
    if (isbn.size() > 0)
    {
        char sep = '-';
        // vector<string> parts;
        vector<int> separators;

        // scan separators position
        for (unsigned int i = 0; i < isbn.size(); i++)
        {
            if (isbn[i] == sep)
            {
                separators.push_back(i);
            }
        }
        // there are less than 3 parts in the code so it doensn't respect the n-n-n-x format
        if (separators.size() < 3)
        {
            throw runtime_error("wrong ISBN format");
        }

        string parts1 = (isbn.substr(0, separators[0]));
        string parts2 = (isbn.substr(separators[0] + 1, (separators[1] - separators[0]) - 1));
        string parts3 = (isbn.substr(separators[1] + 1, (separators[2] - separators[1]) - 1));
        string parts4 = (isbn.substr(separators[2] + 1));

        // check each part in order to check if they're composed only by integers
        for (char const &ch : parts1)
        {
            if (!isdigit(ch))
                return false;
        }

        for (char const &ch : parts2)
        {
            if (!isdigit(ch))
                return false;
        }

        for (char const &ch : parts3)
        {
            if (!isdigit(ch))
                return false;
        }
    }
    // the prior checks are positive, checking the fourth part makes no difference
    return true;
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
    out << "Info\n"
        << "------------------\n"
        << "Title: " << r._title << "\n"
        << "Author: " << r._author << "\n"
        << "Date: " << r._copyrightDate << "\n"
        << "ISBN: " << r._isbn << "\n"
        << "Availability: " << (r._chekedOut ? "available" : "not available")
        << "\n------------------\n";

    return out;
}