#include <stdio.h>
#include <stdbool.h>

int updateResult(int *result, int element, int index)
{
    result[index] = element;
}

int findMinimumValue(int *arr, int arr_count)
{
    int minimumStickCutVal;
    for (int i = 0; i < arr_count; i++)
    {
        // if item is less than minimumStickVal and miniMumStickCut does not equal 0
        // assign item to minimumStickcutVal.
        if (arr[i] > 0)
            minimumStickCutVal = arr[i];
    }

    for (int i = 0; i < arr_count; i++)
    {
        // if item is less than minimumStickVal and miniMumStickCut does not equal 0
        // assign item to minimumStickcutVal.
        if (arr[i] < minimumStickCutVal && arr[i] != 0)
            minimumStickCutVal = arr[i];
    }

    return minimumStickCutVal;
}

bool isEndingCondition(int *arr, int arr_count)
{
    for (int i = 0; i < arr_count; i++)
    {
        if (arr[i] > 0)
            return false;
    }

    return true;
}

int *cutTheSticks(int arr_count, int *arr, int *result_count)
{
    int counterOfSize = 0;

    int resultSize = 0;
    
    while (!isEndingCondition(arr, arr_count))
    {
        int currentMinimumVal = findMinimumValue(arr, arr_count);
    
        counterOfSize = 0;

        // looping through the array called arr
        // printf("%d", currentMinimumVal);
        for (int i = 0; i < arr_count; i++)
        {
            // if the item does not equal zero and it is greater than the minimum value
            // subtract minimum value from the item
            if (arr[i] != 0 && arr[i] >= currentMinimumVal)
            {
                arr[i] = arr[i] - currentMinimumVal;
                counterOfSize++;
            }
            printf("%d ", arr[i]);
        }
        
        updateResult(result_count, counterOfSize, resultSize);
        resultSize++;
        
        

        printf("resultSize: " "%d\n", resultSize);
        printf("Size of array is: "
               "%d\n",
               counterOfSize);
        // isEndingCondition(arr, arr_count);
        // printf("The bool condition is %d ", isEndingCondition(arr, arr_count));
        // printf("minimunVal is:" " %d\n", currentMinimumVal);
        // printf("\n");
    }
    // for (int i = 0; i < arr_count; i++)
    // {
    //     if(result_count[i] != 0){
    //         printf("%d\n", result_count[i]);
    //     }else{
    //         return 0;
    //     }
    // }
    return result_count;
}

int main()
{
    // int size = 6;
    // int arr[6] = {5, 4, 4, 2, 2, 8};
    int size = 8;
    int arr[8] = {1, 2, 3, 4, 3, 3, 2, 1};
    int result_count;

    //int* arr = malloc(size * sizeof(int));

    int *result = cutTheSticks(size, arr, &result_count);
    // printf("%d\n", result);
    // printf("size of result: " "%ld\n", sizeof(result) / sizeof(result[0]));
    //printf("byte size of result: " "%ld\n",sizeof(result));

    for (int i = 0; i < size; i++)
    {
        printf("result item is: " "%d\n", result[i]);
    }
}