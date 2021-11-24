#include <stdio.h>
#include <string.h>

void renameFile()
{
    getchar();
    char old_file[25];
    char new_file_name[25];
    int value;
    printf("Enter the name of the file(recent): ");
    fgets(old_file, 25, stdin);
    old_file[strlen(old_file) - 1] = 0;
    printf("Enter the new name of the file: ");
    fgets(new_file_name, 25, stdin);
    new_file_name[strlen(new_file_name) - 1] = 0;
    value = rename(old_file, new_file_name);

    if (!value)
    {
        printf("File name changed successfully\n");
    }
    else
    {
        printf("Error\n");
    }
}