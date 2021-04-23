FROM alpine:3.12
EXPOSE 3000

RUN apk update && apk upgrade
RUN apk add libc6-compat
RUN wget https://dl.grafana.com/oss/release/grafana-7.4.3.linux-amd64.tar.gz
RUN tar -zxvf grafana-7.4.3.linux-amd64.tar.gz

COPY grafana.db /grafana-7.4.3/data/
COPY health.sh /
COPY run.sh /
RUN chmod 777 run.sh
ENTRYPOINT sh run.sh