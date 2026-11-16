cmake_minimum_required(VERSION 3.15)
project(proyecto_poo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Los .h se buscan en la carpeta include/
include_directories(include)

# Toma automáticamente todos los .cpp de la carpeta src/
file(GLOB SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(proyecto_poo main.cpp ${SOURCES})