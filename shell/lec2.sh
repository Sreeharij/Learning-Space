#! /bin/bash

#this is a comment

echo $BASH
echo $HOME
echo $BASH_VERSION
echo $PWD

intro_message="Hello From the Other Side"

echo $intro_messagea

read -p "Username: " username
read -sp "Password: " passwd
echo "Your username is $username and password is $passwd"

echo "Enter names: "
read -a names
echo ${names[2]}
echo $names

echo "Enter stuff to be stored in REPLY variable: "
read
echo $REPLY