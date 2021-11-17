/*Author: Shreejan Dolai
Language: C
*/

//header files(some are inbuilt and some header files I have created to organize different codes)
#include "echo_file.h"
#include "system_info.h"
#include "copy_file.h"
#include "change_root.h"
#include "change_dir_path.h"
#include "help_file.h"
#include "open_file1.h"
#include "file_mkdr1.h"
#include "rmdr_file.h"
#include "make_file.h"
#include "wrta_file.h"
#include "wrte_file.h"
#include "list_file.h"
#include "calc_file.h"
#include "pcwd_file.h"
#include "clr_file.h"
#include "ccwd_file.h"
#include "remo_file.h"
#include "date_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//define variables
#define SIZE 25

void main_loop()
{
    //all the commands length are 5 characters so the command input will be taken from this variable.
    char cmd_str[5];

    int stop = 0; //intializing stop = 0 so as to stop the while loop when it is 1.

    while (stop != 1) //the condition to stop the while loop.
    {
        char *buf;                                //intializing a string to print the current or working directory.
        buf = (char *)malloc(100 * sizeof(char)); //I am using malloc as I don't know how much characters are there in the directory name.
        getcwd(buf, 100);                         //getcwd function is used here
        printf("[%s] $: ", buf);

        //taking the command
        scanf("%s", cmd_str);

        if (strcmp(cmd_str, "quit") == 0)
        {
            stop = 1; //making stop = 1 to stop the while loop. And the terminal shut downs.
        }

        else if (strcmp(cmd_str, "cnge") == 0)
        {
            change(); //calling the change function in the change_root.h
        }

        else if (strcmp(cmd_str, "help") == 0)
        {
            help(); //calling the help function in the help_file.h
        }
        else if (strcmp(cmd_str, "list") == 0)
        {
            list(); //calling the list function in the list_file.h
        }
        else if (strcmp(cmd_str, "date") == 0)
        {
            date(); //calling the date function in the date_file.h
        }
        else if (strcmp(cmd_str, "calc") == 0)
        {
            calc(); //calling the calc function in the calc_file.h
        }
        else if (strcmp(cmd_str, "pcwd") == 0)
        {
            pcwd(); //calling the pcwd function in the pcwd_file.h
        }
        else if (strcmp(cmd_str, "make") == 0)
        {
            make(); //calling the make function in the make_file.h
        }
        else if (strcmp(cmd_str, "wrte") == 0)
        {
            wrte(); //calling the wrte function in the wrte_file.h
        }
        else if (strcmp(cmd_str, "wrta") == 0)
        {
            wrta(); //calling the wrta function in the wrta_file.h
        }
        else if (strcmp(cmd_str, "remo") == 0)
        {
            remo(); //calling the remo function in the remo_file.h
        }
        else if (strcmp(cmd_str, "ccwd") == 0)
        {
            ccwd(); //calling the ccwd function in the ccwd_file.h
        }
        else if (strcmp(cmd_str, "mkdr") == 0)
        {
            mkdr(); //calling the mkdr function in the file_mkdr1.h
        }
        else if (strcmp(cmd_str, "rmdr") == 0)
        {
            rmdr(); //calling the rmdr function in the rmdr_file.h
        }
        else if (strcmp(cmd_str, "info") == 0)
        {
            //You can give your name here. And email address.
            printf("Developer: Shreejan Dolai\nLanguage: C\nEmail Id: dolaishreejan@gmail.com\n(c)All rights reserved.\n\n");

            printf("\n\n\n\n\n\n");
        }
        else if (strcmp(cmd_str, "clr") == 0)
        {
            clearScreen(); //calling the clearScreen function in the clr_file.h
        }
        else if (strcmp(cmd_str, "read") == 0)
        {
            read_file(); //calling the open function in the open_file.h
        }
        else if(strcmp(cmd_str, "copy") == 0){
            copy(); //calling the copy  fucntion in the copy_file.h
        }
        else if(strcmp(cmd_str, "sys") == 0){
            int a = info_system(); //calling the copy  fucntion in the system_info.h
        }
        else if(strcmp(cmd_str, "echo") == 0){
            echo(); //calling the echo function in the echo_file.h
        }
        else
        {
            printf("Error: Wrong Command\n\tRun command which is there. Type help for information\n");
        }
    }
}

//main program
int main()
{
    //intialization to check the time
    time_t t;
    time(&t);

    //welcome statement with time
    printf("Welcome to C terminal.\n\nTime:%s\n(Type help for manual or you can directly start interacting with terminal)\n\n", ctime(&t));

    //setting of username and password
    char username[10], password[10];
    FILE *root_passwd;
    root_passwd = fopen("password_root.txt", "r");

    //first of all cjecking whether there is anything written in the password file.
    fseek(root_passwd, 0, SEEK_END);
    int size = ftell(root_passwd);

    if (size == 0) //if nothing is written
    {
        //opening the files with write mode
        FILE *wpasswd;
        FILE *w_user;
        w_user = fopen("root_username.txt", "w");
        wpasswd = fopen("password_root.txt", "w");

        //the length of the username should be less than 10 charcters and password less than 6 characters
        printf("Give two enters after wrting the username and password.. Length of username should not exceed 10 charcters and password\nshould be of 6 characters.\n");

        printf("USERNAME:- ");
        gets(username);
        getchar();
        printf("PASSWORD:- ");
        gets(password);
        getchar();
        
        fprintf(w_user, username);
        fprintf(wpasswd, password);
        fclose(w_user);
        fclose(wpasswd);

        main_loop();
    }
    else //or it will ask the password
    {
        //This only tkes the password and opens the file having the real passwords nd compres it.
        char password_existing[10], c1, c2;

        printf("Enter the password- ");
        gets(password_existing);
        getchar();

        FILE *ptr;
        ptr = fopen("password_root.txt", "r");
        c1 = fgetc(ptr);
        int i = 0, i2 = 0, decision = 0, decision2 = 0;
        while (c1 != EOF)
        {
            if (password_existing[i] == c1)
            {
                decision = 1;
            }
            else
            {
                decision = 0;
                break;
            }
            i++;
            c1 = fgetc(ptr);
        }
        if (decision == 1)
        {
            main_loop();
        }
        else
        {
            printf("Access denied\n");
        }
        fclose(ptr);
    }

    fclose(root_passwd);

    return 0;
}