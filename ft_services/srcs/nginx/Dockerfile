FROM alpine:3.12
EXPOSE 80 443 22
RUN apk update && apk upgrade

RUN apk add  --no-cache nginx openssl openssh
RUN apk add openrc --no-cache

COPY default.conf ./etc/nginx/conf.d/default.conf

COPY nginx-selfsigned.crt ./etc/ssl/certs/nginx-selfsigned.crt

COPY nginx-selfsigned.key ./etc/ssl/private/nginx-selfsigned.key

COPY run.sh /run.sh

RUN echo "<h1 style='color : green;padding-left : 45vw'>100%!</h1>" > /var/www/localhost/htdocs/index.html;

COPY health.sh /

CMD sh run.sh