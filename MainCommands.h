#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>

#define SIZE 260
#define BUFFER_SIZE 4096

char change_dir[100];

// Function to chnage the cuurent directory
void ccwd()
{
    printf("\033[0;35m");
    printf("Enter the path to change this directory to: \n");
    getchar();
    fgets(change_dir, 100, stdin);
    change_dir[strlen(change_dir) - 1] = 0;
    if (chdir(change_dir) == 0) //implementing chdir function.
    {
        printf("successfully changed\n");
    }
    else
    {
        printf("Cannot change the directory.\n");
    }
}

// Function to calculate
void calc()
{
    printf("\033[0;34m");
    char type;
    printf("Enter d for decimal operations and i for integer operation: ");
    scanf("%c", &type);
    if (type == 'i')
    {
        getchar();
        int a, b;
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        char o;
        printf("Enter operation(+, -, /, *): ");
        getchar();
        scanf("%c", &o);
        if (o == '+')
        {
            printf("%d\n\n", a + b);
        }
        else if (o == '-')
        {
            printf("%d\n\n", a - b);
        }
        else if (o == '*')
        {
            printf("%d\n\n", a * b);
        }
        else if (o == '/')
        {
            printf("%d\n\n", a / b);
        }
    }
    else
    {
        getchar();
        float x, y;
        printf("Enter first number: ");
        scanf("%f", &x);
        printf("Enter second number: ");
        scanf("%f", &y);
        char o;
        printf("Enter operation(+, -, /, *): ");
        getchar();
        scanf("%c", &o);
        if (o == '+')
        {
            printf("%.2f\n\n", x + y);
        }
        else if (o == '-')
        {
            printf("%.2f\n\n", x - y);
        }
        else if (o == '*')
        {
            printf("%.2f\n\n", x * y);
        }
        else if (o == '/')
        {
            printf("%.2f\n\n", x / y);
        }
    }
}

//Function to change root credentials - username and password
void change()
{
    printf("\033[0;32m");
    printf("YOU WILL BE ABLE TO TYPE YOUR PASSWORD AND USERNAME ONCE ONLY.\n\n");
    printf("Things to remeber:-\n");
    printf("i. Be accurate and do not make mistake\n");
    printf("ii. Do not share your passwords with others\n");
    printf("iii. With great power comes great responsibility\n\nGood Luck!!!");
    char username_new[10], password_new[10];
    int i = 0;
    getchar();
    printf("Now you can change the username and password.\n");
    printf("Enter new username-");
    fgets(username_new, 10, stdin); //new username
    username_new[strlen(username_new) - 1] = 0;

    printf("Enter new password-");
    fgets(password_new, 10, stdin); //new password
    password_new[strlen(password_new) - 1] = 0;

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

// Function to clear the screen
void clearScreen()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

// Fucntion to copy file
void copy_file()
{
    printf("\033[0;33m");
    FILE *ptr1;
    FILE *ptr2;
    char filename1[SIZE], filename2[SIZE], content;

    getchar();
    printf("Enter the filename to be copied- ");
    fgets(filename1, SIZE, stdin);
    filename1[strlen(filename1) - 1] = 0;

    printf("Now enter the name of the file in which the contents of the %s to be copied - ", filename1);
    fgets(filename2, SIZE, stdin);
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

//date function. If the user clears the screen it can be usefule to see the date.
void date()
{
    printf("\033[0;37m");
    time_t t;
    time(&t);
    printf("%s\n\n", ctime(&t));
}

//Function to print the anything which user has given.
void echo()
{
    printf("\033[0;34m");
    fgetc(stdin);
    char user_str[1000000];
    fgets(user_str, 1000000, stdin);
    printf("\033[0;31m");
    printf("%s", user_str);
}

//function to make a folder.
void mkdr()
{
    printf("\033[0;35m");
    int check;
    char dirname[SIZE];
    printf("Enter a name of the folder:");
    getchar();
    fgets(dirname, SIZE, stdin);
    dirname[strlen(dirname) - 1] = 0;
    check = mkdir(dirname);
    if (!check)
        printf("Directory created\n");

    else
    {
        printf("Unable to create directory\n");
    }
}

//function to print the help menu.
void help()
{
    printf("\033[0;32m");
    printf("\tIn all the cases first write the command hit enter and then give the arguements\n\n");

    printf(">>calc - This command open a terminal calculator and you can do simple calculator operation in this.\n\tThe operaation are - (+, -, * , /, ^(Power of. Ex- 3^2 = 9)\n\tFirst number (operation) Second Number\n\tFor doing operation in decimal give d and for integer give i\n\n\n");
    printf(">>date - This command prints the current date and time\n\n");
    printf(">>make - This command will make a file for you and you need to give command which type of extension do you want.\n\n");
    printf(">>remo - This command will remove a file\n\n");
    printf(">>list - This will print the files and folders in your directory\n\n");
    printf(">>wrte - This will write in the file you will give. Start writing the text with a space.\n\n");
    printf(">>wrta - This will append in your file. Start writing the text with a space and tehn write all the things which you want.\nFor example - Suppose there is hello initially written. So you want write hi with a space between hello and hi,\n so you should give two spaces before writing in the terminal\n\n");
    printf(">>quit - write quit and hit enter to exit the terminal\n\n");
    printf(">>pcwd - Print Current Working Directory\n\n");
    printf(">>ccwd - Change Current Working Directory\n\n");
    printf(">>mkdr - This will make a folder in the current directory\n\n");
    printf(">>rmdr - This will remove a folder in the current directory\n\n");
    printf(">>info - This will show you the details of the STerminal\n\n");
    printf(">>clr - This will clear the screen of the terminal\n\n");
    printf(">>read - This will print the content of the file.\n\n");
    printf(">>cnge - This will change your username and password\n\n");
    printf(">>cfile - This will copy the contents of one file to another file.\n\n");
    printf(">>sys - This will print the information of your OS.\n\n");
    printf(">>echo - This will print anything which you have given. After writing echo press enter then write whatever you want and press enter.\n\n");
    printf(">>root - This will print the username and password\n\n");
    printf(">>rfile - This will rename the file with the name you want.\n\n");
    printf(">>rdr - This will rename the folder with the name you want.\n\n");
    printf(">>getf - This will confirm you that the fille or folder name you have given is present in the directory that you specified.\n\n");
    printf(">>findf - This will find the specified word in a given file and print the line where it is located.\n\n");
}

//function to list all the files in the current directory.
void list()
{
    printf("\033[0;32m");
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        printf("Nothing in this directory\n\n");
    }

    struct dirent *entity;
    entity = readdir(dir);
    while (entity != NULL)
    {
        printf("%s\n", entity->d_name);
        entity = readdir(dir);
    }
    printf("\n\n");
    closedir(dir);
}

// Function to make a file
void make()
{
    printf("\033[0;33m");

    FILE *fp;
    char name_file[SIZE];
    getchar();
    printf("Enter file name with its extension:\n");
    fgets(name_file, SIZE, stdin);
    name_file[strlen(name_file) - 1] = 0;

    fp = fopen(name_file, "w");
    fclose(fp);
}

// Function to read the contents of a file
void read_file()
{
    printf("\033[0;37m");

    getchar();
    FILE *fptr;

    char filename[SIZE], c;

    printf("Enter the filename to open \n");
    fgets(filename, SIZE, stdin);
    filename[strlen(filename) - 1] = 0;

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
    }
    else
    {
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

//function to remove a file
void remo()
{
    printf("\033[0;33m");

    char name_file[SIZE];
    getchar();
    printf("Enter the file name to delete: ");

    fgets(name_file, SIZE, stdin);
    name_file[strlen(name_file) - 1] = 0;
    int check = remove(name_file);
    if (!check)
    {
        printf("Successfully deleted.\n");
    }
    else
    {
        printf("Cannot delete.\n");
    }
}

// Function to rename file
void renameFile()
{
    printf("\033[0;32m");

    getchar();
    char old_file[SIZE];
    char new_file_name[SIZE];
    int value;
    printf("Enter the name of the file(recent): ");
    fgets(old_file, SIZE, stdin);
    old_file[strlen(old_file) - 1] = 0;
    printf("Enter the new name of the file: ");
    fgets(new_file_name, SIZE, stdin);
    new_file_name[strlen(new_file_name) - 1] = 0;
    value = rename(old_file, new_file_name);

    if (!value)
    {
        printf("File name changed successfully\n");
    }
    else
    {
        printf("Error\n");
    }
}

//function to remove a directory.
void rmdr()
{
    printf("\033[0;31m");

    int check;
    char dirname[SIZE];

    printf("Enter a name of the folder:");
    getchar();
    fgets(dirname, SIZE, stdin);
    dirname[strlen(dirname) - 1] = 0;
    check = rmdir(dirname);

    if (!check)
        printf("Directory deleted\n");

    else
    {
        printf("Unable to delete directory\n");
    }
}

// Function to print system information
int info_system()
{
    printf("\033[0;32m");

#ifdef __linux__
    int r = system("cat /etc/os-release");
    return 1;
#elif __unix__
    int r = system("cat /etc/os-release");
    return 1;
#elif __APPLE__
    int r = system("cat /etc/os-release");
    return 1;
#elif __WIN32 || __WIN64
    int r = system("systeminfo");
    return 1;
#endif
    return 0;
}

// Function to print the username and password
void rootDisplay()
{
    printf("\033[0;32m");

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

//a function with which user can append into a file using the terminal.
void wrta()
{
    printf("\033[0;35m");

    FILE *fp;
    FILE *fptr;
    char name_file[SIZE];
    getchar();
    printf("Enter file name: ");
    fgets(name_file, 30, stdin);
    name_file[strlen(name_file) - 1] = 0;
    fp = fopen(name_file, "r");
    if (fp == NULL)
    {
        printf("cannot open the file.\n");
    }
    else
    {
        fptr = fopen(name_file, "a");
        char edits[300];
        printf("Write the text you want to append in your file. Start typing with a space..\n");
        fgetc(stdin);
        fgets(edits, 300, stdin);
        edits[strlen(edits) - 1] = 0;
        fprintf(fptr, edits);
        fclose(fptr);
    }
    fclose(fp);
}

//a function with which user can write into a file using terminal.
void wrte()
{
    printf("\033[0;35m");

    FILE *fp;
    FILE *fptr;
    char name_file[SIZE];
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
}

// Function to print current directory
void pcwd()
{
    printf("\033[0;33m");

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

    char current_working_dir[FILENAME_MAX];
    if (GetCurrentDir(current_working_dir, FILENAME_MAX) == NULL)
    {
        printf("Error\n");
    }
    else
    {
        printf("%s\n", current_working_dir);
    }
}

// Function to rename folder
void renameFolder()
{
    printf("\033[0;32m");

    getchar();
    char firstname[SIZE], lastname[SIZE];
    printf("Enter the current name of the folder: ");
    fgets(firstname, SIZE, stdin);
    firstname[strlen(firstname) - 1] = 0;
    printf("Enter the new name of the folder: ");
    fgets(lastname, SIZE, stdin);
    lastname[strlen(lastname) - 1] = 0;

    int value = rename(firstname, lastname);
    if (!value)
    {
        printf("Successfully changed\n");
    }
    else
    {
        printf("Cannot change\n");
    }
}

// Function to find a file or folder in a folder
void getf()
{
    printf("\033[0;34m");

    getchar();
    char foldername[SIZE];
    printf("Enter the name of the folder or directory first: ");
    fgets(foldername, SIZE, stdin);
    foldername[strlen(foldername) - 1] = 0;
    DIR *dp;
    struct dirent *dirp;

    if ((dp = opendir(foldername)) == NULL)
    {
        printf("can't find %s\n", foldername);
    }
    else
    {
        printf("Enter the filename or foldername to find: ");
        char reciepent[SIZE];
        fgets(reciepent, SIZE, stdin);
        reciepent[strlen(reciepent) - 1] = 0;
        while ((dirp = readdir(dp)) != NULL)
        {
            if (!strcmp(dirp->d_name, reciepent))
                printf("%s is presnt in the folder %s\n", dirp->d_name, foldername);
        }
    }
    closedir(dp);
}

// Function to find the location of a word in a file
void findf()
{
    printf("\033[0;32m");

    getchar();
    char word[SIZE];
    FILE *fptr;

    int i = 0, line = 1;
    int confirm;
    int linearray[1000];

    char filename[SIZE];
    printf("Enter filename: ");
    fgets(filename, SIZE, stdin);
    filename[strlen(filename) - 1] = 0;

    char str[BUFFER_SIZE];

    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file.\n");
    }
    else
    {
        printf("Enter the word to find: ");
        fgets(word, SIZE, stdin);
        word[strlen(word) - 1] = 0;
        printf("The word is find in line number:- \n");
        while (fgets(str, BUFFER_SIZE, fptr) != NULL)
        {
            if (strstr(str, word))
            {
                linearray[i] = line;
                confirm = 1;
                printf("%d\n", linearray[i]);
            }
            else
            {
                if (confirm != 1)
                {
                    confirm = 0;
                }
            }
            i++;
            line++;
        }
        if (confirm == 0)
        {
            printf("Actually! eh word is not present.\n");
        }
    }
    fclose(fptr);
}