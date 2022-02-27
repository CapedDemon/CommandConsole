/*Author: Shreejan Dolai
Language: C
*/
//header files(some are inbuilt and some header files I have created to organize different codes)
#include "MainCommands.h"
#include "Others/cricket.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "internet.h"
struct Node{
    char *data;
    struct Node *next;
};
struct Queue{
    int top;
    struct Node *rearNode;
    struct Node *frontNode;
};

void insertion(struct Queue *q, char data[]){
    if(q->top == 0){
        q->frontNode = (struct Node *)malloc(sizeof(struct Node));
        q->frontNode->data = data;
        q->frontNode->next = NULL;
        q->rearNode = q->frontNode;
        q->top = 1;
    }
    else{
        if(q->top == 1){
            q->rearNode = (struct Node *)malloc(sizeof(struct Node));
            q->rearNode->data = data;
            q->rearNode->next = NULL;
            q->frontNode->next = q->rearNode;
            q->top++;
        }
        else{
            struct Node *n = (struct Node *)malloc(sizeof(struct Node));
            q->rearNode->next = n;
            n->next = NULL;
            q->rearNode = n;
            q->rearNode->data= data;
            q->top++;
        }
        
    }
}

void traverse(struct Queue *a){
    struct Node *nomad = a->frontNode;
    if(a->top == 0){
        printf("No commands typed yet\n");
    }
    else{
        while (nomad!=NULL)
        {
            printf("%s\n", nomad->data);
            nomad = nomad->next;
        }
        
        
    }
}

void main_loop()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->top = 0;
    q->rearNode = NULL;
    

    //all the commands length are 5 characters so the command input will be taken from this variable.
    char cmd_str[4];

    int stop = 0; //intializing stop = 0 so as to stop the while loop when it is 1.
    clearScreen();
    printf("\nWELCOME ");
    char usernamePrint[10];
    FILE *user;
    user = fopen("etc/userdetails/user.txt", "r");
    char c1;
    int userCount = 0;
    c1 = fgetc(user);
    while(c1 != EOF){
        printf("%c", c1);
        usernamePrint[userCount] = c1;
        userCount++;
        c1 = fgetc(user);
    }
  
    usernamePrint[userCount] = '\0';
    printf("\n");
    while (stop != 1) //the condition to stop the while loop.
    {
        
        char *buf;                                //intializing a string to print the current or working directory.
        buf = (char *)malloc(100 * sizeof(char)); //I am using malloc as I don't know how much characters are there in the directory name.
        getcwd(buf, 100);                         //getcwd function is used here
        printf("(:-)%s(root): [%s] $: ", usernamePrint, buf);
        free(buf);
        //taking the command
        
        scanf("%s", cmd_str);

        if (strcmp(cmd_str, "quit") == 0)
        {
            
            printf("\nBYE BYE\n");
            stop = 1; //making stop = 1 to stop the while loop. And the terminal shut downs.
        }

        else if(strcmp(cmd_str, "hist") == 0)
        {

            traverse(q);

        }

        else if (strcmp(cmd_str, "cnge") == 0)
        {
            change();
            
            insertion(q, "cnge");
        }

        else if (strcmp(cmd_str, "help") == 0)
        {
            help();
            
            insertion(q, "help");
        }
        else if (strcmp(cmd_str, "list") == 0)
        {
            list();

            insertion(q, "list");
            
        }
        else if (strcmp(cmd_str, "date") == 0)
        {
            date();
            
            insertion(q, "date");
            
        }
        else if (strcmp(cmd_str, "calc") == 0)
        {
            calc();
            
            insertion(q, "calc");
            
        }
        else if (strcmp(cmd_str, "pcwd") == 0)
        {
            pcwd();
            
            insertion(q, "pcwd");
            
        }
        else if (strcmp(cmd_str, "make") == 0)
        {
            make();
            
            insertion(q, "make");
            
        }
        else if (strcmp(cmd_str, "wrte") == 0)
        {
            wrte();

            insertion(q, "wrte");
            
        }
        else if (strcmp(cmd_str, "wrta") == 0)
        {
            wrta();
            
            insertion(q, "wrta");
            
        }
        else if (strcmp(cmd_str, "remo") == 0)
        {
            remo();
            
            insertion(q, "remo");
            
        }
        else if (strcmp(cmd_str, "ccwd") == 0)
        {
            ccwd();
            
            insertion(q, "ccwd");
            
        }
        else if (strcmp(cmd_str, "mkdr") == 0)
        {
            mkdr();

            insertion(q, "mkdr");
            
        }
        else if (strcmp(cmd_str, "rmdr") == 0)
        {
            rmdr();
            
            insertion(q, "rmdr");
            
        }
        else if (strcmp(cmd_str, "info") == 0)
        {
            printf("Command Console is a fast, light-weight and secure shell.\nIt can run cross-platform - wndows, macOS and linux.\nType help to know about the commands.\nFor any query write us email - dolaishreejan@gmail.com\n");

            printf("\n\n\n\n\n\n");
        }
        else if (strcmp(cmd_str, "clr") == 0)
        {
            clearScreen();

            insertion(q, "clr");

        }
        else if (strcmp(cmd_str, "read") == 0)
        {
            read_file();
            insertion(q, "read");

        }
        else if(strcmp(cmd_str, "game") == 0)
        {
            game();
            insertion(q, "game");
        }
        else if (strcmp(cmd_str, "cfile") == 0)
        {
            copy_file();
            insertion(q, "cfile");

        }
        else if (strcmp(cmd_str, "sys") == 0)
        {
            int a = info_system();
            insertion(q, "sys");

        }
        else if (strcmp(cmd_str, "echo") == 0)
        {
            echo();
            insertion(q, "echo");

        }
        else if (strcmp(cmd_str, "root") == 0)
        {
            rootDisplay();
            insertion(q, "root");

        }
        else if (strcmp(cmd_str, "rfile") == 0)
        {
            renameFile();
            insertion(q, "rfile");

        }
        else if (strcmp(cmd_str, "rdr") == 0)
        {
            renameFolder();
            insertion(q, "rdr");

        }
        else if (strcmp(cmd_str, "getf") == 0)
        {
            getf();
            insertion(q, "getf");

        }
        else if(strcmp(cmd_str, "findf") == 0){
            findf();
            insertion(q, "findf"); 

        }
        else if (strcmp(cmd_str, "ipad") == 0)
        {
            ipad();
            insertion(q, "ipad");
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
    printf("Welcome to Command Console.\n\nTime:%s\n(Type help for manual or you can directly start interacting with terminal)\n\n", ctime(&t));

    //setting of username and password
    char username[10], password[10], ch;
    FILE *root_passwd;
    root_passwd = fopen("etc/userdetails/passwd.txt", "r");

    //first of all cjecking whether there is anything written in the password file.
    fseek(root_passwd, 0, SEEK_END);
    int size = ftell(root_passwd);

    if (size == 0) //if nothing is written
    {
        //opening the files with write mode
        FILE *wpasswd;
        FILE *w_user;
        w_user = fopen("etc/userdetails/passwd.txt", "w");
        wpasswd = fopen("etc/userdetails/user.txt", "w");

        //the length of the username should be less than 10 charcters and password less than 6 characters
        printf("Give two enters after wrting the username and password.. Length of username should not exceed 10 charcters and password\nshould be of 6 characters.\n\n");
        printf("YOU WILL BE ABLE TO TYPE YOUR PASSWORD AND USERNAME ONCE ONLY.\n\n");
        printf("Things to remeber:-\n");
        printf("i. Be accurate and do not make mistake\n");
        printf("ii. Do not share your passwords with others\n");
        printf("iii. With great power comes great responsibility\n\nGood Luck!!!");

        printf("USERNAME:- ");
        fgets(username, 10, stdin);
        username[strlen(username) - 1] = 0;

        printf("PASSWORD:- ");
        fgets(password, 10, stdin);
        password[strlen(password) - 1] = 0;

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
        fgets(password_existing, 10, stdin);
        password_existing[strlen(password_existing) - 1] = 0;

        FILE *ptr;
        ptr = fopen("etc/userdetails/passwd.txt", "r");
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
