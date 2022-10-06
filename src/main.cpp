#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <time.h>
#include <queue>
#include "maincommands.hpp"
#include "Others/cricket.hpp"
#include "internetthings.cpp"

using namespace std;

class CClass
{
public:
    CClass(bool startprogram)
    {
        CClass::startprogram = startprogram;
    };
    // implementation of queue
    queue<string> Q;
    
    const double version = 3.5;
    void welcomeStatement();
    void cmdTake();
    int showRuncmdloop();

private:
    bool startprogram = false;
    bool runingcmdloop = false;

    // intialization to check the time
    time_t computertime;

    // seeking username and password.
    // Going to make the variables and ask for username and password
    // if not present in the files
    string username, password;
    string rootPassword = "root/userdetails/passwd.txt";
    string rootUsername = "root/userdetails/user.txt";

    // checking the file size and logging in
    bool CheckAndLogin()
    {
        bool finaldecision;

        ifstream in_file(rootPassword, ios::binary);
        in_file.seekg(0, ios::end);
        int fileSize = in_file.tellg();

        // new user
        if (fileSize == 0)
        {
            // another variable to verify the password
            string verifyPassword;

            // we will repeat the process of entering the values
            // until password is correct
            int passLoop = 1;
            while (passLoop)
            {
                cout << "Enter a beautiful and dashing username - \n";
                getline(cin, username);

                cout << "Enter a strong password - ";
                getline(cin, password);

                cout << "Verify password - ";
                getline(cin, verifyPassword);

                // verifying
                if (password == verifyPassword)
                {
                    ofstream userFile(rootUsername);
                    ofstream userPasswd(rootPassword);

                    userFile << username;
                    userPasswd << password;

                    userFile.close();
                    userPasswd.close();

                    passLoop = 0;
                    finaldecision = true;
                }

                else
                {
                    string choice;
                    cout << "OOPs ! Password didn't match!\nWant to continue - (y/n): ";

                    getline(cin, choice);

                    if (choice == "n")
                    {
                        passLoop = 0;
                        finaldecision = false;
                    }
                }
            }
        }

        // existing user
        else
        {
            string exPass;
            ifstream userPasswd(rootPassword);
            ifstream userName(rootUsername);

            getline(userPasswd, exPass);
            getline(userName, username);

            cout << "Enter the password - ";
            getline(cin, password);

            if (password == exPass)
            {
                finaldecision = true;
            }
            else {
                finaldecision = false;}
            userName.close();
            userPasswd.close();
        }
        return finaldecision;
    }
};

int CClass::showRuncmdloop()
{
    return CClass::runingcmdloop;
}

void CClass ::welcomeStatement()
{
    if (CClass::startprogram == true)
    {
        time(&(CClass::computertime));
        char buf[50];
        cout << "Welcome to Command Console." << endl
             << endl
             << "Time: " << ctime_r(&(CClass::computertime), buf) << endl
             << "(Type help for manual)\n\n";

        bool login;
        login = CClass::CheckAndLogin();
        CClass::runingcmdloop = login;
    }
}

void CClass::cmdTake()
{
    if (showRuncmdloop() == false){
        cout << "Bye";}

    else
    {
        string command;
        maincommands MC(true);

        while (showRuncmdloop())
        {
            cout << "| (:-) " << CClass::username << " (root): [";
            MC.pcd();
            cout << "] $: ";
            getline(cin, command);
            Q.push(command);
            if (command == "quit")
                CClass::runingcmdloop = false;

            else if (command == "hist")
            {
                queue<string> q = Q;

                while (!q.empty())
                {
                    cout << "|\t" << q.front() << endl;
                    q.pop();
                }
            }

            else if (command == "cnge")
            {
                MC.rootChange();
            }
            
            else if (command == "help")
            {
                MC.help();
            }

            else if (command == "pcwd")
            {
                MC.pcd();
                cout << endl;
            }

            else if (command == "list")
            {
                MC.list();
            }

            else if (command == "clr")
            {
                MC.clearScreen();
            }

            else if (command == "ccwd")
            {
                MC.ccwd();
            }

            else if (command == "time")
            {
                MC.gettime();
            }

            else if (command == "make")
            {
                MC.make();
            }

            else if (command == "wrte")
            {
                MC.wrte();
            }

            else if (command == "wrta")
            {
                MC.wrta();
            }

            else if (command == "remo")
            {
                MC.remo();
            }

            else if (command == "mkdr")
            {
                MC.mkdr();
            }

            else if (command == "rmdr")
            {
                MC.rmdr();
            }

            else if (command == "info")
            {
                MC.info();
            }

            else if (command == "read")
            {
                MC.read();
            }

            else if (command == "cfile")
            {
                MC.copyfile();
            }

            else if (command == "sys")
            {
                int a = MC.info_system();
            }

            else if (command == "echo")
            {
                MC.echo();
            }

            else if (command == "root")
            {
                MC.rootDisplay();
            }

            else if (command == "rfile")
            {
                MC.renameFile();
            }

            else if (command == "rdr")
            {
                MC.renameDir();
            }

            else if (command == "getf")
            {
                MC.getf();
            }

            else if (command == "findf")
            {
                MC.findf();
            }

            else if (command == "calc")
            {
                MC.calc();
            }

            else if (command == "game")
            {
                char gdec;
                cout << "Do you want to play the game (y/n) - ";
                cin.sync();
                cin >> gdec;
                if (gdec == 'y')
                {
                    cricket CG(1);
                    CG.cricketGame();
                }
                else if (gdec == 'n')
                {
                    cricket CG(0);
                    CG.cricketGame();
                }
                else
                    cout << "Put the right command\n";
            }

            else if (command == "ipad")
            {
                ipad();
            }
            else
            {
                cout << "|\tGIVE THE RIGHT COMMAND :}>" << endl;
            }
        }
    }
}

int main()
{
    CClass Mainterminal(true);
    Mainterminal.welcomeStatement();
    Mainterminal.cmdTake();

    return 0;
}