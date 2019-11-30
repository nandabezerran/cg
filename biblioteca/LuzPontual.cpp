//
// Created by thais on 06/09/2019.
//

#include <c++/cmath>
#include "LuzPontual.hpp"
#include "Cluster.h"

LuzPontual::LuzPontual(float r, float g, float b, double x,double y,double z): Luz(r, g, b){
    posicaoPontual = new Ponto();
    posicaoPontual->x = x;
    posicaoPontual->y = y;
    posicaoPontual->z = z;
}

double LuzPontual::calcularFatorDifuso(const PontoIntersecao& p) {
    Vetor l = biblioteca::NormalizaVetor(biblioteca::SubtracaoPontos(*p.p, *posicaoPontual));
    Vetor normal = p.objeto->calcularNormal(p.p);

    double fatorDifuso = biblioteca::ProdutoEscalar(normal, l);
    if(fatorDifuso < 0){
        return 0;
    }
    return fatorDifuso;

}

Vetor LuzPontual::calcularIntensidadeDifusa(const PontoIntersecao& p){
    Vetor Id;
    Id.x = intensidadeRgb.x * p.objeto->material->Kd[0];
    Id.y = intensidadeRgb.y * p.objeto->material->Kd[1];
    Id.z = intensidadeRgb.z * p.objeto->material->Kd[2];

    Id = Id * calcularFatorDifuso(p);
    return Id;
}

void LuzPontual::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(posicaoPontual);
}

void LuzPontual::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(posicaoPontual);

}

double LuzPontual::calcularFatorEspecular(const PontoIntersecao& p) {
    Vetor PlPint = biblioteca::SubtracaoPontos(*p.p, *posicaoPontual);
    Vetor l = biblioteca::NormalizaVetor(PlPint);

    Vetor normal = p.objeto->calcularNormal(p.p);

    Vetor r = ((biblioteca::ProdutoEscalar(l, normal)) * 2 * normal) - l;
    Vetor v = biblioteca::SubtracaoPontos(*p.p, Ponto{0, 0, 0});

    double fatorEspecular = biblioteca::ProdutoEscalar(biblioteca::NormalizaVetor(v),
        biblioteca::NormalizaVetor(r));

    if(fatorEspecular < 0){
        return 0;
    }

    return fatorEspecular;

}

Vetor LuzPontual::calcularIntensidadeEspecular(const PontoIntersecao& p) {
    Vetor Id;
    Id.x = intensidadeRgb.x * p.objeto->material->Ks[0];
    Id.y = intensidadeRgb.y * p.objeto->material->Ks[1];
    Id.z = intensidadeRgb.z * p.objeto->material->Ks[2];

    Id = Id * pow(calcularFatorEspecular(p), p.objeto->material->m);
    return Id;
}
