#include <stdio.h>
#include <stdlib.h>

//a function with which user can append into a file using the terminal.
void wrta()
{
    FILE *fp;
    char name_file[30];
    getchar();
    printf("Enter file name: ");
    fgets(name_file, 30, stdin);
    fp = fopen(name_file, "a");
    char edits[300];
    printf("Write the text you want to append in your file. Start typing with a space..\n");
    getchar();
    fgets(edits, 300, stdin);
    fprintf(fp, edits);
    fclose(fp);
}