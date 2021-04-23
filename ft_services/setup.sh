#!bin/bash
minikube delete
minikube start --driver virtualbox
minikube addons enable metallb
eval $(minikube docker-env)
docker build -t ftps_service ./srcs/ftps/.
docker build -t influxdb_service ./srcs/influxdb/.
docker build -t nginx_service ./srcs/nginx/.
docker build -t mysql_service ./srcs/mysql/.
docker build -t wordpress_service ./srcs/wordpress/.
docker build -t phpmyadmin_service ./srcs/phpmyadmin/.
docker build -t grafana_service ./srcs/grafana/.



kubectl apply -f srcs/yaml/ftps.yaml
kubectl apply -f srcs/yaml/influxdb.yaml
kubectl apply -f srcs/yaml/metallb.yaml
kubectl apply -f srcs/yaml/nginx.yaml
kubectl apply -f srcs/yaml/mysql.yaml
kubectl apply -f srcs/yaml/wordpress.yaml
kubectl apply -f srcs/yaml/phpmyadmin.yaml
kubectl apply -f srcs/yaml/grafana.yaml

// create more user