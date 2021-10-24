#include <iostream>

constexpr int size = 100;

void print_array_lenght(double *arr)
{
    std::cout << sizeof(arr) << "\n";
    arr[2] = 12;
    std::cout << arr[2] << "\n";
}

int main()
{
    double arr[size];
    std::cout << sizeof(arr) << "\n";

    print_array_lenght(arr);
    // non conosce la dimensione dell'array
    // accesso permesso

    return 0;
}