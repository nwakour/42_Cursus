wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvzf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages /var/www/phpmyadmin
mv config.inc.php /var/www/phpmyadmin
chown -R www-data:www-data /var/www/phpmyadmin
rm phpMyAdmin-5.0.2-all-languages.tar.gz

php-fpm7
chmod 777 /var/www/phpmyadmin/tmp
mkdir -p /run/nginx
nginx -g "daemon off;"