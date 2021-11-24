#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to remove a file
void remo()
{
    char name_file[30];
    printf("Enter the file name to delete: ");
    getchar();
    fgets(name_file, 30, stdin);
    name_file[strlen(name_file) - 1] = 0;
    int check = remove(name_file);
    if(!check){
        printf("Successfully deleted.\n");
    }
    else{
        printf("Cannot delete.\n");
    }
}
