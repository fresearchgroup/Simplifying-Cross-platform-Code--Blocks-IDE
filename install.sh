#!/bin/sh

sudo apt-get install libwxgtk2.8-dev
sudo apt-get install hunspell
sudo apt-get install libhunspell-dev
sudo apt-get install gamin
sudo apt-get install libgamin-dev
sudo apt-get install libtool
sudo apt-get install libgtk2.0-dev

DIRECTORY="$HOME/Downloads/wxGTK-2.8.12"


if [ ! -d "$DIRECTORY" ]
 then
  wget -P $HOME/Downloads https://sourceforge.net/projects/wxwindows/files/2.8.12/wxGTK-2.8.12.tar.gz
  tar zxf $HOME/Downloads/wxGTK-2.8.12.tar.gz -C /$HOME/Downloads
else
  echo "wxGTK already installed.."
fi

APP_DIR=`dirname "$0"`
APP_DIR=`( cd "$APP_DIR" && pwd )`
export LD_LIBRARY_PATH=$APP_DIR:$LD_LIBRARY_PATH
sudo mkdir /usr/share/simpleblocks
sudo mkdir /usr/share/simpleblocks/share
sudo cp -r share/* /usr/share/simpleblocks/share
sudo cp cb_console_runner /usr/share/simpleblocks
sudo cp codeblocks /usr/share/simpleblocks
sudo cp libcodeblocks.so /usr/share/simpleblocks
sudo cp libwxpropgrid.so /usr/share/simpleblocks
sudo cp run.sh /usr/share/simpleblocks
sudo cp uninstall.sh /usr/share/simpleblocks
sudo cp Simple__Blocks.desktop /usr/share/applications
sudo chmod 777 -R /usr/share/simpleblocks
sudo mkdir $HOME/Documents/"Sample Programs"
sudo cp -r share/codeblocks/"Sample Programs"/* $HOME/Documents/"Sample Programs"
sudo chmod 777 -R $HOME/Documents/"Sample Programs"
