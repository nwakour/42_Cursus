FROM alpine:3.12

EXPOSE 3000

RUN apk update && apk upgrade

RUN apk add libc6-compat

RUN apk add wget

COPY grafana.sh /
COPY grafana.db /

CMD sh grafana.sh
