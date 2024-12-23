//  do not allocate memory for the result
//  write to pre-allocated pointer *camel

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void to_camel_case(const char *text, char *camel) 
{
//     //  <----  hajime!
    int string_length = strlen(text);
    char *copy_of_string = (char *)malloc(string_length + 1 * sizeof(char));  
    strcpy(copy_of_string, text);
  
    char *token = NULL;
    const char *delimiters = "-_"; 
    token = strtok(copy_of_string, delimiters);
    
    int j = 0;
  
    int is_first_word = 1;
  
    while (token != NULL)
    { 
        if (is_first_word)
        {

          camel[j++] = token[0]; 
          is_first_word = 0;

        } else {
          
          camel[j++] = toupper(token[0]); 
        }
      
        for (int i = 1; token[i] != '\0'; i++)
        {    
            camel[j++] = tolower(token[i]);
        }
       
      token = strtok(NULL, delimiters);
    }  
  
    free(copy_of_string);
  
    camel[j] = '\0';  // Null-terminate the string
}

// The function definition goes here.

int main() 
{
    const char *input = "the-quick_brown-fox";
    char camel_case_output[100]; // Allocate sufficient space for the output.

    to_camel_case(input, camel_case_output);

    printf("Original: %s\n", input);
    printf("CamelCase: %s\n", camel_case_output);

    return 0;
}
