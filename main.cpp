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

private:
    int staringProgram = 0;
    bool runingcmdloop = false;

    // intialization to check the time
    time_t my_time = time(NULL);

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

void CClass ::welcomeStatement()
{
    if (CClass::staringProgram == 1)
    {
        cout << "Welcome to Command Console." << endl
             << endl
             << "Time: " << ctime(&(CClass::my_time)) << endl
             << "(Type help for manual)\n\n";

        bool login = CClass::checkANDlogin();
        CClass::runingcmdloop = login;
    }
}

void CClass::cmdTake()
{
    if (CClass::runingcmdloop == false)
        cout << "Bye";

    else
    {
        string cmdStr;
        MainCommands MC(true);

        while (CClass::runingcmdloop)
        {
            cout << "| (:-) " << CClass::username << " (root): [" << (MC.pcd()) << "] $: ";
            getline(cin, cmdStr);

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
                Q.push("hist");
            }

            else if (cmdStr == "cnge")
            {
                MC.rootChange();
                Q.push("cnge");
            }

            else if (cmdStr == "help")
            {
                MC.help();
                Q.push("help");
            }

            else if (cmdStr == "pcwd")
            {
                cout << MC.pcd() << endl;
                Q.push("pcwd");
            }

            else if (cmdStr == "list")
            {
                Q.push("list");
                MC.list();
            }

            else if (cmdStr == "clr")
            {
                Q.push("clr");
                MC.clearScreen();
            }

            else if (cmdStr == "ccwd")
            {
                Q.push("ccwd");
                MC.ccwd();
            }

            else if (cmdStr == "time")
            {
                Q.push("time");
                MC.gettime();
            }

            else if (cmdStr == "make")
            {
                Q.push("make");
                MC.make();
            }

            else if (cmdStr == "wrte")
            {
                Q.push("wrte");
                MC.wrte();
            }

            else if (cmdStr == "wrta")
            {
                Q.push("wrta");
                MC.wrta();
            }

            else if (cmdStr == "remo")
            {
                Q.push("remo");
                MC.remo();
            }

            else if (cmdStr == "mkdr")
            {
                Q.push("mkdr");
                MC.mkdr();
            }

            else if (cmdStr == "rmdr")
            {
                Q.push("rmdr");
                MC.rmdr();
            }

            else if (cmdStr == "info")
            {
                Q.push("info");
                MC.info();
            }

            else if (cmdStr == "read")
            {
                Q.push("read");
                MC.read();
            }

            else if (cmdStr == "cfile")
            {
                Q.push("cfile");
                MC.copyfile();
            }

            else if (cmdStr == "sys")
            {
                Q.push("sys");
                int a = MC.info_system();
            }

            else if (cmdStr == "echo")
            {
                Q.push("echo");
                MC.echo();
            }

            else if (cmdStr == "root")
            {
                Q.push("root");
                MC.rootDisplay();
            }

            else if (cmdStr == "rfile")
            {
                Q.push("rfile");
                MC.renameFile();
            }

            else if (cmdStr == "rdr")
            {
                Q.push("rdr");
                MC.renameDir();
            }

            else if (cmdStr == "getf")
            {
                Q.push("getf");
                MC.getf();
            }

            else if (cmdStr == "findf")
            {
                Q.push("findf");
                MC.findf();
            }

            else if (cmdStr == "calc")
            {
                Q.push("calc");
                MC.calc();
            }

            else if (cmdStr == "game")
            {
                Q.push("game");
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
                Q.push("ipad");
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