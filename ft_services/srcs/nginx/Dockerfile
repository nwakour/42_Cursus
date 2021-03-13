FROM alpine:3.12
RUN apk update && apk upgrade

RUN apk add nginx

RUN apk add openssl openssh

COPY default.conf ./etc/nginx/conf.d/default.conf

COPY nginx-selfsigned.crt ./etc/ssl/certs/nginx-selfsigned.crt

COPY nginx-selfsigned.key ./etc/ssl/private/nginx-selfsigned.key

COPY nginx.sh ./nginx.sh

RUN echo "<h1 style='color : green;padding-left : 45vw'>ALLOHA!</h1>" > /var/www/localhost/htdocs/index.html;

COPY health.sh /

CMD sh nginx.sh

EXPOSE 80 443 22