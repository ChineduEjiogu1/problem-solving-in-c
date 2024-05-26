#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int find_minimum_value(int *arr, int arr_count)
{
    int minimum_stick_cut_val = 0;

    for (int i = 0; i < arr_count; i++)
    {
        // if item is less than minimumStickVal and miniMumStickCut does not equal 0
        // assign item to minimumStickcutVal.
        if (arr[i] > 0)
            minimum_stick_cut_val  = arr[i];
    }

    for (int i = 0; i < arr_count; i++)
    {
        // if item is less than minimumStickVal and miniMumStickCut does not equal 0
        // assign item to minimumStickcutVal.
        if (arr[i] < minimum_stick_cut_val  && arr[i] != 0)
           minimum_stick_cut_val  = arr[i];
    }

    return minimum_stick_cut_val ;
}

bool is_ending_condition(int *arr, int arr_count)
{
    for (int i = 0; i < arr_count; i++)
    {
        if (arr[i] > 0)
            return false;
    }
    return true;
}

int *cut_the_sticks(int arr_count, int *arr, int *result_count)
{
    int j = 0;
    
    while (!is_ending_condition(arr, arr_count))
    {
        int current_minimum_val = find_minimum_value(arr, arr_count);
    
        int counter_of_size = 0;

        result_count[j] = 0;

        for (int i = 0; i < arr_count; i++)
        {   
            // if the item does not equal zero and it is greater than the minimum value
            // subtract minimum value from the item
            if (arr[i] != 0 && arr[i] >= current_minimum_val)
            {
                arr[i] = arr[i] - current_minimum_val;
                counter_of_size++;
            }
            printf("%d ", arr[i]);
        }

        result_count[j] = counter_of_size;

        j++;

        printf("\n");
    }

    for (int i = 0; i < arr_count; i++)
    {
        if(result_count[i] != 0)
            printf("result is: %d\n", result_count[i]);
    }

    return result_count;
}

int main()
{
    int arr[6] = {5, 4, 4, 2, 2, 8};
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int result_count[4] = {0};

    int *result = cut_the_sticks(size, arr, result_count);

    for (int i = 0; i < size; i++)
    {
        if(result[i] != 0)
            printf("%d\n", result[i]);
        else
            return 0;
    }

    free(result_count);
}