#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fucntion to copy file
void copy()
{
    FILE *ptr1;
    FILE *ptr2;
    char filename1[100], filename2[100], content;

    getchar();
    printf("Enter the filename to be copied- ");
    gets(filename1);
    printf("Now enter the name of the file in which the contents of the %s to be copied - ", filename1);
    gets(filename2);

    ptr1 = fopen(filename1, "r");
    ptr2 = fopen(filename2, "w");
    content = fgetc(ptr1);

    while (content != EOF)
    {
        fputc(content, ptr2);
        content = fgetc(ptr1);
    }

    printf("\nSuccessfully copied to %s \n", filename1);

    fclose(ptr1);
    fclose(ptr2);
}