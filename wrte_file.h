#include <stdio.h>
#include <stdlib.h>


//a function with which user can write into a file using terminal.
void wrte()
{
    FILE *fp;
    char name_file[30];
    getchar();
    printf("Enter file name: ");
    gets(name_file);
    fp = fopen(name_file, "w");

    char edits[300];
    printf("Write the text what you want to be there in your file..\n");
    getchar();
    gets(edits);
    fprintf(fp, edits);
    fclose(fp);
}