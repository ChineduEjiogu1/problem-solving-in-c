#include <stdio.h>

void roman_numeral_converter(int number)
{
    if (number <= 0)
    {
        printf("Invalid number");
        return;
    }

    printf("Roman numeral: ");

    while (number > 0)
    {
        switch (1)
        {       // Always enter the switch
        case 1: // Handle all cases iteratively
            if (number >= 1000)
            {
                printf("M");
                number -= 1000;
            }
            else if (number >= 900)
            {
                printf("CM");
                number -= 900;
            }
            else if (number >= 500)
            {
                printf("D");
                number -= 500;
            }
            else if (number >= 400)
            {
                printf("CD");
                number -= 400;
            }
            else if (number >= 100)
            {
                printf("C");
                number -= 100;
            }
            else if (number >= 90)
            {
                printf("XC");
                number -= 90;
            }
            else if (number >= 50)
            {
                printf("L");
                number -= 50;
            }
            else if (number >= 40)
            {
                printf("XL");
                number -= 40;
            }
            else if (number >= 10)
            {
                printf("X");
                number -= 10;
            }
            else if (number >= 9)
            {
                printf("IX");
                number -= 9;
            }
            else if (number >= 5)
            {
                printf("V");
                number -= 5;
            }
            else if (number >= 4)
            {
                printf("IV");
                number -= 4;
            }
            else if (number >= 1)
            {
                printf("I");
                number -= 1;
            }
            break;
        }
    }
}

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    roman_numeral_converter(number);

    return 0;
}