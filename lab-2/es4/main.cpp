#include <iostream>

void print_array(void *arr, int val)
{
    for (int i = 0; i < val; i++)
    {
        int *new_arr = static_cast<int *>(arr);
        std::cout << new_arr[i];
    }
}

int main()
{
    int my_array[50];
    print_array(my_array, 50);

    return 0;
}