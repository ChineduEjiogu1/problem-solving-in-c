#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int pickingNumbers(int a_count, int *a)
{
    int freq[101] = {0}; // Frequency array for counting occurrences

    // Count the frequency of each element
    for (int i = 0; i < a_count; i++)
    {
        freq[a[i]]++;  
        printf("The freq is: %d\n", freq[a[i]]);
    }
    
    

    // Calculate the maximum count of valid elements
    int maxCount = 0;
    // int i = 0;
    for (int i = 1; i <= 100; ++i)
    {
        maxCount = max(maxCount, freq[i] + freq[i - 1]);
        
    }
    return maxCount;
}

int main()
{
    int a[] = {3, 3, 1, 3, 2, 2};
    int a_count = sizeof(a) / sizeof(a[0]);

    int result = pickingNumbers(a_count, a);
    printf("Maximum count of valid elements: %d\n", result);

    return 0;
}
