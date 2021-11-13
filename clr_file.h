#include <stdio.h>
#include <stdlib.h>

//I have made this function thinking that the clearScreen will work on every system.
void clearScreen()
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}
