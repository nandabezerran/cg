#include "LuzRemota.hpp"

LuzRemota::LuzRemota(int r, int g, int b): Luz(r, g, b){
}

VectorXd LuzRemota::calcularIntensidadeRemota(PontoIntersecao* p){
    VectorXd Ir(3);
//    Id[0] = intensidadeRgb[0] * p->o->rgb[0];
//    Id[1] = intensidadeRgb[1] * p->o->rgb[1];
//    Id[2] = intensidadeRgb[2] * p->o->rgb[2];

    return Ir;
}