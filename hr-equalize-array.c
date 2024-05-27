#include <stdio.h>

int equalize_array(int arr_count, int *arr)
{
    int counter_of_frequenices[101] = {0};
    int result = 0;
    int max_frequency = 0;

    for (int i = 0; i < arr_count; i++)
    {
        counter_of_frequenices[arr[i]]++;
    }

    for (int i = 1; i <= 100; i++)
    {
        if (counter_of_frequenices[i] > max_frequency)
        {
            max_frequency = counter_of_frequenices[i];
        }
    }

    result = arr_count - max_frequency;

    return result;
}

int main()
{
    int arr[8] = {1, 2, 3, 1, 2, 3, 3, 3};

    int arr_count = sizeof(arr) / sizeof(arr[0]);

    int result = equalize_array(arr_count, arr);

    printf("%d\n", result);
}