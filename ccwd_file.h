#include <stdio.h>
#include <stdlib.h>
#include "change_dir_path.h"//including the change_dir_path.h to get the variable change_dir.
#include <dirent.h>
#include <unistd.h>

void ccwd()
{

    printf("Enter the path to change this directory to: \n");
    getchar();
    gets(change_dir);
    if (chdir(change_dir) == 0)//implementing chdir function.
    {
        printf("successfully changed\n");
    }
}
