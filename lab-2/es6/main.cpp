#include <iostream>

int main()
{
    char str[] = "a string";
    int i = 0;
    while (str[i] != '\0')
    {
        std::cout << str[i];
        i++;
    }
    std::cout << "\n"
              << (int)'\0'
              << "\n";
    return 0;
}