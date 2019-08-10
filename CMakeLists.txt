# cmake_minimum_required(VERSION <specify CMake version here>)
project(ComputacaoGrafica)

set(CMAKE_CXX_STANDARD 14)

add_executable(ComputacaoGrafica programaprincipal.cpp biblioteca/biblioteca.cpp biblioteca/biblioteca.hpp)
