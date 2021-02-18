FROM alpine:3.12
RUN apk update && apk upgrade
#install nginx
RUN apk add nginx
#install open-ssl and open-ssh
RUN apk add openssl openssh
#copy the default
COPY default.conf ./etc/nginx/conf.d/default.conf
#copy the cert.key
COPY nginx-selfsigned.crt ./etc/ssl/certs/nginx-selfsigned.crt
#copy the cert.pem
COPY nginx-selfsigned.key ./etc/ssl/private/nginx-selfsigned.key
#copy the nginx.sh
COPY nginx.sh ./nginx.sh
COPY health.sh /
#run nginx
#RUN echo "<h1 style='color : red;padding-left : 45vw'>Hello world!</h1>" > /var/www/localhost/htdocs/index.html;
CMD sh nginx.sh
EXPOSE 80 443 22