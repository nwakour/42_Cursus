#! /bin/sh

ps | grep -v grep | grep mysqld
return=$?
if [ $return -ne 0 ]; 
then
	exit $return
fi