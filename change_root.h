#include <stdio.h>
#include <string.h>


//function to change the username and password
void change(){
    char username_new[10], password_new[10];
    int i =0;
    getchar();
    printf("Now you can change the username and password.\n");
    printf("Enter new username-");
    gets(username_new);//new username
    printf("Enter new password-");
    gets(password_new);//new password
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