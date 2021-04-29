#!bin/bash
mysql_install_db --user=mysql --datadir=/var/lib/mysql
mkdir -p /run/openrc
touch /run/openrc/softlevel
openrc reboot

rc-update add mariadb default

rc-service mariadb start

chown -R mysql: /var/lib/mysql
mysql -u root -e "CREATE USER 'admin'@'%' IDENTIFIED BY 'admin';"
mysql -u root -e "CREATE DATABASE wp_db; use wp_db; source wordpress.sql;"
mysql -u root -e "CREATE DATABASE phpmyadmin; use phpmyadmin; source phpmyadmin.sql;"
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO admin@'%'; FLUSH PRIVILEGES;"
rc-service mariadb restart
top