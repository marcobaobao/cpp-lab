#include <iostream>

bool is_palindrome(const std::string &s);

int main()
{
    std::string str{"anna"};
    is_palindrome(str) ? std::cout << "palindrome" : std::cout << "not palindrome";

    std::string str{"test"};
    is_palindrome(str) ? std::cout << "palindrome" : std::cout << "not palindrome";
    return 0;
}

bool is_palindrome(const std::string &s)
{
    if (s.empty())
        return false;
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}