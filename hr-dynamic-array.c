#include <stdio.h>
#include <stdlib.h>

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int** arr = (int**)malloc(n * sizeof(int*));
    int* sizes = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        arr[i] = NULL;
    }
    
    int lastAnswer = 0;
    int resultCapacity = queries_rows;
    int* result = (int*)malloc(resultCapacity * sizeof(int));
    *result_count = 0;

    for (int i = 0; i < queries_rows; ++i) {
        int queryType = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int idx = (x ^ lastAnswer) % n;

        if (queryType == 1) {
            sizes[idx]++;
            arr[idx] = (int*)realloc(arr[idx], sizes[idx] * sizeof(int));
            arr[idx][sizes[idx] - 1] = y;
        } else if (queryType == 2) {
            int size = sizes[idx];
            lastAnswer = arr[idx][y % size];
            result[(*result_count)++] = lastAnswer;

            if (*result_count == resultCapacity) {
                resultCapacity *= 2;
                result = (int*)realloc(result, resultCapacity * sizeof(int));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);
    free(sizes);

    return result;
}

int main() {
    int n = 2;
    int queries_rows = 5;
    int queries_columns = 3;
    int* result_count = (int*)malloc(sizeof(int));

    int** queries = (int**)malloc(queries_rows * sizeof(int*));
    queries[0] = (int[]){1, 0, 5};
    queries[1] = (int[]){1, 1, 7};
    queries[2] = (int[]){1, 0, 3};
    queries[3] = (int[]){2, 1, 0};
    queries[4] = (int[]){2, 1, 1};

    int* result = dynamicArray(n, queries_rows, queries_columns, queries, result_count);

    printf("Result count: %d\n", *result_count);
    for (int i = 0; i < *result_count; ++i) {
        printf("%d\n", result[i]);
    }

    free(result);
    free(result_count);
    free(queries);

    return 0;
}
