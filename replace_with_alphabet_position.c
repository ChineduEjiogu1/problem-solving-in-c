#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *alphabet_position(const char *text)
{
    int j = 0;

    int text_length = strlen(text);
    char *copy_of_text = (char *)malloc(text_length + 1);
    strcpy(copy_of_text, text);

    char *result_string = (char *)malloc(1000 + 1);

    for (int i = 0; copy_of_text[i] != '\0'; i++)
    {
        if (!isalpha(copy_of_text[i]))
        {
            continue;
        }
        else if (copy_of_text[i] >= 'a' && copy_of_text[i] <= 'z')
        {
            j += sprintf(&result_string[j], "%d ", copy_of_text[i] - 'a' + 1);
        }
        else if (copy_of_text[i] >= 'A' && copy_of_text[i] <= 'Z')
        {
            j += sprintf(&result_string[j], "%d ", copy_of_text[i] - 'A' + 1);
        }
    }

    // Remove the trailing space, if any
    if (j > 0 && result_string[j - 1] == ' ')
    {
        result_string[j - 1] = '\0';
    }

    free(copy_of_text);

    return result_string;
}

int main()
{
    const char *sentence = "The narwhal bacons at midnight.";

    char *result = alphabet_position(sentence);

    printf("%s", result);

    free(result);
}