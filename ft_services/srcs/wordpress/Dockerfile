FROM alpine:3.12
EXPOSE 5050
RUN apk update && apk upgrade

RUN apk add nginx wget

RUN apk add php7 php7-fpm php7-opcache && apk add php7-json php7-mysqli && apk add php7-session \
	&& apk add php7-openssl && apk add php7-mbstring

COPY default.conf /etc/nginx/conf.d/default.conf

COPY wordpress.sh /wordpress.sh

COPY wp-config.php /wp-config.php

COPY health.sh /

CMD sh wordpress.sh