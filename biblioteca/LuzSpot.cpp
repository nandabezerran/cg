//
// Created by fbeze on 08/09/2019.
//

#include <c++/cmath>
#include "LuzSpot.hpp"

LuzSpot::LuzSpot(float r, float g, float b, double x, double y, double z, Vetor pDir,
        float pAng): direcao(pDir), angAbertura(pAng), Luz(r, g, b){
    posicao = new Ponto();
    posicao->x = x;
    posicao->y = y;
    posicao->z = z;
    direcao = biblioteca::NormalizaVetor(direcao);
}

double LuzSpot::calcularFatorDifuso(const PontoIntersecao& p) {
    Vetor l = biblioteca::NormalizaVetor(biblioteca::SubtracaoPontos(*p.p, *posicao));
    if(biblioteca::ProdutoEscalar(-l, direcao) > cos(angAbertura)){
        return 0 ;
    }
    double fatorDifuso = biblioteca::ProdutoEscalar(l, p.objeto->calcularNormal(p.p));
    if(fatorDifuso < 0){
        return 0;
    }
    return fatorDifuso;
}

Vetor LuzSpot::calcularIntensidadeDifusa(const PontoIntersecao& p) {
    Vetor Id;
    Id.x = intensidadeRgb.x * p.objeto->material->Kd[0];
    Id.y = intensidadeRgb.y * p.objeto->material->Kd[1];
    Id.z = intensidadeRgb.z * p.objeto->material->Kd[2];

    Id = Id * calcularFatorDifuso(p);
    return Id;
}

void LuzSpot::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(direcao);
    camera->mudarMundoCamera(posicao);
}

void LuzSpot::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(direcao);
    camera->mudarCameraMundo(posicao);
}

double LuzSpot::calcularFatorEspecular(const PontoIntersecao& p) {
    Vetor l = biblioteca::NormalizaVetor(biblioteca::SubtracaoPontos(*p.p, *posicao));

    Vetor normal = p.objeto->calcularNormal(p.p);

    Vetor r = (2 * ((biblioteca::ProdutoEscalar(l, normal))*normal)) - l;
    Vetor v = biblioteca::SubtracaoPontos(*p.p, Ponto{0,0,0});

    if(biblioteca::ProdutoEscalar(-l, direcao) > cos(angAbertura)){
        return 0 ;
    }
    double fatorEspecular = biblioteca::ProdutoEscalar(v, r);
    if(fatorEspecular < 0){
        return 0;
    }
    return fatorEspecular;

}

Vetor LuzSpot::calcularIntensidadeEspecular(const PontoIntersecao& p) {
    Vetor Is;
    Is.x = intensidadeRgb.x * p.objeto->material->Ks[0];
    Is.y = intensidadeRgb.y * p.objeto->material->Ks[1];
    Is.z = intensidadeRgb.z * p.objeto->material->Ks[2];

    Is = Is * pow(calcularFatorEspecular(p), p.objeto->material->m);
    return Is;
}