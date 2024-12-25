#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the units and their corresponding seconds
typedef struct {
    const char *name;
    int seconds;
} Unit;

Unit units[] = {
    {"year", 60 * 60 * 24 * 365},
    {"day", 60 * 60 * 24},
    {"hour", 60 * 60},
    {"minute", 60},
    {"second", 1}
};

#define UNIT_COUNT (sizeof(units) / sizeof(units[0]))

char* format_duration(int seconds) {
    if (seconds == 0) {
        return strdup("now");
    }

    char *result = (char *)malloc(256 * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }
    result[0] = '\0'; // Initialize result as an empty string

    // Array to hold formatted units
    char formatted[UNIT_COUNT][50];
    int formatted_count = 0;

    // Process each unit
    for (int i = 0; i < UNIT_COUNT; i++) {
        int count = seconds / units[i].seconds;
        seconds %= units[i].seconds;

        if (count > 0) {
            sprintf(formatted[formatted_count], "%d %s%s", count, units[i].name, count > 1 ? "s" : "");
            formatted_count++;
        }
    }

    // Build the final string
    for (int i = 0; i < formatted_count; i++) {
        if (i > 0) {
            if (i == formatted_count - 1) {
                strcat(result, " and ");
            } else {
                strcat(result, ", ");
            }
        }
        strcat(result, formatted[i]);
    }

    return result;
}

// Test the function
int main() {
    // Test cases
    int test_cases[] = {0, 1, 62, 3662, 123343233, 89988, 3600};
    const char *expected[] = {
        "now",
        "1 second",
        "1 minute and 2 seconds",
        "1 hour, 1 minute and 2 seconds",
        "3 years, 332 days, 14 hours and 33 seconds",
        "1 day, 59 minutes and 48 seconds",
        "1 hour"
    };

    for (int i = 0; i < 7; i++) {
        char *result = format_duration(test_cases[i]);
        printf("Test %d:\n", i + 1);
        printf("Input seconds: %d\n", test_cases[i]);
        printf("Expected: %s\n", expected[i]);
        printf("Got:      %s\n", result);
        printf("Result: %s\n", strcmp(result, expected[i]) == 0 ? "PASS" : "FAIL");
        printf("\n");
        free(result);  // Free memory allocated for result
    }

    return 0;
}
