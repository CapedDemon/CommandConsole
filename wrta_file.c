#include <stdio.h>
#include <stdlib.h>

//a function with which user can append into a file using the terminal.
void wrta()
{
    FILE *fp;
    FILE *fptr;
    char name_file[30];
    getchar();
    printf("Enter file name: ");
    fgets(name_file, 30, stdin);
    name_file[strlen(name_file) - 1] = 0;
    fp = fopen(name_file, "r");
    if (fp == NULL)
    {
        printf("cannot open the file.\n");
    }
    else
    {
        fptr = fopen(name_file, "a");
        char edits[300];
        printf("Write the text you want to append in your file. Start typing with a space..\n");
        fgetc(stdin);
        fgets(edits, 300, stdin);
        edits[strlen(edits) - 1] = 0;
        fprintf(fptr, edits);
        fclose(fptr);
    }
    fclose(fp);
}