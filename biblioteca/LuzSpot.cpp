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

double LuzSpot::calcularFatorDifuso(PontoIntersecao *p, Objeto *o) {
    VectorXd PlPint = biblioteca::SubtracaoPontos(p->p, posicao, 3);
    VectorXd l = biblioteca::NormalizaVetor(PlPint, 3);
    if(biblioteca::ProdutoEscalar(-l, direcao, 3) > angAbertura){
        return 0 ;
    }

    return biblioteca::ProdutoEscalar(l, o->calcularNormal(p->p), 3);
}

VectorXd LuzSpot::calcularIntensidadeDifusa(PontoIntersecao *p, Objeto *o) {
    VectorXd Id(3);
//  Id[0] = intensidadeRgb[0] * o->material->K[0];
//  Id[1] = intensidadeRgb[1] * o->material->K[1];
//  Id[2] = intensidadeRgb[2] * o->material->K[2];

    Id = Id * calcularFatorDifuso(p, o);
    return Id;
}
