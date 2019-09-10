//
// Created by fbeze on 08/09/2019.
//

#include "LuzSpot.hpp"
LuzSpot::LuzSpot(float r, float g, float b, double x, double y, double z,VectorXd pDir,
        float pAng): direcao(pDir), angAbertura(pAng), Luz(r, g, b){
    posicao = new Ponto();
    posicao->x = x;
    posicao->y = y;
    posicao->z = z;
}

double LuzSpot::calcularFatorDifuso(PontoIntersecao *p) {
    VectorXd PlPint = biblioteca::SubtracaoPontos(p->p, posicao, 3);
    VectorXd l = biblioteca::NormalizaVetor(PlPint, 3);
    direcao = biblioteca::NormalizaVetor(direcao,3);
    if(biblioteca::ProdutoEscalar(-l, direcao, 3) > cos(angAbertura)){
        return 0 ;
    }
    double fatorDifuso = biblioteca::ProdutoEscalar(l, p->objeto->calcularNormal(p->p), 3);
    if(fatorDifuso < 0){
        return 0;
    }
    return fatorDifuso;
}

VectorXd LuzSpot::calcularIntensidadeDifusa(PontoIntersecao *p) {
    VectorXd Id(3);
    Id[0] = intensidadeRgb[0] * p->objeto->material->Kd[0];
    Id[1] = intensidadeRgb[1] * p->objeto->material->Kd[1];
    Id[2] = intensidadeRgb[2] * p->objeto->material->Kd[2];

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

double LuzSpot::calcularFatorEspecular(PontoIntersecao *p) {
    VectorXd PlPint = biblioteca::SubtracaoPontos(p->p, posicao, 3);
    VectorXd l = biblioteca::NormalizaVetor(PlPint, 3);

    VectorXd normal = p->objeto->calcularNormal(p->p);

    VectorXd r = (2 * ((biblioteca::ProdutoEscalar(l, normal,3))*normal)) - l;
    VectorXd v = biblioteca::SubtracaoPontos(p->p, biblioteca::CriarPonto(0,0,0), 3);

    if(biblioteca::ProdutoEscalar(-l, direcao, 3) > cos(angAbertura)){
        return 0 ;
    }
    double fatorEspecular = biblioteca::ProdutoEscalar(v, r, 3);
    if(fatorEspecular < 0){
        return 0;
    }
    return fatorEspecular;

}

VectorXd LuzSpot::calcularIntensidadeEspecular(PontoIntersecao *p) {
    VectorXd Id(3);
    Id[0] = intensidadeRgb[0] * p->objeto->material->Ks[0];
    Id[1] = intensidadeRgb[1] * p->objeto->material->Ks[1];
    Id[2] = intensidadeRgb[2] * p->objeto->material->Ks[2];

    Id = Id * pow(calcularFatorEspecular(p), p->objeto->material->m);
    return Id;
}