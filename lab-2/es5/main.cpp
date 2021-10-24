#include <iostream>

void print_reference(const double &d_ref, const int &i_ref)
{
    std::cout << d_ref << "\n"
              << i_ref << "\n";
}

void print_pointer(double *d_ptr, int *i_ptr)
{
    std::cout << d_ptr << "\n"
              << i_ptr << "\n";
}

int main()
{
    int a_int;
    double a_double;
    print_reference(a_double, a_int);
    print_pointer(&a_double, &a_int);
    return 0;
}