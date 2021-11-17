#include <stdio.h>
#include <string.h>
#include <conio.h>

#define ENTER 13
#define space 32
#define tab 9
#define bksp 8

//function to change the username and password
void change(){
    char username_new[10], password_new[10];
    int i =0;
    getchar();
    printf("Now you can change the username and password.\n");
    printf("Enter new username-");
    gets(username_new);//new username
    printf("Enter new password-");
    //new password
    while (1)
    {
        password_new[i] = getch();
        if (password_new[i] == ENTER)
        {
            password_new[i] = '\0';
            break;
        }
        else if (password_new[i] == bksp)
        {
            if (i>0){
                i--;
                printf("\b \b");
            }
            
        }
        else if (password_new[i] == tab || password_new[i] == space)
        {
            continue;
        }
        else if (password_new[i] != 13)
        {
            printf("*");
            i++;
        }
        
    }
    getchar();

    FILE *new_user;
    FILE *new_password;
    //writing in the files the new username and password
    new_user = fopen("root_username.txt", "w");
    new_password = fopen("password_root.txt", "w");
    fprintf(new_user, username_new);
    fprintf(new_password, password_new);
    fclose(new_user);
    fclose(new_password);
}