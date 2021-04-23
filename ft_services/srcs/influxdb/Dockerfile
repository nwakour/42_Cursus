FROM alpine:3.12
EXPOSE 8086

RUN apk update && apk upgrade
RUN apk add influxdb --no-cache --repository http://dl-2.alpinelinux.org/alpine/edge/community
RUN apk add telegraf --no-cache --repository http://dl-2.alpinelinux.org/alpine/edge/community

COPY telegraf.conf /etc
COPY health.sh /
COPY run.sh /
ENTRYPOINT sh run.sh
