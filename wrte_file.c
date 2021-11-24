#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//a function with which user can write into a file using terminal.
void wrte()
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
            printf("Cannot open file\n");
      }
      else
      {
            fptr = fopen(name_file, "w");
            char edits[300];
            printf("Write the text what you want to be there in your file..\n");
            fgetc(stdin);
            fgets(edits, 300, stdin);
            edits[strlen(edits) - 1] = 0;
            fprintf(fptr, edits);
            fclose(fptr);
      }
      fclose(fp);
}