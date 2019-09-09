//
// Created by thais on 06/09/2019.
//

#include "Luz.hpp"


Luz::Luz(float r, float g, float b) {
    VectorXd aux(3);
    intensidadeRgb = aux;
    intensidadeRgb[0] = r;
    intensidadeRgb[1] = g;
    intensidadeRgb[2] = b;
}