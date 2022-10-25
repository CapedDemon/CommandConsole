#pragma once
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
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

using namespace std;

class maincommands
{
private:
    bool access;

public:
    int buffersize = 4096;

    maincommands(bool access)
    {
        maincommands::access = access;
    }
    string filename;
    char dirname[260];
    void rootChange();
    void help();
    void pcd();
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