# procpp6e-docker
A Dockerfile and supporting Makefiles to build a Linux development environment for compiling C++ code.

### Motivation
This repo was created while reading _Professional C++, 6th Edition_ by Marc Gregoire.  Many of his examples utilize features from the C++23 version of C++.  Unfortunately, some of the features like modules and "import std" do not compile correctly with the current version of GCC (14.2 at this writing) nor the version of Clang that is pre-installed on macOS (version 16.0).  This should be cleared up with GCC 15, but that's not due until April/May 2025.

Therefore, in order to compile the examples from the book on Linux or macOS, it is necessary to use the latest version of Clang (19.1.4 at this writing).  Rather than trying to install Clang 19.1.4 on your own machine and trying to figure out the correct flags for Clang, etc., the Dockerfile contained here will do just that.  

Also included are Makefiles to manage the creation/cleanup of the docker image and container as well as sample code from Chapter 1 of the book with a Makefile that provides the correct flags for Clang to compile C++ code using modules.  Apologies for not using Cmake, but the intent here is to keep things relatively simple with less moving parts.

### Instructions
The instructions below describe a two step process:
1. Create a docker image and container and run it to enter the development environment.
2. Compile C++ source code using modules and run the executable as proof it works.

#### 1. Creating the Docker Image
Use the following commands to clone the repository, build the image and execute it.  Note that the construction of the docker image can take a few minutes since it has to download the Debian base image and then install the C++ compiler toolchain.  Also note that these commands require that you have `git`, `docker` and `make` installed.  
```
git clone https://github.com/leftslash/procpp6e-docker
cd procpp6e-docker
make
```
At this point, you should see a prompt like `todd@82d5b262edd9:~/proj$ ` From here you can skip to Step 2 to compile the C++ code.  If you want to exit the container, simply press `Ctrl-D` or type `exit`.

To re-enter the docker image to continue testing:
```
make start
```
To remove the docker container and image:
```
make cleanall
```

#### 2. Compiling C+ code
Once you are at the prompt which looks like: `todd@82d5b262edd9:~/proj$ `, you can use the following  instructions to build and execute one of the first examples from the book:
```
make
./Employee
```
This is a very primitive, in-source build process.  It is not the way it would be done in real life, but is sufficient for demonstrating how to get C++ module code working.  To remove all the build artifacts, you can use the following command:
```
make cleanall
```
