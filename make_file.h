#include <stdio.h>
#include <stdlib.h>

void make()
{
    FILE *fp;
    char name_file[30];
    getchar();
    printf("Enter file name with its extension:\n");
    gets(name_file);

    fp = fopen(name_file, "w");
    fclose(fp);
}
