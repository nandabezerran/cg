#include "LuzAmbiente.hpp"

LuzAmbiente::LuzAmbiente(float r, float g, float b){
    VectorXd aux(3);
    intensidadeRgb = aux;
    intensidadeRgb[0] = r;
    intensidadeRgb[1] = g;
    intensidadeRgb[2] = b;
}

VectorXd LuzAmbiente::calcularIntensidadeAmbiente(PontoIntersecao* p){
    VectorXd Ia(3);
    Ia[0] = intensidadeRgb[0] * p->objeto->material->Ka[0];
    Ia[1] = intensidadeRgb[1] * p->objeto->material->Ka[1];
    Ia[2] = intensidadeRgb[2] * p->objeto->material->Ka[2];
    return Ia;
}