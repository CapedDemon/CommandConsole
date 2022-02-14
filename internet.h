/* This is header file contains all the functions related to internet which are 
implemented in the main.c program. It is the same header file like MainCommands.h */

// libraries
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

// first function - printing the ipaddress of the user
void ipad(){
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
    printf("IPv4 address is:    %s\n", arr, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
}