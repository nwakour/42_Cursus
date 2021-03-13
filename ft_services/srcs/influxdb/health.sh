#!bin/bash
ps | grep -v grep | grep influxd
return=$?
if [ $return -ne 0 ]; 
then
	exit $return
fi

ps | grep -v grep | grep telegraf
return=$?
if [ $return -ne 0 ]; 
then
	exit $return
fi