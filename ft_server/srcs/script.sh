#!/bin/sh
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-english.tar.gz
tar -xvzf phpMyAdmin-4.9.2-english.tar.gz
mv phpMyAdmin-4.9.2-english /var/www/html/phpmyadmin
chown -R www-data:www-data /var/www/html/phpmyadmin
mv config.inc.php /var/www/html/phpmyadmin
rm phpMyAdmin-4.9.2-english.tar.gz

apt-get -qq -y update
apt-get install -qq -y default-mysql-server
chown -R mysql: /var/lib/mysql
service mysql start
mysql -u root -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';"
mysql -u root -e "CREATE DATABASE wordpress; use wordpress; source wordpress.sql;"
mysql -u root -e "GRANT ALL PRIVILEGES ON wordpress.* TO admin@localhost; FLUSH PRIVILEGES;"

wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
chown -R www-data:www-data wordpress/
usermod -a -G www-data www-data
mv wordpress/* /var/www/html/
rm -rf wordpress latest.tar.gz