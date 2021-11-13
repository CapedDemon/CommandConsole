#include <stdio.h>
#include <stdlib.h>

//function to remove a file
void remo()
{
    char namr_file[30];
    printf("Enter the file name to delete: ");
    getchar();
    gets(namr_file);
    remove(namr_file);
}
