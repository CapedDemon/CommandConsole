#include <stdio.h>
#include <string.h>

void renameFile()
{
    getchar();
    char old_file[25];
    char new_file_name[25];
    int value;
    printf("Enter the name of the file(recent): ");
    gets(old_file);
    getchar();
    printf("Enter the new name of the file: ");
    gets(new_file_name);
    value = rename(old_file, new_file_name);

    if (!value)
    {
        printf("File name changed successfully");
    }
    else
    {
        printf("Error");
    }
}