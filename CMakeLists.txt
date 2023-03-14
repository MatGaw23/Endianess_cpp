cmake_minimum_required(VERSION 3.16)

# Prerequirement:  
# I am running this on Ubuntu 20.04
# sudo apt update && sudo apt upgrade -y
# sudo apt install build-essential
# sudo apt install cmake

project(EndianessTest LANGUAGES C CXX)

# set(CMAKE_CXX_COMPILER s390x-linux-gnu-g++) // you need to install crosscompiler to do this: https://command-not-found.com/s390x-linux-gnu-gcc-7
add_subdirectory(app)
add_subdirectory(tests)