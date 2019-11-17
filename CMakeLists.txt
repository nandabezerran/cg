cmake_minimum_required(VERSION 3.13)
project(opengl)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(opengl main.cpp)

target_link_libraries(opengl -lopengl32 -lglut -lglew -lglu32)



