#include <stdio.h>
#include <stdlib.h>

//function to remove a file
void remo()
{
    char namr_file[30];
    printf("Enter the file name to delete: ");
    getchar();
    fgets(namr_file, 30, stdin);
    remove(namr_file);
}
