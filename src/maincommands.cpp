#include <iostream>
#include <unistd.h>
#include <ios>
#include <fstream>
#include <dirent.h>
#include <ctime>
#include <time.h>
#include <filesystem>
#include <sys/stat.h>
#include <sys/types.h>
#include "maincommands.hpp"

void maincommands::rootChange()
{
    string username;
    string password;
    string expassword;
    string expasspath = "root/userdetails/passwd.txt";
    ifstream exPass(expasspath);

    getline(exPass, expassword);

    cout << "|\tYou are going to change your root details.\nEnter your existing password - ";
    getline(cin, password);

    if (password == expassword)
    {
        string decision;
        cout << "|\tWhat do you want to change  - username(u) / password(p) / both(b) ?\n";
        getline(cin, decision);

        if (decision == "u")
        {
            string userpath = "root/userdetails/user.txt";
            string newUsername;
            ofstream userFile(userpath);
            userFile.clear();

            cout << "|\tType your new usernmae - ";
            getline(cin, newUsername);

            userFile << newUsername;
        }

        else if (decision == "p")
        {
            string passpath = "root/userdetails/passwd.txt";
            string newPasswd;
            ofstream passFile(passpath);
            passFile.clear();

            cout << "|\tType your new password - ";
            getline(cin, newPasswd);

            passFile << newPasswd;
        }

        else if (decision == "b")
        {
            string passpath = "root/userdetails/passwd.txt";
            string newPasswd;
            string userpath = "root/userdetails/user.txt";
            string newUsername;
            ofstream passFile(passpath);
            passFile.clear();
            ofstream userFile(userpath);
            userFile.clear();

            cout << "|\tType your new usernmae - ";
            getline(cin, newUsername);
            cout << "|\tType your new password - ";
            getline(cin, newPasswd);

            userFile << newUsername;
            passFile << newPasswd;
        }

        else
            cout << "|\tTry again next time\n";
    }
    else
    {
        cout << "|\tOOPS ! Password didn't match try again.\n";
    }
}

void maincommands::help()
{
    cout << ("|\tFor extra information read the README.md file\n");
    cout << ("|\tIn all the cases first write the command hit enter and then give the arguements\n|\t\n");

    cout << ("|\t>>calc - This command open a terminal calculator and you can do simple calculator operation in this.\n|\tThe operaation are - (+, -, * , /, ^(Power of. Ex- 3^2 = 9)\n|\tFirst number (operation) Second Number\n|\tFor doing operation in decimal give d and for integer give i\n|\t\n|\t\n");
    cout << ("|\t>>time - This command prints the current date and time\n|\t\n");
    cout << ("|\t>>make - This command will make a file for you and you need to give command which type of extension do you want.\n|\n");
    cout << ("|\t>>remo - This command will remove a file\n|\n");
    cout << ("|\t>>list - This will print the files and folders in your directory\n|\n");
    cout << ("|\t>>wrte - This will write in the file you will give. Start writing the text with a space.\n|\n");
    cout << ("|\t>>wrta - This will append in your file. Start writing the text with a space and tehn write all the things which you want.\n|\tFor example - Suppose there is hello initially written. So you want write hi with a space between hello and hi,\n|\t so you should give two spaces before writing in the terminal\n|\n");
    cout << ("|\t>>quit - write quit and hit enter to exit the terminal\n|\n");
    cout << ("|\t>>pcwd - Print Current Working Directory\n|\n");
    cout << ("|\t>>ccwd - Change Current Working Directory\n|\n");
    cout << ("|\t>>mkdr - This will make a folder in the current directory\n|\n");
    cout << ("|\t>>rmdr - This will remove a folder in the current directory\n|\n");
    cout << ("|\t>>info - This will show you the details of the STerminal\n|\n");
    cout << ("|\t>>clr - This will clear the screen of the terminal\n|\n");
    cout << ("|\t>>read - This will print the content of the file.\n|\n");
    cout << ("|\t>>cnge - This will change your username and password\n|\n");
    cout << ("|\t>>cfile - This will copy the contents of one file to another file.\n|\n");
    cout << ("|\t>>sys - This will print the information of your OS.\n|\n");
    cout << ("|\t>>echo - This will print anything which you have given. After writing echo press enter then write whatever you want and press enter.\n|\n");
    cout << ("|\t>>root - This will print the username and password\n|\n");
    cout << ("|\t>>rfile - This will rename the file with the name you want.\n|\n");
    cout << ("|\t>>rdr - This will rename the folder with the name you want.\n|\n");
    cout << ("|\t>>getf - This will confirm you that the fille or folder name you have given is present in the directory that you specified.\n|\n");
    cout << ("|\t>>findf - This will find the specified word in a given file and print the line where it is located.\n|\n");
    cout << ("|\t>>hist - This will print all the commands which you have written\n|\n");
    cout << ("|\t>>game - This will start a cricket game.\n|\n");
    cout << ("|\t>>ipad - This will show the IPv4 address.\n|\n");
}

void maincommands::pcd()
{
    char *tmp;
    tmp = new char[256];
    getcwd(tmp, 256);
    cout << tmp;
}

void maincommands::list()
{
    DIR *dir;
    dir = opendir(".");
    if (dir == nullptr)
    {
        printf("|\tNothing in this directory\n\n");
    }

    struct dirent *entity;
    entity = readdir(dir);
    while (entity != nullptr)
    {
        cout << "|\t" << entity->d_name << endl;
        entity = readdir(dir);
    }
    cout << ("|\t\n|\t\n");
    closedir(dir);
}

void maincommands::ccwd()
{
    char nwd[256];
    cout << "|\tGive the path of the new directory - ";
    cin.sync();
    cin.getline(nwd, 256);

    if (chdir(nwd) == 0)
        cout << ("|\tsuccessfully changed\n");
    else
        cout << ("|\tcannot change directory\n");
}

void maincommands::clearScreen()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    cout << "\033[2J\033[1;1H";
#endif

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
#endif
}

void maincommands::gettime()
{
    // variable to get the time
    time_t computertime;
    char buf[50];

    time(&computertime);
    cout << "|\tThe time is " << ctime_r(&computertime, buf) << "|\n"
         << endl;
}

void maincommands::make()
{
    fstream file;
    cout << "|\tEnter a new filename with its file extension - ";
    getline(cin, filename);

    file.open(filename, ios::out);

    if (!file)
        cout << "|\terror\n";
    else
        cout << "|\tFile created\n";
}

void maincommands::wrte()
{
    string text;
    cout << "|\tEnter the filename or file path to write in it - ";
    getline(cin, filename);
    ofstream writeFile(filename);

    cout << "|\tEnter the text which is to be written in the file - " << endl;
    getline(cin, text);
    writeFile << text;
}

void maincommands::wrta()
{
    string text;
    cout << "|\tEnter the filename or file path to append something in it - ";
    getline(cin, filename);
    ofstream appendFile;
    appendFile.open(filename, ios_base::app);

    cout << "|\tEnter the text to append in the file - " << endl;
    getline(cin, text);
    appendFile << text << endl;
}

void maincommands::remo()
{
    char fremove[20];
    cout << "|\tEnter the filename or file path to remove - ";
    cin.sync();
    cin.getline(fremove, 20);
    if (remove(fremove) == 0)
    {
        cout << "|\tSuccessfully deleted" << endl;
    }
    else
        cout << "|\tCannot delete" << endl;
}

void maincommands::mkdr()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    cout << "|\tEnter the name of the folder or a new path - ";
    cin.sync();
    cin.getline(dirname, FILENAME_MAX);
    if (mkdir(dirname, 0777) == -1)
    {
        cout << "|\tCannot create directory\n";
    }
    else
        cout << "|\tDirectory created\n";
#endif
#if defined(__WIN32) || defined(__WIN64)
    cout << "|\tEnter the name of the folder or a new path - ";
    cin.sync();
    cin.getline(dirname, FILENAME_MAX);
    if (mkdir(dirname) == -1)
    {
        cout << "|\tCannot create directory\n";
    }
    else
        cout << "|\tDirectory created\n";
#endif
}

void maincommands::rmdr()
{
    cout << "|\tEnter the name of the folder or a path to delete - ";
    cin.sync();
    cin.getline(dirname, FILENAME_MAX);
    if (rmdir(dirname) == 1)
        cout << "|\tDirectory deleted\n";
    else
        cout << "|\tCannot delete directory\n";
}

void maincommands::info()
{
    cout << "|\tCommand Console is a fast, light-weight and secure shell.\nIt can run cross-platform - wndows, macOS and linux.\nType help to know about the commands.\nFor any query write us email - dolaishreejan@gmail.com\n\n";
}

void maincommands::read()
{
    string text;
    cout << "|\tEnter a filename or its path to read it - ";
    getline(cin, filename);

    fstream readFile;
    readFile.open(filename);
    cout << "|\t";

    while (getline(readFile, text))
    {
        cout << text << endl
             << "|\t";
    }
}

void maincommands::copyfile()
{
    string mfname;
    string cfname;
    string ctext;
    cout << "|\tEnter the filename or specify to file path that is to be copied - ";
    cin.sync();
    getline(cin, mfname);
    cout << "|\tNow enter the the name of the file in which the contents of " << mfname << " to be copied - \n";
    cin.sync();
    getline(cin, cfname);

    ofstream copiedfile;
    copiedfile.open(cfname, ios_base::app);
    ifstream readFile(mfname);
    while (getline(readFile, ctext))
    {
        copiedfile << ctext << endl;
    }
}

int maincommands::info_system()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    auto ifs = std::ifstream("/proc/cpuinfo");
    std::string line;
    while (std::getline(ifs, line))
    {
        std::cout << line << '\n';
    }
#endif

#if defined(__WIN32) || defined(__WIN64)
#include <windows.h>
    SYSTEM_INFO siSysInfo;

    // Copy the hardware information to the SYSTEM_INFO structure.

    GetSystemInfo(&siSysInfo);
    cout << "|\tHardware information: \n"
         << "|\t [*] OEM ID: " << siSysInfo.dwOemId << "\n"
         << "|\t [*] Number of processors: " << siSysInfo.dwNumberOfProcessors << endl
         << "|\t [*] PAGE size: " << siSysInfo.dwPageSize << endl
         << "|\t [*] Processor type: " << siSysInfo.dwProcessorType << endl
         << "|\t [*] Minimum application address: " << siSysInfo.lpMinimumApplicationAddress << endl
         << "|\t [*] Maximum application address: " << siSysInfo.lpMaximumApplicationAddress << endl
         << "|\t [*] Active processor mask: " << siSysInfo.dwActiveProcessorMask << endl;
#endif
    return 0;
}

void maincommands::echo()
{
    string text;
    getline(cin, text);
    cout << text << endl;
}

void maincommands::rootDisplay()
{
    string passwd;
    string expasswd;
    string expasspath = "root/userdetails/passwd.txt";
    ifstream exPasswordFile(expasspath);
    getline(exPasswordFile, expasswd);
    cout << "|\tEnter the password - ";
    getline(cin, passwd);
    if (passwd == expasswd)
    {
        string userpath = "root/userdetails/user.txt", username;
        ifstream userFile(userpath);
        getline(userFile, username);
        cout << "|\tUsername:- " << username << endl;
        cout << "|\tPassword:- " << expasswd << endl;
    }
    else
        cout << "|\tOOPS! Password is wrong. Try again next time\n";
}

void maincommands::renameFile()
{
    char ofile[FILENAME_MAX];
    char nfile[FILENAME_MAX];
    cout << "|\tEnter the name of the file which you want to rename - ";
    cin.sync();
    cin.getline(ofile, FILENAME_MAX);
    cout << "|\tEnter the new name - ";
    cin.sync();
    cin.getline(nfile, FILENAME_MAX);
    if (!(rename(ofile, nfile)))
        cout << "|\tSuccessfully changed\n";
    else
        cout << "|\tError\n";
}

void maincommands::renameDir()
{
    char odir[FILENAME_MAX];
    char ndir[FILENAME_MAX];
    cout << "|\tEnter the name of the folder/directory which you want to rename - ";
    cin.sync();
    cin.getline(odir, FILENAME_MAX);
    cout << "|\tEnter the new name - ";
    cin.sync();
    cin.getline(ndir, FILENAME_MAX);
    if (!(rename(odir, ndir)))
        cout << "|\tSuccessfully changed\n";
    else
        cout << "|\tError\n";
}

void maincommands::getf()
{
    char foldername[FILENAME_MAX];
    printf("|\tEnter the name of the folder or directory first: ");
    cin.sync();
    cin.getline(foldername, FILENAME_MAX);
    DIR *dp;
    struct dirent *dirp;

    if ((dp = opendir(foldername)) == nullptr)
    {
        cout << "|\tcan't find " << foldername << endl;
    }
    else
    {
        char reciepent[FILENAME_MAX];
        printf("|\tEnter the filename or foldername to find: ");
        cin.sync();
        cin.getline(reciepent, FILENAME_MAX);
        while ((dirp = readdir(dp)) != nullptr)
        {
            if (!strcmp(dirp->d_name, reciepent))
                cout << "|\t" << dirp->d_name << " is present in the folder " << foldername << endl;
        }
    }
    closedir(dp);
}

void maincommands::findf()
{
    char word[FILENAME_MAX];
    FILE *fptr;

    int i = 0, line = 1;
    int confirm;
    int linearray[1000];

    char filename[FILENAME_MAX];
    cout << ("|\tEnter filename: ");
    cin.sync();
    cin.getline(filename, FILENAME_MAX);

    char str[buffersize];

    fptr = fopen(filename, "r");
    if (fptr == nullptr)
    {
        cout << ("|\tCannot open file.\n");
    }
    else
    {
        cout << ("|\tEnter the word to find: ");
        cin.sync();
        cin.getline(word, FILENAME_MAX);
        cout << ("|\tThe word is find in line number:- \n");
        while (fgets(str, buffersize, fptr) != nullptr)
        {
            if (strstr(str, word))
            {
                linearray[i] = line;
                confirm = 1;
                cout << "|\t " << linearray[i] << endl;
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
            cout << ("|\tActually! eh word is not present.\n");
        }
    }
    fclose(fptr);
}

void maincommands::calc()
{
    char type;
    cout << ("|\tEnter d for decimal operations and i for integer operation: ");
    cin.sync();
    cin >> type;
    if (type == 'i')
    {
        cin.sync();
        int a, b;
        cout << ("|\tEnter first number: ");
        cin.sync();
        cin >> a;
        cout << ("|\tEnter second number: ");
        cin.sync();
        cin >> b;
        char o;
        cout << ("|\tEnter operation(+, -, /, *): ");
        cin.sync();
        cin >> o;
        if (o == '+')
        {
            cout << "|\t" << a + b << "\n\n";
        }
        else if (o == '-')
        {
            cout << "|\t" << a - b << "\n\n";
        }
        else if (o == '*')
        {
            cout << "|\t" << a * b << "\n\n";
        }
        else if (o == '/')
        {
            cout << "|\t" << a / b << "\n\n";
        }
    }
    else
    {
        cin.sync();
        double x, y;
        cout << ("|\tEnter first number: ");
        cin >> x;
        cout << ("|\tEnter second number: ");
        cin.sync();
        cin >> y;
        char o;
        cout << ("|\tEnter operation(+, -, /, *): ");
        cin.sync();
        cin >> o;
        if (o == '+')
        {
            cout << "|\t" << x + y << "\n\n";
        }
        else if (o == '-')
        {
            cout << "|\t" << x - y << "\n\n";
        }
        else if (o == '*')
        {
            cout << "|\t" << x * y << "\n\n";
        }
        else if (o == '/')
        {
            cout << "|\t" << x / y << "\n\n";
        }
    }
}