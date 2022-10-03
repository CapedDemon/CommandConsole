#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <time.h>
#include <queue>
#include "MainCommands.hpp"
#include "maincommands.cpp"
#include "Others/cricket.hpp"
#include "internetthings.cpp"

using namespace std;

// implementation of queue
queue<string> Q;

class CClass
{
public:
    CClass(int startP)
    {
        CClass::staringProgram = startP;
    };

    void welcomeStatement();
    void cmdTake();
    int showRuncmdloop();

private:
    int staringProgram = 0;
    bool runingcmdloop = false;

    // intialization to check the time
    time_t my_time;

    // seeking username and password.
    // Going to make the variables and ask for username and password
    // if not present in the files
    string username, password;
    string rootPassword = "root/userdetails/passwd.txt";
    string rootUsername = "root/userdetails/user.txt";

    // checking the file size and logging in
    bool checkANDlogin()
    {
        bool fDecision;

        ifstream in_file(rootPassword, ios::binary);
        in_file.seekg(0, ios::end);
        int fileSize = in_file.tellg();

        // new user
        if (fileSize == 0)
        {
            // another variable to verify the password
            string verPassword;

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
                getline(cin, verPassword);

                // verifying
                if (password == verPassword)
                {
                    ofstream userFile(rootUsername);
                    ofstream userPasswd(rootPassword);

                    userFile << username;
                    userPasswd << password;

                    userFile.close();
                    userPasswd.close();

                    passLoop = 0;
                    fDecision = true;
                }

                else
                {
                    string choice;
                    cout << "OOPs ! Password didn't match!\nWant to continue - (y/n): ";

                    getline(cin, choice);

                    if (choice == "n")
                    {
                        passLoop = 0;
                        fDecision = false;
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
                fDecision = true;
            else
                fDecision = false;
            userName.close();
            userPasswd.close();
        }
        return fDecision;
    }
};

int CClass::showRuncmdloop()
{
    return CClass::runingcmdloop;
}

void CClass ::welcomeStatement()
{
    if (CClass::staringProgram == 1)
    {
        time(&(CClass::my_time));
        char buf[50];
        cout << "Welcome to Command Console." << endl
             << endl
             << "Time: " << ctime_r(&(CClass::my_time), buf) << endl
             << "(Type help for manual)\n\n";

        bool login = CClass::checkANDlogin();
        CClass::runingcmdloop = login;
    }
}

void CClass::cmdTake()
{
    if (showRuncmdloop() == false)
        cout << "Bye";

    else
    {
        string cmdStr;
    MainCommands MC(true);

        while (showRuncmdloop())
        {
            cout << "| (:-) " << CClass::username << " (root): [";
            MC.pcd();
            cout << "] $: ";
            getline(cin, cmdStr);
            Q.push(cmdStr);
            if (cmdStr == "quit")
                CClass::runingcmdloop = false;

            else if (cmdStr == "hist")
            {
                queue<string> q = Q;

                while (!q.empty())
                {
                    cout << "|\t" << q.front() << endl;
                    q.pop();
                }
            }

            else if (cmdStr == "cnge")
            {
                MC.rootChange();
            }
            
            else if (cmdStr == "help")
            {
                MC.help();

            }

            else if (cmdStr == "pcwd")
            {
                MC.pcd();
                cout << endl;

            }

            else if (cmdStr == "list")
            {

                MC.list();
            }

            else if (cmdStr == "clr")
            {

                MC.clearScreen();
            }

            else if (cmdStr == "ccwd")
            {

                MC.ccwd();
            }

            else if (cmdStr == "time")
            {

                MC.gettime();
            }

            else if (cmdStr == "make")
            {

                MC.make();
            }

            else if (cmdStr == "wrte")
            {

                MC.wrte();
            }

            else if (cmdStr == "wrta")
            {

                MC.wrta();
            }

            else if (cmdStr == "remo")
            {

                MC.remo();
            }

            else if (cmdStr == "mkdr")
            {

                MC.mkdr();
            }

            else if (cmdStr == "rmdr")
            {

                MC.rmdr();
            }

            else if (cmdStr == "info")
            {

                MC.info();
            }

            else if (cmdStr == "read")
            {

                MC.read();
            }

            else if (cmdStr == "cfile")
            {

                MC.copyfile();
            }

            else if (cmdStr == "sys")
            {

                int a = MC.info_system();
            }

            else if (cmdStr == "echo")
            {

                MC.echo();
            }

            else if (cmdStr == "root")
            {

                MC.rootDisplay();
            }

            else if (cmdStr == "rfile")
            {

                MC.renameFile();
            }

            else if (cmdStr == "rdr")
            {

                MC.renameDir();
            }

            else if (cmdStr == "getf")
            {

                MC.getf();
            }

            else if (cmdStr == "findf")
            {

                MC.findf();
            }

            else if (cmdStr == "calc")
            {

                MC.calc();
            }

            else if (cmdStr == "game")
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

            else if (cmdStr == "ipad")
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
    CClass Mainterminal(1);
    Mainterminal.welcomeStatement();
    Mainterminal.cmdTake();

    return 0;
}