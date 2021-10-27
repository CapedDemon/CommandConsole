#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "change_dir_path.h"


//function to print the current directory.
void pcwd()
{
    if (change_dir == NULL)
    {
        char *buf;
        buf = (char *)malloc(100 * sizeof(char));
        getcwd(buf, 100);
        printf("%s\n\n", buf);
    }
    else
    {
        if (getcwd(change_dir, sizeof(change_dir)) != NULL)
        {
            printf("%s\n", change_dir);
        }
    }
}