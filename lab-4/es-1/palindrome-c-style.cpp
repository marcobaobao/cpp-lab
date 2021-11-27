#include <iostream>

bool is_palindrome(const char s[], int length);

int main()
{
    char str[] = "anna";
    is_palindrome(str, 4) ? std::cout << "palindrome\n" : std::cout << "not palindrome\n";

    char str2[] = "test";
    is_palindrome(str2, 4) ? std::cout << "palindrome\n" : std::cout << "not palindrome\n";

    return 0;
}

bool is_palindrome(const char s[], int length)
{
    if (s == nullptr || s[0] == '\0')
    {
        return false;
    }

    int i = 0;
    int j = length - 1;
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