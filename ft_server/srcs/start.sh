#! /bin/sh
chown -R mysql: /var/lib/mysql
service mysql start
service php7.3-fpm start
service nginx start
exec /bin/bash