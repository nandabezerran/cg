cmake_minimum_required(VERSION 3.13)
project(ComputacaoGrafica)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(ComputacaoGrafica main.cpp)

target_link_libraries(ComputacaoGrafica -lopengl32 -lfreeglut -lglu32)



