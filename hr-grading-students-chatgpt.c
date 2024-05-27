// chatgpt
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

// Function to process the grades
int *grading_students(int grades_count, int *grades, int *result_count) 
{
    int rounding_range_threshold = 3; // the limit for how far the rounding can be from the original grade.
    int grades_rounding_threshold = 38; // the minimum number for rounding a grade from the original number.
    int multiple = 5; // the multiple for rounding to the nearest multiple.

    int *rounded_grades = (int *)malloc(grades_count * sizeof(int)); // Allocate memory for the result array

    for (int i = 0; i < grades_count; i++) 
    {
        int original_grade = grades[i];
        int rounded_grade = round_to_nearest_multiple(original_grade, multiple);

        if (rounded_grade - original_grade < rounding_range_threshold && original_grade >= grades_rounding_threshold) 
        {
            rounded_grades[i] = rounded_grade;
        } 
        else 
        {
            rounded_grades[i] = original_grade;
        }
    }

    *result_count = grades_count; // Set the result count to the number of grades processed
    return rounded_grades; // Return the pointer to the rounded grades array
}

int main() 
{
    int grades[] = {73, 67, 38, 33};
    int grades_count = sizeof(grades) / sizeof(grades[0]);
    int result_count;

    int *rounded_grades = grading_students(grades_count, grades, &result_count);

    for (int i = 0; i < result_count; i++) 
    {
        printf("%d\n", rounded_grades[i]);
    }

    free(rounded_grades); // Free the allocated memory

    return 0;
}