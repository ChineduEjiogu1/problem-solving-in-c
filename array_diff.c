#include <stdlib.h>
#include <stdio.h>

//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite

#include <stdlib.h>
#include <stdio.h>

// Return the parameter `z`
// `z` should be dynamically allocated inside the function

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, int *z) 
{
    size_t result_index = 0;
    z = (int *)malloc(n1 * sizeof(int)); // Dynamically allocate memory for `z`

    for (size_t i = 0; i < n1; i++) 
    {
        int found = 0;
      
        for (size_t j = 0; j < n2; j++) 
        {
            if (arr1[i] == arr2[j]) 
            {
                found = 1;
                break;
            }
        }
      
        if (!found) 
        {
            z[result_index++] = arr1[i]; // Add elements not found in arr2 to `z`
        }
    }

    // z = realloc(z, result_index * sizeof(int)); // Resize to fit exact number of elements
    return z; // Return the dynamically allocated array
}


int main() {
    int arr1[] = {1, 2, 2, 3};
    int arr2[] = {2};
    int *z = NULL;

    z = array_diff(arr1, 4, arr2, 1, z);

    printf("Result array: ");
    for (int i = 0; z[i] != '\0'; i++) { // Loop until the end of the array
        printf("%d ", z[i]);
    }

    printf("\n");

    free(z); // Free the allocated memory
    return 0;
}
