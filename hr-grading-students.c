#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

// Function to round the grade to the nearest multiple of `multiple`
int round_to_nearest_multiple(int grade, int multiple) 
{
    if (grade < multiple) {
        return grade;
    }
    int remainder = grade % multiple;
    if (remainder >= multiple / 2) {
        grade += (multiple - remainder);
    }
    return grade;
}

int *grading_students(int grades_count, int *grades, int *result_count) 
{
    int rounding_range_threshold = 3; // the limit for how far the rounding can be from the original grade.
    int grades_rounding_threshold = 38; // the minimum number for rounding a grade from the original number.
    int multiple = 5; // the multiple for rounding to the nearest muitple.

    for (int i = 0; i < grades_count; i++) 
    {
        int current_rounded_grade = round_to_nearest_multiple(grades[i], multiple);

        // if the rounded number is subtracted from the original number and it happens to be less than rounding_range_threshold
        // and grade happen to be greater than or equal to grades_rounding_threshold, round the original number to the nearest multiple
        // else return orignal number and the rounded numbers.

        if (current_rounded_grade - grades[i] < rounding_range_threshold && grades[i] >= grades_rounding_threshold) 
        {
            grades[i] = current_rounded_grade;
        }
    }

    *result_count = grades_count;

    return grades;
}

int main() 
{
    int grades[4] = {73, 67, 38, 33};

    int grades_count = sizeof(grades) / sizeof(grades[0]);

    int result_count;

    grading_students(grades_count, grades, &result_count);

    for (int i = 0; i < grades_count; i++) {
        printf("%d\n", grades[i]);
    }

    return 0;
}