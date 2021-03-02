FROM alpine:3.12

RUN apk update && apk upgrade

RUN apk add openssl

RUN apk add vsftpd

COPY vsftpd.conf /vsftpd.conf

COPY vsftpd.crt /vsftpd.crt
COPY vsftpd.key /vsftpd.key

COPY ftps.sh /ftps.sh

CMD sh ftps.sh