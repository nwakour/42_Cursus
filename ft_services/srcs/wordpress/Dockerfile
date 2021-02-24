FROM alpine:3.12
EXPOSE 5050
RUN apk update && apk upgrade

RUN apk add nginx wget

RUN apk add php7 php7-fpm php7-mysqli php7-mbstring

COPY default.conf /etc/nginx/conf.d/default.conf

COPY wordpress.sh /wordpress.sh

CMD sh wordpress.sh

COPY wp-config.php /var/www/wordpress/