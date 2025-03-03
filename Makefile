# Makefile

image     := clang:latest
container := clang

default: image

image:
	docker build -t $(image) .
	docker run -it --name $(container) $(image)

start:
	docker start -ai $(container)

list:
	docker images
	@echo
	docker ps -a

clean:
	-docker rm $(container)

cleanall: clean
	-docker rmi $(image)

# vim: sw=3:ts=2:noexpandtab
