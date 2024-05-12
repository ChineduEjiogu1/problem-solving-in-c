#include <stdio.h>

int simpleArraySum(int ar_count, int* ar)
{
    int sum = 0;
    
    for(int i = 0; i < ar_count; i++)
    {
        sum += ar[i];
    }

    return sum;
}

int main()
{
    int size = 6;
    int ar[6] = {1, 2, 3, 4, 10, 11};

    int result = simpleArraySum(size, ar);

    printf("%d\n", result);
    
}