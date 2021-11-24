<p align="left"> <a href="https://www.gnu.org/software/bash/" target="_blank"> <img src="https://www.vectorlogo.zone/logos/gnu_bash/gnu_bash-icon.svg" alt="bash" width="40" height="40"/> </a>

# **CommandConsole**
As the name suggests this is a terminal like software. Like a normal terminal in linux or command prompt in windows, it also works like the same. It is made using C language and my motive of building this software is to refresh my C language skills and to make something which can take command and work.

![](https://github.com/Shreejan-35/CommandConsole/blob/main/images/terminal_image_social.png)

# <b>Documentation</b>
<br/>
The main program is written in the main.c file and the functions written there are in there individual files and I have made them header files and included them where it is necessary. All the code is written in C language. I have included a .exe file of the main.c file. I have run it in my system and it worked fine doing all the things.

<br/>

### The list of files are:
- Calculator: The code is written in calc_file.h
- Change Current Working Directory: The code is written in ccwd_file.h
- Clear the Screen: The code is written in clr_file.h
- Show the date: The code is written in date_file.h
- Make new directory: The code is written in file_mkdr1.h
- Help(which show all the function to be run): The code is written in help_file.h
- List all the files and directories: The code is written in list_file.h
- Create a new file: The code is written in make_file.h
- Print the current working directory: The code is written in pcwd_file.h
- Remove the file: The code is written in remo_file.h
- Remove the directory file: The code is written in rmdr_file.h
- To append something in a file: The code is written in wrta_file.h
- To write something in a file: The code is written in wrte_file.h
- To print the content of the file: The code is written in open_file1.h
- To change the username and password: The code is written in change_root.h
- To copy the contents of one file to another file: The code is written in copy_file.h
- To print the information of OS: The code is written in system_info.h
- To print the thing you wanted: The code is written in echo_file.h
- To print username & password: The code is written in userinfo.h
- To rename the file: The code is written in rename_file.h

## Things to remember while executing the application:
- Provide the correct command or else it will show "Error: Wrong Command. Run command which is there. Type help for information".
- Type quit to stop the terminal.
- When changing the directory provide the exact name of the directory.
## <br/>
## Limitations and things to be done more and help required:
- I don't know whether it can run in other softwares(like- linux, etc) as I have done this code in windows laptop. I want you all to test this.
- Anyother modification will be considered.

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
