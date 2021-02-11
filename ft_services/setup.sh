minikube delete
minikube start
minikube addons enable metallb
eval $(minikube docker-env)
docker build -t n_nginx ./srcs/test/. 
kubectl apply -f ./srcs/yaml/