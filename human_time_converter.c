#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *format_duration(int n)
{
    if (n == 0)
    {
        char *result = (char *)malloc(4); // For "now" + null terminator
        if (result)
            strcpy(result, "now");
        return result;
    }

    int years = 31536000;
    int days = 86400;
    int hours = 3600;
    int minutes = 60;

    int seconds_left = n;

    int years_count = seconds_left / years;
    seconds_left %= years;

    int days_count = seconds_left / days;
    seconds_left %= days;

    int hours_count = seconds_left / hours;
    seconds_left %= hours;

    int minutes_count = seconds_left / minutes;
    seconds_left %= minutes;

    int seconds_count = seconds_left;

    // Temporary buffer to store each unit
    char parts[5][50];
    int part_count = 0;

    // Append each time unit if it has a non-zero count
    if (years_count > 0)
        sprintf(parts[part_count++], "%d year%s", years_count, years_count > 1 ? "s" : "");
    if (days_count > 0)
        sprintf(parts[part_count++], "%d day%s", days_count, days_count > 1 ? "s" : "");
    if (hours_count > 0)
        sprintf(parts[part_count++], "%d hour%s", hours_count, hours_count > 1 ? "s" : "");
    if (minutes_count > 0)
        sprintf(parts[part_count++], "%d minute%s", minutes_count, minutes_count > 1 ? "s" : "");
    if (seconds_count > 0)
        sprintf(parts[part_count++], "%d second%s", seconds_count, seconds_count > 1 ? "s" : "");

    // Allocate memory for the final string
    char *result_string = (char *)malloc(256);

    if (!result_string)
        return NULL;
        
    result_string[0] = '\0';

    // Build the final result string
    for (int i = 0; i < part_count; i++)
    {
        if (i > 0 && i == part_count - 1)
        {
            strcat(result_string, " and ");
        }
        else if (i > 0)
        {
            strcat(result_string, ", ");
        }
        strcat(result_string, parts[i]);
    }

    return result_string;
}

// Test the function
int main()
{
    int test_cases[] = {0, 1, 62, 3662, 123343233, 89988, 3600};
    const char *expected[] = {
        "now",
        "1 second",
        "1 minute and 2 seconds",
        "1 hour, 1 minute and 2 seconds",
        "3 years, 332 days, 14 hours and 33 seconds",
        "1 day, 59 minutes and 48 seconds",
        "1 hour"};

    for (int i = 0; i < 7; i++)
    {
        char *result = format_duration(test_cases[i]);
        printf("Test %d:\n", i + 1);
        printf("Input seconds: %d\n", test_cases[i]);
        printf("Expected: %s\n", expected[i]);
        printf("Got:      %s\n", result ? result : "NULL");
        printf("Result: %s\n", result && strcmp(result, expected[i]) == 0 ? "PASS" : "FAIL");
        printf("\n");
        free(result); // Free allocated memory
    }

    return 0;
}
