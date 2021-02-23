minikube delete
minikube start
minikube addons enable metallb
eval $(minikube docker-env)
docker build -t nginx_service ./srcs/nginx/.
docker build -t mysql_service ./srcs/mysql/.

kubectl apply -f srcs/yaml/metallb.yaml
kubectl apply -f srcs/yaml/nginx.yaml
kubectl apply -f srcs/yaml/mysql.yaml