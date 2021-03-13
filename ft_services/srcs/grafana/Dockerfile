FROM alpine:3.12

EXPOSE 3000

RUN apk update && apk upgrade

RUN apk add libc6-compat

RUN apk add wget

RUN wget https://dl.grafana.com/oss/release/grafana-7.4.3.linux-amd64.tar.gz

RUN tar -zxvf grafana-7.4.3.linux-amd64.tar.gz
RUN mv grafana-7.4.3 grafana
COPY grafana.sh /
COPY grafana.db /grafana/data/grafana.db

CMD sh grafana.sh
