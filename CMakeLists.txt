cmake_minimum_required(VERSION 3.13)
project(ComputacaoGrafica)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(ComputacaoGrafica biblioteca/biblioteca.cpp biblioteca/biblioteca.hpp
        biblioteca/Cone.cpp biblioteca/Cone.hpp biblioteca/Cilindro.cpp biblioteca/Cilindro.hpp biblioteca/Esfera.cpp
        biblioteca/Esfera.hpp biblioteca/Plano.cpp biblioteca/Plano.hpp biblioteca/Objeto.cpp biblioteca/Objeto.hpp
        biblioteca/Cubo.hpp biblioteca/Cubo.cpp Bitmap/Bitmap.cpp Bitmap/Bitmap.hpp
        Bitmap/BitmapCabecalhoInfo.h Bitmap/BitmapCabecalhoArq.h biblioteca/Camera.hpp biblioteca/Camera.cpp
        biblioteca/Cenario.cpp biblioteca/Cenario.hpp TrabalhoGrade.cpp biblioteca/PontoIntersecao.cpp
        biblioteca/PontoIntersecao.hpp biblioteca/Luz.cpp biblioteca/Luz.hpp biblioteca/LuzPontual.cpp biblioteca/LuzPontual.hpp
        biblioteca/Material.cpp biblioteca/Material.hpp biblioteca/LuzSpot.cpp biblioteca/LuzSpot.hpp
        biblioteca/LuzAmbiente.cpp biblioteca/LuzAmbiente.hpp)

target_link_libraries(ComputacaoGrafica -lOpenGL32 -lfreeGLUT -lglu32)
