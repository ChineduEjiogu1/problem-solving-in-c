// seconds_left = total_seconds

// years = seconds_left / 31536000
// seconds_left %= 31536000

// days = seconds_left / 86400
// seconds_left %= 86400

// hours = seconds_left / 3600
// seconds_left %= 3600

// minutes = seconds_left / 60
// seconds_left %= 60

// seconds = seconds_left


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *formatDuration (int n) 
{
    int years = 31536000;
    int days =  86400;
    int hours = 3600;
    int minutes = 60;

    int seconds_left = n;

    char result_string = NULL;

    int years_count = seconds_left / years;
    seconds_left %= years;

    int days_count = seconds_left / days;
    seconds_left %= days;

    int hours_count = seconds_left / hours;
    seconds_left %= hours;

    int minutes_count = seconds_left / minutes;
    seconds_left %= minutes;

    int seconds_count = seconds_left;


    result_string = 

    return 0;
}

int main()
{
    int seconds = 0;

    printf("%s", "Please enter a number: ");
    scanf("%d", &seconds);

    char *result = formatDuration(seconds);

    printf("%s", result);
}