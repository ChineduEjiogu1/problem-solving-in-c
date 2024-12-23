#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *highestScoringWord(const char *str)
{
    int str_length = strlen(str);
    char *buffer = (char *)malloc((str_length + 1) * sizeof(char)); // Ensure the buffer is large enough
    strncpy(buffer, str, str_length + 1);

    int current_score = 0;
    int maximum_score = 0;
    char *token = NULL;
    char *maximum_string = NULL;

    token = strtok(buffer, " "); // Start tokenizing

    while (token != NULL)
    {
        current_score = 0;

        // Calculate the score for the current token
        for (int i = 0; token[i] != '\0'; i++)
        {
            // Adjust this scoring logic if you're considering lowercase letters
            current_score += token[i] - 'a' + 1; // a = 1, b = 2, ..., z = 26
        }

        // If the current score is higher than the maximum, update maximum_score and maximum_string
        if (current_score > maximum_score)
        {
            maximum_score = current_score;
            
            // Free the previous maximum_string if it's not NULL
            if (maximum_string != NULL)
            {
                free(maximum_string);
            }

            // Allocate memory for the new maximum_string and copy the token
            maximum_string = (char *)malloc(strlen(token) + 1);
            if (maximum_string == NULL) // Check for allocation failure
            {
                free(buffer);
                return NULL; // Handle allocation failure
            }
            strcpy(maximum_string, token);
        }

        token = strtok(NULL, " "); // Get the next token
    }

    free(buffer); // Free the buffer after processing all tokens
    return maximum_string; // Return the word with the maximum score
}

int main() {
    const char *sentence = "what time are we climbing up the volcano";
    char *result = highestScoringWord(sentence);
    if (result != NULL) {
        printf("Highest scoring word: %s\n", result);
        free(result); // Free the allocated memory for the result
    } else {
        printf("No word found\n");
    }
    return 0;
}
