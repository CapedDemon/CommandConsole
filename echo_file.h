#include <stdio.h>
#include <string.h>

//Function to print the anything which user has given.
void echo()
{   
    getchar();
    char user_str[1000000];
    gets(user_str); 
    puts(user_str);
}