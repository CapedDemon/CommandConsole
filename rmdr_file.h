#include "change_dir_path.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#define SIZE 25

//function to remove a directory.
void rmdr()
{
    int check;
    char dirname[25];
    
    printf("Enter a name of the folder:");
    getchar();
    gets(dirname);
    check = rmdir(dirname);

    if (!check)
        printf("Directory deleted\n");

    else
    {
        printf("Unable to delete directory\n");
    }
}