// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// void remove_spaces(char *string)
// {
//     int i = 0, j = 0;
  
//     for (; string[i]; i++)
//     {
//         if (string[i] != ' ')
//         {
//             string[j++] = string[i];
//         }
//     }
  
//     string[j] = '\0';
// }

// char *camel_case(const char *s)
// {
//     int string_length = strlen(s);
//     char *copy_of_string = malloc(string_length + 1);
//     if (!copy_of_string) {
//         return NULL; // Memory allocation check
//     }
//     strcpy(copy_of_string, s);
  
//     int capitalize_next = 1;  // Flag to track whether the next character should be capitalized
    
//     for (int i = 0; copy_of_string[i] != '\0'; i++)
//     {
//         if (capitalize_next && isalpha(copy_of_string[i])) {
//             copy_of_string[i] = toupper(copy_of_string[i]);
//             capitalize_next = 0;  // Reset the flag after capitalizing
//         }
        
//         if (copy_of_string[i] == ' ') {
//             capitalize_next = 1;  // Set the flag to capitalize the next letter after a space
//         }
//     }

//     remove_spaces(copy_of_string);

//     return copy_of_string;
// }


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_spaces(char *string)
{
    int i = 0, j = 0;
  
    for (; string[i]; i++)
    {
        if (string[i] != ' ')
        {
          string[j++] = string[i];
        }
    }
  
  string[j] = '\0';
  
}

char *camel_case(const char *s)
{
  
  int string_length = strlen(s);
  char *copy_of_string = (char *)malloc(string_length + 1);
  strcpy(copy_of_string, s);
  
  for (int i = 0; copy_of_string[i] != '\0'; i++)
  {
    if (isalpha(copy_of_string[i])) {
    if (copy_of_string[i] == ' ')
    {
      copy_of_string[i + 1] = toupper(copy_of_string[i + 1]);
    }
     copy_of_string[0] = toupper(copy_of_string[0]);
    } else {
        return NULL;
    }
  }
  
  remove_spaces(copy_of_string);
  
  return copy_of_string;
  
}


int main() {
    const char *sentence = "TestCase";
    char *result = camel_case(sentence);
    if (result != NULL)
    {
        printf("The camel case string is: %s\n", result);
        free(result); 
    } else {
        printf("No word found\n");
    }
    return 0;
}