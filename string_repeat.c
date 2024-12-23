#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *repeat_str(size_t count, const char *src)
{
    int src_length = strlen(src);
    int new_length = src_length * count;

    int j = 0;

    char *multiplied_string = (char *)malloc(new_length + 1);


    for (int k = 0; k < count; k++)
    {
        for (int i = 0; src[i] != '\0'; i++) 
        { 
            {
                multiplied_string[j++] = src[i];
            } 
        }      
    }

    multiplied_string[j] = '\0';

    return multiplied_string;
}

int main()
{
    const char *string = "Hello";

    int frequency = 6;

    char *result = repeat_str(frequency, string);

    printf("%s", result);
}