[![CodeFactor](https://www.codefactor.io/repository/github/shreejan-35/commandconsole/badge)](https://www.codefactor.io/repository/github/shreejan-35/commandconsole)
<p align="left"> <a href="https://www.gnu.org/software/bash/" target="_blank"> <img src="https://www.vectorlogo.zone/logos/gnu_bash/gnu_bash-icon.svg" alt="bash" width="40" height="40"/> </a>

# **CommandConsole**
As the name suggests this is a terminal like software. Like a normal terminal in linux or command prompt in windows, it also works like the same. It is made using C language and my motive of building this software is to refresh my C language skills and to make something which can take command and work.

![](https://github.com/Shreejan-35/CommandConsole/blob/main/images/terminal_image_social.png)

# <b>Documentation</b>
<br/>
The main program is written in the main.c file and the functions written there are in there individual files and I have made them header files and included them where it is necessary. All the code is written in C language. I have included a .exe file of the main.c file. I have run it in my system and it worked fine doing all the things.

<br/>

### The list of functions are:
- Calculator: calc
- Change Current Working Directory: ccwd
- Clear the Screen: clr
- Show the date: date
- Make new directory: mkdr
- Help(which show all the function to be run): help
- List all the files and directories: list
- Create new file: make
- Print the current working directory: pcwd
- Remove the file: remo
- Remove the directory file: rmdr
- Append something in a file: wrta
- Write something in a file: wrte
- Print the content of the file: read
- Change the username and password: cnge
- Copy the contents of one file to another file: cfile
- Print the information of OS: sys
- Print the thing you wanted: echo
- Print username & password: root
- Rename the file: rfile
- Rename the folder: rdr
- To confirm that a file or folder is present in a directory specified by you: getf

All the functions are written in **MainCommands.h**

## Things to remember while executing the application:
- Provide the correct command or else it will show "Error: Wrong Command. Run command which is there. Type help for information".
- Type quit to stop the terminal.
- When changing the directory provide the exact name of the directory.
## <br/>
## Limitations and things to be done more and help required:
- I don't know whether it can run in other softwares(like- linux, etc) as I have done this code in windows laptop. I want you all to test this.
- Anyother modification will be considered.

Makefile is also included. The command of make file is:-
```
mingw32-make
```

# <b>Getting Started<b/>

If you have docker installed then it is very good. The steps to execute the software using docker are as follows:-
- type :- 
```
docker run -it shreejan35/commandconsole:version (The latest version is available in the releases).
```
**Recommended 2.6 and above**
- It will pull the image from the docker hub.
- When all the things are done it will start the program. 
- It will be like a normal terminal. First of all type 'list' then check that all the files which are there in the github are shown there. 
- Don't do anything there or else the software will not work as that is the only working directory.
- I have made another directory for you all, i.e, home. Go there by using 'ccwd' command.
- Finally test all the commands.
- Here is my docker repository link - https://hub.docker.com/repository/docker/shreejan35/commandconsole
  
You can clone my repository by executing this:- 
```
git clone https://github.com/Shreejan-35/CommandConsole.git
```
You can also download the zip file, and then run the CommandConsole.exe file.
  
## I have given one screenshot which you can refer to.

![](https://github.com/Shreejan-35/CommandConsole/blob/main/images/Screenshot.JPG)
 
## License is Apache2.0.
 
## This is all the things about my program. If you like it, then please share with others. This is a project which the begineers as well as intermediate programmers can build. Support me by following my github account. Thank you.
