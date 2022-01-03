echo "UPGRADE SIMULATOR"
echo "Do you have git cli installed(y/n): "
read gitDownload
read -p "USERNAME: " USERNAME
read -sp "PASSWORD: " PASSWORD
echo
if [ "$gitDownload" == "y" ];
then
    cd ..
    
    rm -rf CommandConsole
    git clone https://github.com/Shreejan-35/CommandConsole.git
    #gh repo clone Shreejan-35/CommandConsole
else    
    echo "Open any browser and install git, you can directly head over to https://git-scm.com/downloads"
    echo "After downloading and initializing if you want, you can again start this script"
fi
echo
echo "Press enter to stop"
read esc
