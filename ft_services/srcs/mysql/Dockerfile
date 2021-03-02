FROM alpine:3.12

EXPOSE 3306

RUN apk update && apk upgrade

RUN apk add --no-cache mariadb mariadb-client mariadb-common

RUN apk add openrc

COPY mariadb-server.cnf /etc/my.cnf.d

COPY wordpress.sql /

COPY phpmyadmin.sql /

COPY mysql.sh /

CMD sh mysql.sh
