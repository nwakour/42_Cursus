#!bin/bash
mkdir -p /etc/telegraf
cp telegraf.conf /etc/telegraf
#cp influxdb.conf /etc/

# mkdir -p /run/openrc
# touch /run/openrc/softlevel
# openrc reboot
# rc-service telegraf start
# rc-service influxdb start
mkdir -p /var/run/
touch  /var/run/utmp
nohup influxd run &
influx -execute "CREATE DATABASE telegraf"
influx -execute "CREATE USER admin WITH PASSWORD 'admin' WITH ALL PRIVILEGES"
telegraf