#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse_word(char *word)
{
    int len = strlen(word);
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

void extract_substrings(const char *sentence, char *result)
{
    int i, j, len = strlen(sentence), result_index = 0;

    for (i = 0; i < len; i++)
    {
        int word_len = 0;

        for (j = i; j < len && sentence[j] != ' '; j++)
        {
            word_len++;
        }

        if (word_len >= 5)
        {
            char *word = (char *)malloc(word_len + 1);

            strncpy(word, &sentence[i], word_len);
            word[word_len] = '\0';

            reverse_word(word);

            // Copy the reversed word into the result buffer
            strcpy(&result[result_index], word);
            result_index += word_len;

            free(word);
        }
        else
        {
            // Copy the word as it is into the result buffer
            strncpy(&result[result_index], &sentence[i], word_len);
            result_index += word_len;
        }

        if (sentence[j] == ' ')
        {
            result[result_index++] = ' '; // Preserve spaces between words
        }

        i = j; // Move to the end of the current word
    }

    result[result_index] = '\0'; // Null-terminate the result
}

void spin_words(const char *sentence, char *result)
{
    extract_substrings(sentence, result);
}

int main()
{
    const char *sentence = "This is a test string to check the function";
    char result[100]; // Ensure the buffer is large enough to hold the result

    spin_words(sentence, result);
    printf("%s\n", result);

    return 0;
}
