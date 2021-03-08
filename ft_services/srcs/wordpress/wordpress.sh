#!bin/bash
wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
cp -r wordpress var/www/
mv wp-config.php var/www/wordpress
rm -rf wordpress latest.tar.gz

php-fpm7
mkdir -p run/nginx
nginx -g "daemon off;"