#include <iostream>
using namespace std;

int main()
{
    int my_int, *p1, *p2, *p3;
    p1 = &my_int;
    p2 = &my_int;
    p3 = &my_int;

    my_int = 29;
    *p1 = 3;
    printf("my_int:  %d | p1: %p | &p1: %p | *p1: %d\n", my_int, p1, &p1, *p1);
    printf("my_int:  %d | p2: %p | &p2: %p | *p2: %d\n", my_int, p2, &p2, *p2);

    *p2 = 24;
    printf("my_int: %d | p1: %p | &p1: %p | *p1: %d\n", my_int, p1, &p1, *p1);
    printf("my_int: %d | p2: %p | &p2: %p | *p2: %d\n", my_int, p2, &p2, *p2);

    *p3 = 19;
    printf("my_int: %d | p1: %p | &p1: %p | *p1: %d\n", my_int, p1, &p1, *p1);
    printf("my_int: %d | p2: %p | &p2: %p | *p2: %d\n", my_int, p2, &p2, *p2);
    printf("my_int: %d | p3: %p | &p3: %p | *p3: %d\n", my_int, p3, &p3, *p3);

    return 0;
}