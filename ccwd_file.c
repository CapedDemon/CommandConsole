#include <stdio.h>
#include <stdlib.h>
#include "change_dir_path.c" //including the change_dir_path.h to get the variable change_dir.
#include <dirent.h>
#include <unistd.h>

void ccwd()
{
    printf("Enter the path to change this directory to: \n");
    getchar();
    fgets(change_dir, 100, stdin);
    change_dir[strlen(change_dir) - 1] = 0;
    if (chdir(change_dir) == 0) //implementing chdir function.
    {
        printf("successfully changed\n");
    }
    else
    {
        printf("Cannot change the directory.\n");
    }
}