cmake_minimum_required(VERSION 3.14)
project(unidad_1_matriz_dispersa_mauricio_rodriguez)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(unidad_1_matriz_dispersa_mauricio_rodriguez
        main.cpp
        MatrizDispersa.cpp
        MatrizDispersa.h)
