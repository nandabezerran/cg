#include "LuzAmbiente.hpp"

LuzAmbiente::LuzAmbiente(float r, float g, float b){
    intensidadeRgb = Vetor(r, g, b);
}

Vetor LuzAmbiente::calcularIntensidadeAmbiente(const PontoIntersecao& p){
    Vetor Ia;
    Ia.x = intensidadeRgb.x * p.objeto->material->Ka[0];
    Ia.y = intensidadeRgb.y * p.objeto->material->Ka[1];
    Ia.z = intensidadeRgb.z * p.objeto->material->Ka[2];
    return Ia;
}