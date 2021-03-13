#!bin/bash
cp vsftpd.conf /etc/vsftpd/vsftpd.conf
cp vsftpd.crt /etc/ssl/certs/vsftpd.crt
cp vsftpd.key /etc/ssl/private/vsftpd.key
adduser -D admin
echo "admin:admin" | chpasswd
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf