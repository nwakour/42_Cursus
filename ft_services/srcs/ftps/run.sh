#!bin/bash
adduser -D 'admin'
echo "admin:admin" | chpasswd
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf