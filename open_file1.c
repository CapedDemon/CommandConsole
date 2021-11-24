#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(){
    getchar();
    FILE *fptr;

    char filename[25], c;

    printf("Enter the filename to open \n");
    fgets(filename, 25, stdin);
    filename[strlen(filename) - 1] = 0;

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        
    }
    else{
        // Read contents from file
        c = fgetc(fptr);
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(fptr);
        }

        fclose(fptr);
        printf("\n");
    }
    
}