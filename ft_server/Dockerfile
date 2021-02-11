FROM debian:buster

EXPOSE 80 443

RUN apt-get -qq -y update

RUN apt-get install -f -y -qq nginx wget lsb-release gnupg php7.3-fpm php7.3-mysql php7.3-mbstring

COPY srcs/default /etc/nginx/sites-available/

COPY srcs/certificate.crt /etc/nginx/ssl/

COPY srcs/wp-config.php /var/www/html/

COPY srcs/wordpress.sql /wordpress.sql

COPY srcs/key.key /etc/nginx/ssl/

COPY srcs/config.inc.php /config.inc.php

COPY srcs/self-signed.conf /etc/nginx/snippets/

COPY srcs/ssl-params.conf /etc/nginx/snippets/

COPY srcs/dhparam.pem /etc/nginx/

COPY srcs/script.sh /script.sh

RUN ["/script.sh"]

COPY srcs/start.sh /start.sh

CMD sh start.sh