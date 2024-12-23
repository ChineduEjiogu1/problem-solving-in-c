#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int *delete_nth(size_t szin, const int *order, int max_e, size_t *szout)
{
    //  <----  hajime!

    int valid_count = 0;

    int j = 0;
    
    size_t freq[100] = {0}; // Assuming elements are in the range 0-99

    for (size_t i = 0; i < szin; i++)
    {
        if (freq[order[i]] < max_e)
        {
            valid_count++;
        }
    }

    int *result = (int *)malloc(valid_count * sizeof(int));

    for (size_t i = 0; i < szin; i++)
    {
        if (freq[order[i]] < max_e)
        {
            result[j++] = order[i];
            valid_count++;
            freq[order[i]]++;
        } 

        printf("%ld \n", freq[order[i]]);
    } 
    
    *szout = j;

    return result;
}

int main() 
{
    int array[] = {1, 2, 3, 1, 2, 1, 2, 3};
    int size = sizeof(array) / sizeof(array[0]);

    size_t new_size = 99;

    size_t *new_array_size = (size_t *)malloc(new_size * sizeof(size_t));
    
    int num = 3;
    int frequency_limit = 2;
    
    int *result = delete_nth(size, array, frequency_limit, new_array_size);

    for (size_t i = 0; i < *new_array_size; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}