FROM alpine:3.12
EXPOSE 8086
RUN apk update && apk upgrade

#RUN apk add openrc
RUN apk add libc6-compat
RUN apk add influxdb --no-cache  --repository http://dl-2.alpinelinux.org/alpine/edge/community
RUN apk add telegraf --no-cache --repository http://dl-2.alpinelinux.org/alpine/edge/community

COPY influxdb.conf /influxdb.conf

COPY telegraf.conf /telegraf.conf

COPY influxdb.sh /influxdb.sh

CMD sh influxdb.sh