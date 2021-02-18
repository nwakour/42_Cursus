minikube delete
minikube start
minikube addons enable metallb
eval $(minikube docker-env)
docker build -t nginx_service ./srcs/nginx/.
kubectl apply -f yaml/metallb.yaml
kubectl apply -f yaml/nginx.yaml