#include <stdio.h>


int main()
{
    int x = 0;
    int product = 0;
    printf("Enter an integer> ");
    scanf("%d", &x);
    product = x;
    int count = 0;

    while (count < 4)
    {
        printf("%d\n", product);
        product *= x;
        count += 1;
    }
}