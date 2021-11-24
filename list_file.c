#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>


//function to list all the files in the current directory.
void list()
{
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        printf("Nothing in this directory\n\n");
    }

    struct dirent *entity;
    entity = readdir(dir);
    while (entity != NULL)
    {
        printf("%s\n", entity->d_name);
        entity = readdir(dir);
    }
    printf("\n\n");
    closedir(dir);
}