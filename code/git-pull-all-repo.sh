#!/usr/bin/env bash
# This script will pull request any git you clone in your home directory
# change your folder location that contain collection of git you clone 
# e.g your git in /home/user/project
#   WORKDIR=$HOME/project

WORKDIR=$HOME
cd $WORKDIR
find . -type d -name .git -exec git --git-dir={} --work-tree=$WORKDIR/{}/.. pull origin master \;
