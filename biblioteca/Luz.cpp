//
// Created by thais on 06/09/2019.
//

#include "Luz.hpp"


Luz::Luz(float r, float g, float b) {
    intensidadeRgb = Vetor(r, g, b);
    estado = true;
}