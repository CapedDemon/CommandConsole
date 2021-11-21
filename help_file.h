#include <stdio.h>

//function to print the help menu.
void help()
{
    printf("\tIn all the cases first write the command hit enter and then give the arguements\n\n");

    printf(">>calc - This command open a terminal calculator and you can do simple calculator operation in this.\n\tThe operaation are - (+, -, * , /, ^(Power of. Ex- 3^2 = 9)\n\tFirst number (operation) Second Number\n\tFor doing operation in decimal give d and for integer give i\n\n\n");
    printf(">>date - This command prints the current date and time\n\n");
    printf(">>make - This command will make a file for you and you need to give command which type of extension do you want.\n\n");
    printf(">>remo - This command will remove a file\n\n");
    printf(">>list - This will print the files and folders in your directory\n\n");
    printf(">>wrte - This will write in the file you will give. Start writing the text with a space.\n\n");
    printf(">>wrta - This will append in your file. Start writing the text with a space and tehn write all the things which you want.\nFor example - Suppose there is hello initially written. So you want write hi with a space between hello and hi,\n so you should give two spaces before writing in the terminal\n\n");
    printf(">>quit - write quit and hit enter to exit the terminal\n\n");
    printf(">>pcwd - Print Current Working Directory\n\n");
    printf(">>ccwd - Change Current Working Directory\n\n");
    printf(">>mkdr - This will make a folder in the current directory\n\n");
    printf(">>rmdr - This will remove a folder in the current directory\n\n");
    printf(">>info - This will show you the details of the STerminal\n\n");
    printf(">>clr - This will clear the screen of the terminal\n\n");
    printf(">>read - This will print the content of the file.\n\n");
    printf(">>cnge - This will change your username and password\n\n");
    printf(">>copy - This will copy the contents of one file to another file.\n\n");
    printf(">>sys - This will print the information of your OS.\n\n");
    printf(">>echo - This will print anything which you have given. After writing echo press enter then write whatever you want and press enter.\n\n");
    printf(">>root - This will print the username and password\n\n");
}