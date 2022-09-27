#include <iostream>
#include <unistd.h>
#include <ios>
#include <fstream>
#include <dirent.h>
#include <ctime>
#include <time.h>
#include <windows.h>

#pragma once

using namespace std;
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
    void gettime();
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