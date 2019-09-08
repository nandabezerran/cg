#include "LuzAmbiente.hpp"

LuzAmbiente::LuzAmbiente(float r, float g, float b): Luz(r, g, b){
}

VectorXd LuzAmbiente::calcularIntensidadeAmbiente(PontoIntersecao* p){
    VectorXd Ia(3);
//    Ia[0] = intensidadeRgb[0] * p->o->rgb[0];
//    Ia[1] = intensidadeRgb[1] * p->o->rgb[1];
//    Ia[2] = intensidadeRgb[2] * p->o->rgb[2];
    return Ia;
}