#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#define SIZE 25

//function to remove a directory.
void rmdr()
{
    int check;
    char dirname[25];
    
    printf("Enter a name of the folder:");
    getchar();
    fgets(dirname, 25, stdin);
    dirname[strlen(dirname) - 1] = 0;
    check = rmdir(dirname);

    if (!check)
        printf("Directory deleted\n");

    else
    {
        printf("Unable to delete directory\n");
    }
}