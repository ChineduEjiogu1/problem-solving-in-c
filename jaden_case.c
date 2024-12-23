#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *to_jaden_case(char * jaden_case, const char *string)
{

    int is_word = 1;

    int j = 0;

    int string_length = strlen(string);

    for (int i = 0; i < string_length; i++)
    {
        if (string[i] == ' ')
        {
            is_word = 1;
        }
        
        if (string[i] != ' ' && is_word == 1)
        {
            jaden_case[j++] = toupper(string[i]);
            is_word = 0; 

        } else {

            jaden_case[j++] = string[i];
        }
    } 

    jaden_case[j] = '\0';
    return jaden_case;
}




int main()
{
    const char *sentence = "Hello world how are you doing today";

    int string_length = strlen(sentence);

    char *jaden_case = (char *)malloc(string_length + 1);

    int result = *to_jaden_case(jaden_case, sentence);

    for (int i = 0; i < string_length; i++)
    {
        printf("%c", jaden_case[i]);
    }

}