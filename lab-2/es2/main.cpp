#include <iostream>

void f()
{
    int arr[10];
    int *p = &arr[3];
    *p = 7;

    p[-3] = 2;
    p[-2] = 8;
    p[-1] = 5;
    p[1] = 24;
    p[2] = 3;
    p[3] = 19;
    p[4] = 20;
    p[5] = 21;
    p[6] = 29;
    // ok
}

void illegal_f()
{
    int arr[10];
    int *p = &arr[3];
    *p = 7;

    p[-4] = 99; // ok
    p[8] = 100; // segmentation fault
}

int main()
{
    f();
    illegal_f();
    return 0;
}