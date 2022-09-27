#include <iostream>
#include <unistd.h>
#include <ios>
#include <fstream>
#include <dirent.h>
#include <ctime>
#pragma once

using namespace std;
int SIZE = 260;
int BUFFER_SIZE = 4096;

    class MainCommands
{
private:
    bool access;

public:
    MainCommands(bool access)
    {
        MainCommands::access = access;
    }
    string filename;
    char dirname[260];
    void rootChange();
    void help();
    char *pcd();
    void list();
    void ccwd();
    void clearScreen();
    void date();
    void make();
    void wrte();
    void wrta();
    void remo();
    void mkdr();
    void rmdr();
    void info();
    void read();
    void copyfile();
    int info_system();
    void echo();
    void rootDisplay();
    void renameFile();
    void renameDir();
    void getf();
    void findf();
    void calc();
};

void MainCommands::rootChange()
{
    string username, password, expassword, expasspath = "root/userdetails/passwd.txt";
    ifstream exPass(expasspath);

    getline(exPass, expassword);

    cout << "You are going to change your root details.\nEnter your existing password - ";
    getline(cin, password);

    if (password == expassword)
    {
        string decision;
        cout << "What do you want to change  - username(u) / password(p) / both(b) ?\n";
        getline(cin, decision);

        if (decision == "u")
        {
            string userpath = "root/userdetails/user.txt", newUsername;
            ofstream userFile(userpath);
            userFile.clear();

            cout << "Type your new usernmae - ";
            getline(cin, newUsername);

            userFile << newUsername;
            userFile.close();
        }

        else if (decision == "p")
        {
            string passpath = "root/userdetails/passwd.txt", newPasswd;
            ofstream passFile(passpath);
            passFile.clear();

            cout << "Type your new password - ";
            getline(cin, newPasswd);

            passFile << newPasswd;
            passFile.close();
        }

        else if (decision == "b")
        {
            string passpath = "root/userdetails/passwd.txt", newPasswd, userpath = "root/userdetails/user.txt", newUsername;
            ofstream passFile(passpath);
            passFile.clear();
            ofstream userFile(userpath);
            userFile.clear();

            cout << "Type your new usernmae - ";
            getline(cin, newUsername);
            cout << "Type your new password - ";
            getline(cin, newPasswd);

            userFile << newUsername;
            passFile << newPasswd;
            userFile.close();
            passFile.close();
        }

        else
            cout << "Try again next time\n";
    }
    else
    {
        cout << "OOPS ! Password didn't match try again.\n";
    }
    exPass.close();
}

void MainCommands::help()
{
    printf("For extra information read the README.md file\n");
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
    printf(">>hist - This will print all the commands which you have written\n\n");
    printf(">>game - This will start a cricket game.\n\n");
    printf(">>ipad - This will show the IPv4 address.\n\n");
}

char *MainCommands::pcd()
{
    char *tmp = new char[256];
    getcwd(tmp, 256);
    return tmp;
}

void MainCommands::list()
{
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

void MainCommands::ccwd()
{
    char nwd[256];
    cout << "Give the path of the new directory - ";
    cin.sync();
    cin.getline(nwd, 256);

    if (chdir(nwd) == 0)
        printf("successfully changed\n");
    else
        printf("cannot change directory\n");
}

void MainCommands::clearScreen()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}


void MainCommands::date () 
{
    // variable to get the time
    //  this is going to print
    // the date only🙃
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Format - DD.MM.YYYY"<<endl<<ltm->tm_mday << "." << ltm->tm_mon << "." << 1900+ltm->tm_year << endl;
}

void MainCommands::make() 
{
    fstream file;
    cout << "Enter a new filename with its file extension - ";
    getline(cin, filename);

    file.open(filename, ios::out);

    if (!file)
        cout << "error\n";
    else
        cout << "File created\n";
    file.close();
}

void MainCommands::wrte()
{
    string text;
    cout << "Enter the filename or file path to write in it - ";
    getline(cin, filename);
    ofstream writeFile(filename);

    cout << "Enter the text which is to be written in the file - " << endl;
    getline(cin, text);
    writeFile<<text;
    writeFile.close();
}

void MainCommands::wrta()
{
    string text;
    cout << "Enter the filename or file path to append something in it - ";
    getline(cin, filename);
    ofstream appendFile;
    appendFile.open(filename, ios_base::app);

    cout << "Enter the text to append in the file - " << endl;
    getline(cin, text);
    appendFile << text << endl;
    appendFile.close();
}

void MainCommands::remo()
{
    char fremove[20];
    cout << "Enter the filename or file path to remove - ";
    cin.sync();
    cin.getline(fremove, 20);
    if(remove(fremove) == 0)
    {
        cout << "Successfully deleted" << endl;
    }
    else
        cout << "Cannot delete" << endl;
}

void MainCommands::mkdr()
{
    cout << "Enter the name of the folder or a new path - ";
    getcwd(dirname, SIZE);
    if (mkdir(dirname) == -1)
    {
        cout << "Cannot create directory\n";
    }
    else
        cout << "Directory created\n";
       
}

void MainCommands::rmdr()
{
    cout << "Enter the name of the folder or a path to delete - ";
    cin.sync();
    cin.getline(dirname, SIZE);
    if (rmdir(dirname) == 1)
        cout << "Directory deleted\n";
    else
        cout << "Cannot delete directory\n";
}

void MainCommands::info()
{
    cout << "Command Console is a fast, light-weight and secure shell.\nIt can run cross-platform - wndows, macOS and linux.\nType help to know about the commands.\nFor any query write us email - dolaishreejan@gmail.com\n\n";
}

void MainCommands::read()
{
    string text;
    cout << "Enter a filename or its path to read it - ";
    getline(cin, filename);

    ifstream readFile(filename);
    getline(readFile, text);
    cout << text << endl;
    readFile.close();
}

void MainCommands::copyfile()
{
    string mfname, cfname, ctext;
    cout << "Enter the filename or specify to file path that is to be copied - ";
    getline(cin, mfname);
    cout << "Now enter the the name of the file in which the contents of " << mfname << " to be copied - \n";
    getline(cin, cfname);

    ofstream copiedfile;
    copiedfile.open(cfname, ios_base::app);
    ifstream readFile(mfname);
    getline(readFile, ctext);
    copiedfile<<ctext<<endl;
    readFile.close();
    copiedfile.close();
}

int MainCommands::info_system()
{
#ifdef __linux__
    int r = system("cat /root/os-release");
    return 1;
#elif __unix__
    int r = system("cat /root/os-release");
    return 1;
#elif __APPLE__
    int r = system("cat /root/os-release");
    return 1;
#elif __WIN32 || __WIN64
    int r = system("systeminfo");
    return 1;
#endif
    return 0;
}

void MainCommands::echo()
{
    string text;
    getline(cin, text);
    cout << text << endl;
}

void MainCommands::rootDisplay()
{
    string passwd, expasswd, expasspath = "root/userdetails/passwd.txt";
    ifstream exPasswordFile(expasspath);
    getline(exPasswordFile, expasswd);
    cout << "Enter the password - ";
    getline(cin, passwd);
    if(passwd == expasswd)
    {
        string userpath="root/userdetails/user.txt", username;
        ifstream userFile(userpath);
        getline(userFile, username);
        cout << "Username:- "<< username << endl;
        cout << "Password:- "<<expasswd<<endl;
        userFile.close();
    }
    else
        cout << "OOPS! Password is wrong. Try again next time\n";
    exPasswordFile.close();
}

void MainCommands::renameFile()
{
    char ofile[SIZE], nfile[SIZE];
    cout << "Enter the name of the file which you want to rename - ";
    cin.sync();
    cin.getline(ofile, SIZE);
    cout << "Enter the new name - ";
    cin.sync();
    cin.getline(nfile, SIZE);
    if(!(rename(ofile, nfile)))
        cout << "Successfully changed\n";
    else    
        cout << "Error\n";
}

void MainCommands::renameDir()
{
    char odir[SIZE], ndir[SIZE];
    cout << "Enter the name of the folder/directory which you want to rename - ";
    cin.sync();
    cin.getline(odir, SIZE);
    cout << "Enter the new name - ";
    cin.sync();
    cin.getline(ndir, SIZE);
    if (!(rename(odir, ndir)))
        cout << "Successfully changed\n";
    else
        cout << "Error\n";
}

void MainCommands::getf()
{
    char foldername[SIZE];
    printf("Enter the name of the folder or directory first: ");
    cin.sync();
    cin.getline(foldername, SIZE);
    DIR *dp;
    struct dirent *dirp;

    if ((dp = opendir(foldername)) == NULL)
    {
        printf("can't find %s\n", foldername);
    }
    else
    {
        char reciepent[SIZE];
        printf("Enter the filename or foldername to find: ");
        cin.sync();
        cin.getline(reciepent, SIZE);
        while ((dirp = readdir(dp)) != NULL)
        {
            if (!strcmp(dirp->d_name, reciepent))
                printf("%s is present in the folder %s\n", dirp->d_name, foldername);
        }
    }
    closedir(dp);
}

void MainCommands::findf()
{
    char word[SIZE];
    FILE *fptr;

    int i = 0, line = 1;
    int confirm;
    int linearray[1000];

    char filename[SIZE];
    printf("Enter filename: ");
    cin.sync();
    cin.getline(filename, SIZE);

    char str[BUFFER_SIZE];

    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file.\n");
    }
    else
    {
        printf("Enter the word to find: ");
        cin.sync();
        cin.getline(word, SIZE);
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


void MainCommands::calc()
{
    char type;
    printf("Enter d for decimal operations and i for integer operation: ");
    cin.sync();
    cin >> type;
    if (type == 'i')
    {
        cin.sync();
        int a, b;
        printf("Enter first number: ");
        cin>>a;
        printf("Enter second number: ");
        cin.sync();
        cin>>b;
        char o;
        printf("Enter operation(+, -, /, *): ");
        cin.sync();
        cin>>o;
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
        cin.sync();
        float x, y;
        printf("Enter first number: ");
        cin>>x;
        printf("Enter second number: ");
        cin.sync();
        cin>>y;
        char o;
        printf("Enter operation(+, -, /, *): ");
        cin.sync();
        cin>>o;
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