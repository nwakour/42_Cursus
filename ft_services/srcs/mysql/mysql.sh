#cmds for openrc
mysql_install_db --user=mysql --datadir=/var/lib/mysql
mkdir -p /run/openrc
touch /run/openrc/softlevel
openrc reboot
#start the services
rc-update add mariadb default
# /etc/init.d/mariadb setup
rc-service mariadb start
#create user & data base
chown -R mysql: /var/lib/mysql
mysql -u root -e "CREATE USER 'admin'@'%' IDENTIFIED BY 'admin';"
mysql -u root -e "CREATE DATABASE wp_db; use wp_db; source wordpress.sql;"
mysql -u root -e "GRANT ALL PRIVILEGES ON wp_db.* TO admin@'%'; FLUSH PRIVILEGES;"
rc-service mariadb restart
# telegraf start
top