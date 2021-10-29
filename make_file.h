#include <stdio.h>
#include <stdlib.h>

void make()
{
    FILE *fp;
    char name_file[30];
    getchar();
    printf("Enter file name with its extension:\n");
    fgets(name_file, 30, stdin);

    fp = fopen(name_file, "w");
    fclose(fp);
}
