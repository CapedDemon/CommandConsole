#include <iostream>
#include <unistd.h>
#include <ios>
#include <fstream>
#include <dirent.h>
#include <ctime>
#include <time.h>
#include <windows.h>
#include "MainCommands.hpp"

void MainCommands::rootChange()
{
    string username, password, expassword, expasspath = "root/userdetails/passwd.txt";
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
            string userpath = "root/userdetails/user.txt", newUsername;
            ofstream userFile(userpath);
            userFile.clear();

            cout << "|\tType your new usernmae - ";
            getline(cin, newUsername);

            userFile << newUsername;
            userFile.close();
        }

        else if (decision == "p")
        {
            string passpath = "root/userdetails/passwd.txt", newPasswd;
            ofstream passFile(passpath);
            passFile.clear();

            cout << "|\tType your new password - ";
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

            cout << "|\tType your new usernmae - ";
            getline(cin, newUsername);
            cout << "|\tType your new password - ";
            getline(cin, newPasswd);

            userFile << newUsername;
            passFile << newPasswd;
            userFile.close();
            passFile.close();
        }

        else
            cout << "|\tTry again next time\n";
    }
    else
    {
        cout << "|\tOOPS ! Password didn't match try again.\n";
    }
    exPass.close();
}

void MainCommands::help()
{
    printf("|\tFor extra information read the README.md file\n");
    printf("|\tIn all the cases first write the command hit enter and then give the arguements\n|\t\n");

    printf("|\t>>calc - This command open a terminal calculator and you can do simple calculator operation in this.\n|\tThe operaation are - (+, -, * , /, ^(Power of. Ex- 3^2 = 9)\n|\tFirst number (operation) Second Number\n|\tFor doing operation in decimal give d and for integer give i\n|\t\n|\t\n");
    printf("|\t>>time - This command prints the current date and time\n|\t\n");
    printf("|\t>>make - This command will make a file for you and you need to give command which type of extension do you want.\n|\n");
    printf("|\t>>remo - This command will remove a file\n|\n");
    printf("|\t>>list - This will print the files and folders in your directory\n|\n");
    printf("|\t>>wrte - This will write in the file you will give. Start writing the text with a space.\n|\n");
    printf("|\t>>wrta - This will append in your file. Start writing the text with a space and tehn write all the things which you want.\n|\tFor example - Suppose there is hello initially written. So you want write hi with a space between hello and hi,\n|\t so you should give two spaces before writing in the terminal\n|\n");
    printf("|\t>>quit - write quit and hit enter to exit the terminal\n|\n");
    printf("|\t>>pcwd - Print Current Working Directory\n|\n");
    printf("|\t>>ccwd - Change Current Working Directory\n|\n");
    printf("|\t>>mkdr - This will make a folder in the current directory\n|\n");
    printf("|\t>>rmdr - This will remove a folder in the current directory\n|\n");
    printf("|\t>>info - This will show you the details of the STerminal\n|\n");
    printf("|\t>>clr - This will clear the screen of the terminal\n|\n");
    printf("|\t>>read - This will print the content of the file.\n|\n");
    printf("|\t>>cnge - This will change your username and password\n|\n");
    printf("|\t>>cfile - This will copy the contents of one file to another file.\n|\n");
    printf("|\t>>sys - This will print the information of your OS.\n|\n");
    printf("|\t>>echo - This will print anything which you have given. After writing echo press enter then write whatever you want and press enter.\n|\n");
    printf("|\t>>root - This will print the username and password\n|\n");
    printf("|\t>>rfile - This will rename the file with the name you want.\n|\n");
    printf("|\t>>rdr - This will rename the folder with the name you want.\n|\n");
    printf("|\t>>getf - This will confirm you that the fille or folder name you have given is present in the directory that you specified.\n|\n");
    printf("|\t>>findf - This will find the specified word in a given file and print the line where it is located.\n|\n");
    printf("|\t>>hist - This will print all the commands which you have written\n|\n");
    printf("|\t>>game - This will start a cricket game.\n|\n");
    printf("|\t>>ipad - This will show the IPv4 address.\n|\n");
}

void MainCommands::pcd()
{
    char *tmp = new char[256];
    getcwd(tmp, 256);
    cout << tmp ;
}

void MainCommands::list()
{
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        printf("|\tNothing in this directory\n\n");
    }

    struct dirent *entity;
    entity = readdir(dir);
    while (entity != NULL)
    {
        printf("|\t%s\n", entity->d_name);
        entity = readdir(dir);
    }
    printf("|\t\n|\t\n");
    closedir(dir);
}

void MainCommands::ccwd()
{
    char nwd[256];
    cout << "|\tGive the path of the new directory - ";
    cin.sync();
    cin.getline(nwd, 256);

    if (chdir(nwd) == 0)
        printf("|\tsuccessfully changed\n");
    else
        printf("|\tcannot change directory\n");
}

void MainCommands::clearScreen()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    cout << "\033[2J\033[1;1H";
#endif

#if defined(_WIN32) || defined(_WIN64)
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

void MainCommands::gettime()
{
    // variable to get the time
    time_t ltime;
    char buf[50];

    time(&ltime);
    printf("|\tThe time is %s |\n", ctime_r(&ltime, buf));
}

void MainCommands::make()
{
    fstream file;
    cout << "|\tEnter a new filename with its file extension - ";
    getline(cin, filename);

    file.open(filename, ios::out);

    if (!file)
        cout << "|\terror\n";
    else
        cout << "|\tFile created\n";
    file.close();
}

void MainCommands::wrte()
{
    string text;
    cout << "|\tEnter the filename or file path to write in it - ";
    getline(cin, filename);
    ofstream writeFile(filename);

    cout << "|\tEnter the text which is to be written in the file - " << endl;
    getline(cin, text);
    writeFile << text;
    writeFile.close();
}

void MainCommands::wrta()
{
    string text;
    cout << "|\tEnter the filename or file path to append something in it - ";
    getline(cin, filename);
    ofstream appendFile;
    appendFile.open(filename, ios_base::app);

    cout << "|\tEnter the text to append in the file - " << endl;
    getline(cin, text);
    appendFile << text << endl;
    appendFile.close();
}

void MainCommands::remo()
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

void MainCommands::mkdr()
{
    cout << "|\tEnter the name of the folder or a new path - ";
    getcwd(dirname, 260);
    if (mkdir(dirname) == -1)
    {
        cout << "|\tCannot create directory\n";
    }
    else
        cout << "|\tDirectory created\n";
}

void MainCommands::rmdr()
{
    cout << "|\tEnter the name of the folder or a path to delete - ";
    cin.sync();
    cin.getline(dirname, 260);
    if (rmdir(dirname) == 1)
        cout << "|\tDirectory deleted\n";
    else
        cout << "|\tCannot delete directory\n";
}

void MainCommands::info()
{
    cout << "|\tCommand Console is a fast, light-weight and secure shell.\nIt can run cross-platform - wndows, macOS and linux.\nType help to know about the commands.\nFor any query write us email - dolaishreejan@gmail.com\n\n";
}

void MainCommands::read()
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
    readFile.close();
}

void MainCommands::copyfile()
{
    string mfname, cfname, ctext;
    cout << "|\tEnter the filename or specify to file path that is to be copied - ";
    getline(cin, mfname);
    cout << "|\tNow enter the the name of the file in which the contents of " << mfname << " to be copied - \n";
    getline(cin, cfname);

    ofstream copiedfile;
    copiedfile.open(cfname, ios_base::app);
    ifstream readFile(mfname);
    while (getline(readFile, ctext))
    {
        copiedfile << ctext << endl;
    }
    
    readFile.close();
    copiedfile.close();
}

int MainCommands::info_system()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#include <sys/sysinfo.h>
    struct sysinfo info;
    ::sysinfo(&info);

    // 1 Gigabyte = 1024 megabytes = 1024 * 1024 kbytes = 1024 * 1024 * 1024 bytes;
    constexpr double factor = 1024 * 1024 * 1024;
    constexpr uint64_t one_day_to_seconds = 24 * 60 * 60;

    cout << "|\t [*] System uptime since boot (seconds) = " << info.uptime << '\n'
         << "|\t [*] System uptime since boot    (days) = " << info.uptime / one_day_to_seconds << '\n'
         << "|\t [*]              Total RAM memory (Gb) = " << info.totalram / factor << '\n'
         << "|\t [*]              Free  RAM memory (Gb) = " << info.freeram / factor << '\n'
         << "|\t [*]                    Total SWAP (Gb) = " << info.totalswap / factor << '\n'
         << "|\t [*]                     Free SWAP (Gb) = " << info.freeswap / factor << '\n'
         << "|\t [*]        Number of processes running = " << info.procs << '\n'
         << "|\t\n";
#endif

#if defined(__WIN32) || defined(__WIN64)
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
    cout << "|\tEnter the password - ";
    getline(cin, passwd);
    if (passwd == expasswd)
    {
        string userpath = "root/userdetails/user.txt", username;
        ifstream userFile(userpath);
        getline(userFile, username);
        cout << "|\tUsername:- " << username << endl;
        cout << "|\tPassword:- " << expasswd << endl;
        userFile.close();
    }
    else
        cout << "|\tOOPS! Password is wrong. Try again next time\n";
    exPasswordFile.close();
}

void MainCommands::renameFile()
{
    char ofile[260], nfile[260];
    cout << "|\tEnter the name of the file which you want to rename - ";
    cin.sync();
    cin.getline(ofile, 260);
    cout << "|\tEnter the new name - ";
    cin.sync();
    cin.getline(nfile, 260);
    if (!(rename(ofile, nfile)))
        cout << "|\tSuccessfully changed\n";
    else
        cout << "|\tError\n";
}

void MainCommands::renameDir()
{
    char odir[260], ndir[260];
    cout << "|\tEnter the name of the folder/directory which you want to rename - ";
    cin.sync();
    cin.getline(odir, 260);
    cout << "|\tEnter the new name - ";
    cin.sync();
    cin.getline(ndir, 260);
    if (!(rename(odir, ndir)))
        cout << "|\tSuccessfully changed\n";
    else
        cout << "|\tError\n";
}

void MainCommands::getf()
{
    char foldername[260];
    printf("|\tEnter the name of the folder or directory first: ");
    cin.sync();
    cin.getline(foldername, 260);
    DIR *dp;
    struct dirent *dirp;

    if ((dp = opendir(foldername)) == NULL)
    {
        printf("|\tcan't find %s\n", foldername);
    }
    else
    {
        char reciepent[260];
        printf("|\tEnter the filename or foldername to find: ");
        cin.sync();
        cin.getline(reciepent, 260);
        while ((dirp = readdir(dp)) != NULL)
        {
            if (!strcmp(dirp->d_name, reciepent))
                printf("|\t%s is present in the folder %s\n", dirp->d_name, foldername);
        }
    }
    closedir(dp);
}

void MainCommands::findf()
{
    char word[260];
    FILE *fptr;

    int i = 0, line = 1;
    int confirm;
    int linearray[1000];

    char filename[260];
    printf("|\tEnter filename: ");
    cin.sync();
    cin.getline(filename, 260);

    char str[BUFFER_SIZE];

    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("|\tCannot open file.\n");
    }
    else
    {
        printf("|\tEnter the word to find: ");
        cin.sync();
        cin.getline(word, 260);
        printf("|\tThe word is find in line number:- \n");
        while (fgets(str, BUFFER_SIZE, fptr) != NULL)
        {
            if (strstr(str, word))
            {
                linearray[i] = line;
                confirm = 1;
                printf("|\t%d\n", linearray[i]);
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
            printf("|\tActually! eh word is not present.\n");
        }
    }
    fclose(fptr);
}

void MainCommands::calc()
{
    char type;
    printf("|\tEnter d for decimal operations and i for integer operation: ");
    cin.sync();
    cin >> type;
    if (type == 'i')
    {
        cin.sync();
        int a, b;
        printf("|\tEnter first number: ");
        cin >> a;
        printf("|\tEnter second number: ");
        cin.sync();
        cin >> b;
        char o;
        printf("|\tEnter operation(+, -, /, *): ");
        cin.sync();
        cin >> o;
        if (o == '+')
        {
            printf("|\t%d\n\n", a + b);
        }
        else if (o == '-')
        {
            printf("|\t%d\n\n", a - b);
        }
        else if (o == '*')
        {
            printf("|\t%d\n\n", a * b);
        }
        else if (o == '/')
        {
            printf("|\t%d\n\n", a / b);
        }
    }
    else
    {
        cin.sync();
        float x, y;
        printf("|\tEnter first number: ");
        cin >> x;
        printf("|\tEnter second number: ");
        cin.sync();
        cin >> y;
        char o;
        printf("|\tEnter operation(+, -, /, *): ");
        cin.sync();
        cin >> o;
        if (o == '+')
        {
            printf("|\t%.2f\n\n", x + y);
        }
        else if (o == '-')
        {
            printf("|\t%.2f\n\n", x - y);
        }
        else if (o == '*')
        {
            printf("|\t%.2f\n\n", x * y);
        }
        else if (o == '/')
        {
            printf("|\t%.2f\n\n", x / y);
        }
    }
}