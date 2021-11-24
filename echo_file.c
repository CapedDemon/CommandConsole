#include <stdio.h>
#include <string.h>

//Function to print the anything which user has given.
void echo()
{   
    fgetc(stdin);
    char user_str[1000000];
    fgets(user_str, 1000000, stdin);
    printf("%s", user_str);
}