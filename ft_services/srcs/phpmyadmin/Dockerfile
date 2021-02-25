FROM alpine:3.12
EXPOSE 5000
RUN apk update && apk upgrade

RUN apk add nginx wget

RUN apk add php7 php7-fpm php7-opcache && apk add php7-json php7-mysqli && apk add php7-session \
	&& apk add php7-openssl && apk add php7-mbstring

COPY default.conf /etc/nginx/conf.d/default.conf

COPY phpmyadmin.sh /phpmyadmin.sh

COPY config.inc.php /config.inc.php

CMD sh phpmyadmin.sh