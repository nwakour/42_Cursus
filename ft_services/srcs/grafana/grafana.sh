wget https://dl.grafana.com/oss/release/grafana-7.4.3.linux-amd64.tar.gz

tar -zxvf grafana-7.4.3.linux-amd64.tar.gz
cp grafana.db grafana-7.4.3/data/
cd grafana-7.4.3/bin

./grafana-server