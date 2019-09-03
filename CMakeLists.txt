# cmake_minimum_required(VERSION <specify CMake version here>)
project(ComputacaoGrafica)

set(CMAKE_CXX_STANDARD 14)

add_executable(ComputacaoGrafica biblioteca/biblioteca.cpp biblioteca/biblioteca.hpp
        biblioteca/Cone.cpp biblioteca/Cone.hpp biblioteca/Cilindro.cpp biblioteca/Cilindro.hpp biblioteca/Esfera.cpp
        biblioteca/Esfera.hpp biblioteca/Plano.cpp biblioteca/Plano.hpp biblioteca/Objeto.cpp biblioteca/Objeto.hpp
        biblioteca/Cubo.hpp biblioteca/Cubo.cpp Bitmap/Bitmap.cpp Bitmap/Bitmap.hpp
        Bitmap/BitmapCabecalhoInfo.h Bitmap/BitmapCabecalhoArq.h biblioteca/Camera.hpp biblioteca/Camera.cpp
        biblioteca/Cenario.cpp biblioteca/Cenario.hpp TrabalhoGrade.cpp biblioteca/PontoIntersecao.cpp
        biblioteca/PontoIntersecao.hpp)
