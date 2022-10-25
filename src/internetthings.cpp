/* This is header file contains all the functions related to internet which are 
implemented in the main.cpp program. It is the same header file like MainCommands.hpp */

// libraries
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    #include <sys/socket.h>
    #include <sys/ioctl.h>
    #include <netinet/in.h>
    #include <net/if.h>
    #include <arpa/inet.h>
#endif

// first function - printing the ipaddress of the user
void ipad(){
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    int n;
    struct ifreq ifr;
    char arr[] = "eth0";

    n=socket(AF_INET, SOCK_STREAM, 0);

    //IPv4 address
    ifr.ifr_addr.sa_family = AF_INET;

    // copying it to the struct

    strncpy(ifr.ifr_name, arr, IFNAMSIZ -1);

    // accessing the network interface 
    ioctl(n, SIOCGIFADDR, &ifr);
    close(n);

    // printing the ipaddress
    cout << ("IPv4 address is:    %s\n", arr, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
#endif
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <winsock.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#define INFO_BUFFER_SIZE 32767
    TCHAR infoBuf[INFO_BUFFER_SIZE];
    DWORD bufCharCount = INFO_BUFFER_SIZE;

    if (!GetComputerName(infoBuf, &bufCharCount))
        cout << (TEXT("GetComputerName"));
    
    WSADATA ws;
    int res = WSAStartup(MAKEWORD(2,2), &ws);
    if (res)
    {
        cout << "Failed to intialize" << res << endl;
    }

    struct hostent *host_info;
    struct in_addr addr;
    DWORD dw;
    char * hostname = (char *) infoBuf;
    host_info = gethostbyname(hostname);
    cout << "|\tHostname : " << host_info->h_name << endl;
    int i=0;
    while (host_info->h_addr_list[i] != 0)
    {
        addr.s_addr = *(u_long *)host_info->h_addr_list[i++];
        cout << "|\tIP Address " << inet_ntoa(addr) << endl; // inet_ntoa function converts IPv4 address to ASCII string in Internet standard dotted-decimal format.
    }

#endif
}