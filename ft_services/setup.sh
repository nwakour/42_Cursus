minikube delete
minikube start
minikube addons enable metallb
eval $(minikube docker-env)
docker build -t nginx_service ./srcs/nginx/.
docker build -t mysql_service ./srcs/mysql/.
docker build -t wordpress_service ./srcs/wordpress/.

kubectl apply -f srcs/yaml/metallb.yaml
kubectl apply -f srcs/yaml/nginx.yaml
kubectl apply -f srcs/yaml/mysql.yaml
kubectl apply -f srcs/yaml/wordpress.yaml