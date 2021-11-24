#include <stdio.h>
#include <stdlib.h>

// Function to print system information
int info_system(){
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