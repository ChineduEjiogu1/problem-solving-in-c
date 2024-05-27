// version 1

// #include <stdio.h>
// #include <stdlib.h>

// int* cutTheSticks(int arr_count, int* arr, int* result_count) {
//     // Initialize an array to store the results
//     int* result = (int*)malloc(arr_count * sizeof(int));

//     // Initialize the result_count
//     *result_count = 0;

//     // Find the maximum stick length
//     int max_length = arr[0];
//     for (int i = 1; i < arr_count; i++) {
//         if (arr[i] > max_length) {
//             max_length = arr[i];
//         }
//     }

//     // Initialize an array to count sticks of each length
//     int* count = (int*)calloc(max_length + 1, sizeof(int));
//     for (int i = 0; i < arr_count; i++) {
//         count[arr[i]]++;
//     }

//     // Iterate through the array and cut the sticks
//     int remaining_sticks = arr_count;
//     for (int i = 1; i <= max_length; i++) {
//         if (count[i] > 0) {
//             result[(*result_count)++] = remaining_sticks;
//             remaining_sticks -= count[i];
//         }
//     }

//     free(count);

//     return result;
// }

// int main() {
//     int arr[6] = {5, 4, 4, 2, 2, 8};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int result_count = 0;

//     int* result = cutTheSticks(size, arr, &result_count);

//     // Print the results
//     for (int i = 0; i < result_count; i++) {
//         printf("%d\n", result[i]);
//     }

//     free(result);  // Don't forget to free the allocated memory

//     return 0;
// }

// version 2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Function to find the minimum value greater than zero in the array
int find_minimum_value(int *arr, int arr_count)
{
    int min_val = INT_MAX;
    for (int i = 0; i < arr_count; i++)
    {
        if (arr[i] > 0 && arr[i] < min_val)
        {
            min_val = arr[i];
        }
    }
    return min_val;
}

// Function to check if all elements in the array are zero
bool is_ending_condition(int *arr, int arr_count)
{
    for (int i = 0; i < arr_count; i++)
    {
        if (arr[i] > 0)
        {
            return false;
        }
    }
    return true;
}

// Function to cut the sticks and return the result count array
int *cut_the_sticks(int arr_count, int *arr, int *result_count)
{
    int *results = (int *)malloc(arr_count * sizeof(int));
    int j = 0;

    while (!is_ending_condition(arr, arr_count))
    {
        int current_minimum_val = find_minimum_value(arr, arr_count);
        int counter_of_size = 0;

        for (int i = 0; i < arr_count; i++)
        {
            if (arr[i] >= current_minimum_val)
            {
                arr[i] -= current_minimum_val;
                counter_of_size++;
            }
        }

        results[j] = counter_of_size;
        j++;
    }

    *result_count = j;
    return results;
}

int main()
{
    int arr[] = {5, 4, 4, 2, 2, 8};
    int arr_count = sizeof(arr) / sizeof(arr[0]);
    int result_count;

    int *results = cut_the_sticks(arr_count, arr, &result_count);

    for (int i = 0; i < result_count; i++)
    {
        printf("Result is: %d\n", results[i]);
    }

    free(results);
    return 0;
}

// version 3

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include <limits.h>

// // Function to find the minimum value greater than zero in the array
// int find_minimum_value(int *arr, int arr_count)
// {
//     int min_val = INT_MAX;
//     for (int i = 0; i < arr_count; i++)
//     {
//         if (arr[i] > 0 && arr[i] < min_val)
//         {
//             min_val = arr[i];
//         }
//     }
//     return min_val;
// }

// // Function to check if all elements in the array are zero
// bool is_ending_condition(int *arr, int arr_count)
// {
//     for (int i = 0; i < arr_count; i++)
//     {
//         if (arr[i] > 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// // Function to cut the sticks and return the result count array
// int *cut_the_sticks(int arr_count, int *arr, int *result_count)
// {
//     int *results = (int *)malloc(arr_count * sizeof(int));
//     int j = 0;

//     while (!is_ending_condition(arr, arr_count))
//     {
//         int current_minimum_val = find_minimum_value(arr, arr_count);
//         int counter_of_size = 0;

//         for (int i = 0; i < arr_count; i++)
//         {
//             if (arr[i] > 0)
//             {
//                 arr[i] -= current_minimum_val;
//                 counter_of_size++;
//             }
//         }

//         results[j] = counter_of_size;
//         j++;
//     }

//     *result_count = j;
//     return results;
// }

// int main()
// {
//     int arr[] = {5, 4, 4, 2, 2, 8};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int result_count;

//     int *results = cut_the_sticks(size, arr, &result_count);

//     for (int i = 0; i < result_count; i++)
//     {
//         printf("Result is: %d\n", results[i]);
//     }

//     free(results);
//     return 0;
// }
