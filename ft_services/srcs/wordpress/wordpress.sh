wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
cp -r wordpress /var/www/
rm -rf wordpress latest.tar.gz

php-fpm7
mkdir -p /run/nginx
nginx -g "daemon off;"