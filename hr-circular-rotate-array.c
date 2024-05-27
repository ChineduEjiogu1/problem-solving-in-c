#include <stdio.h>
#include <stdlib.h>

int *circularArrayRotation(int a_count, int *a, int k, int queries_count, int *queries, int *result_count)
{
    k = k % a_count; // Handle cases where k > n
    int *result = (int *)malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; ++i)
    {
        int newIndex = (queries[i] + a_count - k) % a_count;
        result[i] = a[newIndex];
    }

    *result_count = queries_count;
    return result;
}

int main()
{
    // Example usage
    int a[] = {1, 2, 3, 4, 5};
    int a_count = sizeof(a) / sizeof(a[0]);
    int k = 2;
    int queries[] = {1, 3}; // Indices to query
    int queries_count = sizeof(queries) / sizeof(queries[0]);
    int result_count;

    int *result = circularArrayRotation(a_count, a, k, queries_count, queries, &result_count);

    printf("Rotated array elements at queried indices:\n");
    for (int i = 0; i < result_count; ++i)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result); // Don't forget to free the allocated memory

    return 0;
}
