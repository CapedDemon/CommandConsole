#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//code to write the content of the file
void openf()
{
    //Intitialization
    FILE *ptr;
    char name_file[100];
    char content;

    //getting the name of the file
    printf("Enter the filename- ");
    fgets(name_file, 100, stdin);
    getchar();
    //opening  the file in tead mode
    ptr = fopen(name_file, "r");

    //If the file is null
    if (ptr == NULL)
    {
        printf("Cannot write the content of the file\n\n");
        exit(0);
    }

    //if it is not null
    else
    {
        content = fgetc(ptr);
        while (content != EOF)
        {
            printf("%c", content);
            content = fgetc(ptr);
        }

    }
    printf("\n");
    fclose(ptr);
}