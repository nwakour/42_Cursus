#!bin/bash
usr/sbin/influxd&
influx -execute "CREATE USER admin WITH PASSWORD 'admin' WITH ALL PRIVILEGES"
influx -execute "CREATE DATABASE influxdb"
telegraf --config /etc/telegraf.conf
top