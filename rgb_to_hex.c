#include <stdio.h>

void rgb(int r, int g, int b, char hex[6 + 1])
{
    int i = 0;

    if (r < 0)
        r = 0;
    if (r > 255)
        r = 255;
    if (g < 0)
        g = 0;
    if (g > 255)
        g = 255;
    if (b < 0)
        b = 0;
    if (b > 255)
        b = 255;

    hex[i++] = (r / 16 < 10) ? ('0' + r / 16) : ('A' + r / 16 - 10); // Most significant hex digit
    hex[i++] = (r % 16 < 10) ? ('0' + r % 16) : ('A' + r % 16 - 10); // Least significant hex digit

    hex[i++] = (g / 16 < 10) ? ('0' + g / 16) : ('A' + g / 16 - 10);
    hex[i++] = (g % 16 < 10) ? ('0' + g % 16) : ('A' + g % 16 - 10);

    hex[i++] = (b / 16 < 10) ? ('0' + b / 16) : ('A' + b / 16 - 10);
    hex[i++] = (b % 16 < 10) ? ('0' + b % 16) : ('A' + b % 16 - 10);

    // write to the hex string
    hex[i] = '\0';

    printf("%s", hex);
}

int main()
{
    int r = 111; int g = 255; int b = 50;

    char hex[6 + 1] = {0};

    rgb(r, g, b, hex);

    printf("\n");

    return 0;
}