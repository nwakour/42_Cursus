#!bin/bash
eval $(minikube docker-env)
kubectl delete -f srcs/yaml/$1.yaml
docker build -t $1_service ./srcs/$1/.
kubectl apply -f srcs/yaml/$1.yaml