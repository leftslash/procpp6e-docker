# Debian has the latest stable version of clang supporting c++ modules
FROM debian:latest

# Install the clang/llvm compiler toolchain
RUN apt update && apt install -y clang-19 libc++-19-dev make

# Uncomment the following to install dev tools in the container
# RUN apt install -y vim valgrind file tree less

# Create a non-admin user
RUN useradd -m -U -s /bin/bash todd
USER todd

# Setup workspace
WORKDIR /home/todd/proj
COPY --chown=todd:todd src .

# Starth interactive session
CMD ["/bin/bash"]
