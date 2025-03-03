# Makefile
#
# Type "make" to create the docker image and container and start
# the container with a command line within the container to compile
# source code. When finished, simply exit via "exit"
#
# Use "make start" to return to the container to do more
# compilation, development, etc.
#
# Finally, use "make cleanall" to remove the container and image.
#

image			:= clang:latest
container	:= clang

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
