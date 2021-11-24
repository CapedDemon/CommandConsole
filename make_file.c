#include <stdio.h>
#include <stdlib.h>

void make()
{
    FILE *fp;
    char name_file[25];
    getchar();
    printf("Enter file name with its extension:\n");
    fgets(name_file, 25, stdin);
    name_file[strlen(name_file) - 1] = 0;
    
    fp = fopen(name_file, "w");
    fclose(fp);
}
