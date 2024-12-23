#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeat_string(const char* src, int count) {
    int len = strlen(src);
    int new_len = len * count;
    char* multiplied_string = (char*)malloc(new_len + 1); 

    if (multiplied_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < count; i++) { 
        for (int k = 0; k < len; k++) {
            multiplied_string[j++] = src[k]; 
        }
    }
    multiplied_string[j] = '\0'; 

    return multiplied_string;
}

int main() {
    const char* str = "hello";
    int repeat_count = 3;
    char* multiplied_str = repeat_string(str, repeat_count);
    printf("%s\n", multiplied_str);
    free(multiplied_str); 
    return 0;
}