FROM alpine:3.12

RUN apk update && apk upgrade

RUN apk add openssl vsftpd

COPY vsftpd.conf /vsftpd.conf

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY vsftpd.crt /etc/ssl/certs/vsftpd.crt

COPY vsftpd.key /etc/ssl/private/vsftpd.key

COPY run.sh /run.sh

COPY health.sh /health.sh

CMD sh run.sh