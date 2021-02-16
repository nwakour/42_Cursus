minikube delete
minikube start
minikube addons enable metallb
eval $(minikube docker-env)
docker build -t nginx_service ./srcs/test/srcs/.
kubectl apply -f metallb.yaml
kubectl apply -f nginx.yaml