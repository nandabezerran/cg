//
// Created by thais on 06/09/2019.
//

#include "LuzPontual.hpp"

LuzPontual::LuzPontual(int r, int g, int b, int x, int y, int z): Luz(r, g, b){
    posicaoPontual = new Ponto();
    posicaoPontual->x = x;
    posicaoPontual->y = y;
    posicaoPontual->z = z;
}

double LuzPontual::calcularFatorDifuso(PontoIntersecao *p, Objeto* o) {
    VectorXd PlPint = biblioteca::SubtracaoPontos(p->p, posicaoPontual, 3);
    VectorXd l = biblioteca::NormalizaVetor(PlPint, 3);
//    VectorXd normal = o->calcularNormal(p);
//    double fatorDifuso = biblioteca::ProdutoEscalar(normal, l, 3);
//    return fatorDifuso;
    double x = 2;
    return x;
}

VectorXd LuzPontual::calcularIntensidadeDifusa(PontoIntersecao* p, Objeto* o){
    VectorXd Id(3);
//    Id[0] = intensidadeRgb[0] * o->material->K[0];
//    Id[1] = intensidadeRgb[1] * o->material->K[1];
//    Id[2] = intensidadeRgb[2] * o->material->K[2];

    Id = Id * calcularFatorDifuso(p, o);
    return Id;
}