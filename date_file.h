#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//date function. If the user clears the screen it can be usefule to see the date.
void date()
{
    time_t t;
    time(&t);
    printf("%s\n\n", ctime(&t));
}