#include <stdio.h>
#include <stdlib.h>

void rootDisplay(){
    FILE *ptr1;
    FILE *ptr2;
    char c1, c2;
    ptr1 = fopen("root_username.txt", "r");
    ptr2 = fopen("password_root.txt", "r");
    c1 = fgetc(ptr1);
    printf("Username:- ");
    while (c1 != EOF)
    {
        printf("%c", c1);
        c1 = fgetc(ptr1);
    }

    c2 = fgetc(ptr2);
    printf("\nPassword:- ");
    while (c2 != EOF)
    {
        printf("%c", c2);
        c2 = fgetc(ptr2);
    }
    printf("\n");
}