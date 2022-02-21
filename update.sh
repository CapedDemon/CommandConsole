echo "UPGRADE SIMULATOR"
echo "Do you want to upgrade?(y/n): "
read gitDownload

echo
if [ "$gitDownload" == "y" ];
then

    read -p "USERNAME: " USERNAME
    read -sp "PASSWORD: " PASSWORD
    cd ..
    
    rm -rf CommandConsole
    git clone https://github.com/Shreejan-35/CommandConsole.git
    cd CommandConsole
	echo $USERNAME > etc/userdetails/user.txt
	echo $PASSWORD > etc/userdetails/passwd.txt
else    
    echo "Open any browser and install git, you can directly head over to https://git-scm.com/downloads"
    echo "After downloading and initializing if you want, you can again start this script"
fi
echo "Press enter to stop"
read esc