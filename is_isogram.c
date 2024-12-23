#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool IsIsogram (const char *string) 
{
    int freq[256] = {0};

    int i = 0;

    int string_length = strlen(string);
    char *copy_of_string = (char *)malloc(string_length + 1);
    strcpy(copy_of_string, string);

    for (int i = 0; string[i] != '\0'; i++)
    {
        copy_of_string[i] = tolower(string[i]);

        if (isalpha(copy_of_string[i]))
            freq[copy_of_string[i]]++;
    }

    for (int j = 0; copy_of_string[j] != '\0'; j++)
    {
        if (freq[copy_of_string[j]] != 1)
        {
            return false;
        }
    }

    free(copy_of_string);

    return true;
}


int main()
{
    const char *string = "abcde";

    int result = IsIsogram(string);

    printf("%d", result);
}