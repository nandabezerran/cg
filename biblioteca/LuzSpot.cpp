//
// Created by fbeze on 08/09/2019.
//

#include "LuzSpot.hpp"
LuzSpot::LuzSpot(float r, float g, float b, double x, double y, double z): Luz(r, g, b){
    posicao = new Ponto();
    posicao->x = x;
    posicao->y = y;
    posicao->z = z;
}

double LuzSpot::calcularFatorDifuso(PontoIntersecao *p) {
    VectorXd PlPint = biblioteca::SubtracaoPontos(p->p, posicao, 3);
    VectorXd l = biblioteca::NormalizaVetor(PlPint, 3);
    if(biblioteca::ProdutoEscalar(-l, direcao, 3) > angAbertura){
        return 0 ;
    }

    return biblioteca::ProdutoEscalar(l, p->objeto->calcularNormal(p->p), 3);
}

VectorXd LuzSpot::calcularIntensidadeDifusa(PontoIntersecao *p) {
    VectorXd Id(3);
    Id[0] = intensidadeRgb[0] * p->objeto->material->Ka[0];
    Id[1] = intensidadeRgb[1] * p->objeto->material->Ka[1];
    Id[2] = intensidadeRgb[2] * p->objeto->material->Ka[2];

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