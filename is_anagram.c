#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool is_anagram(const char *s1, const char *s2)
{
    int string_1_length = strlen(s1);
    int string_2_length = strlen(s2);

    int freq[256] = {0};

    if (string_1_length != string_2_length)
    {
        return false;
    }

    for (int i = 0; s1[i] != '\0'; i++)
    {
       
        freq[tolower(s1[i])]++;  
    }

    for (int j = 0; s2[j] != '\0'; j++)
    {   
        freq[tolower(s2[j])]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0) 
        {
            return false;
        }
    }

	return true;
}

int main()
{
    char string_1[100]; // Allocate enough space for the first string
    char string_2[100]; // Allocate enough space for the second string

    printf("Enter a string: ");
    scanf("%99s", string_1); // Use %99s to avoid buffer overflow

    printf("Enter another string: ");
    scanf("%99s", string_2); // Use %99s to avoid buffer overflow

    int result = is_anagram(string_1, string_2);

    printf("%d", result);

}