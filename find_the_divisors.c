#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void divisors(unsigned n, size_t *length, unsigned array[])
{
    *length = 0;

    for (unsigned divisor = 2; divisor < n; divisor++)
    {
        if (n % divisor == 0)
        {
            array[(*length)++] = divisor;
        }
    }

    if (*length == 0)
    {
        printf("%u is prime\n", n);
    }
    else
    {
        printf("Divisors of %u: ", n);
        for (int i = 0; i < *length; i++)
        {
            printf("%u ", array[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 0;
    
    printf("%s", "Enter a number: ");
    scanf("%d", &n);
    
    size_t length;
    unsigned array[100]; // Preallocate an array large enough to hold all divisors.

    divisors(n, &length, array);

    return 0;
}