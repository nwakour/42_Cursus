FROM alpine:3.12
EXPOSE 8086
RUN apk update && apk upgrade

RUN apk add wget

RUN apk add influxdb


COPY influxdb.sh /influxdb.sh


CMD sh influxdb.sh