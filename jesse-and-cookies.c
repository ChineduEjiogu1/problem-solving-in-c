#include <stdio.h>

int cookies(int k, int A_count, int* A) 
{
    int minimum = 0, secondMinimum = 0;
    int timesOne = 1, timesTwo = 2;
    int counter = 0;

    for(int i = 0; i < A_count; i++)
    {
        if(A[i] >= k)
            return -1;

        if(minimum > A[i])
            minimum = A[i];

        printf("%d", minimum);

        if (secondMinimum > minimum && secondMinimum < A[i])
            secondMinimum = A[i];

        while(A[i] <= k)
        {
            A[i] = (timesOne * minimum) + (timesTwo * secondMinimum);
            counter++;
        }
    }
    return counter;
}

int main()
{
    int A[6] =  {2, 7, 3, 6, 4, 6};
    int B[6] =  {1, 2, 3, 9, 10, 12};

    printf("%d\n", (9, 6, *A));
    // printf("%d\n", (7, 6, *B));
    return 0;
}