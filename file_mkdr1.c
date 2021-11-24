#include <stdio.h>
#include "change_dir_path.c"
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#define SIZE 25

//function to make a folder.
void mkdr()
{
    int check;
    char *dirname;
    dirname = malloc(SIZE * sizeof(char));
    printf("Enter a name of the folder:");
    getchar();
    fgets(dirname, 25, stdin);
    dirname[strlen(dirname) - 1] = 0;
    check = mkdir(dirname);
    if (!check)
        printf("Directory created\n");

    else
    {
        printf("Unable to create directory\n");
    }
}