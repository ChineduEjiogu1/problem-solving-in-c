#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t duplicate_count(const char *text) {
    char modifiable_text[100];
    size_t repeat_counter = 0;
    size_t length;

    // Copy input to a modifiable string
    strcpy(modifiable_text, text);

    // Convert all characters to lowercase for case insensitivity
    for (int i = 0; modifiable_text[i]; i++) {
        modifiable_text[i] = tolower(modifiable_text[i]);
    }

    length = strlen(modifiable_text);

    // Check for duplicates
    for (int i = 0; i < length; i++) {
        int duplicate_found = 0;

        // Skip already processed characters
        if (modifiable_text[i] == '0') {
            continue;
        }

        // Compare with the rest of the string
        for (int j = i + 1; j < length; j++) {
            if (modifiable_text[i] == modifiable_text[j]) {
                duplicate_found = 1;
                modifiable_text[j] = '0'; // Mark as processed
            }
        }

        // Increment repeat counter if duplicates were found
        if (duplicate_found) {
            repeat_counter++;
        }
    }

    return repeat_counter; // Return total count of repeated characters
}
