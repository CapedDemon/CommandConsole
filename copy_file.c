#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fucntion to copy file
void copy()
{
    FILE *ptr1;
    FILE *ptr2;
    char filename1[25], filename2[25], content;

    getchar();
    printf("Enter the filename to be copied- ");
    fgets(filename1, 25, stdin);
    filename1[strlen(filename1) - 1] = 0;

    printf("Now enter the name of the file in which the contents of the %s to be copied - ", filename1);
    fgets(filename2, 25, stdin);
    filename2[strlen(filename2) - 1] = 0;

    ptr1 = fopen(filename1, "r");

    if (ptr1 == NULL)
    {
        printf("Cannot copy\n");
    }
    else
    {
        ptr2 = fopen(filename2, "w");

        content = fgetc(ptr1);

        while (content != EOF)
        {
            fputc(content, ptr2);
            content = fgetc(ptr1);
        }

        printf("\nSuccessfully copied to %s \n", filename1);
        fclose(ptr2);
    }

    fclose(ptr1);
}