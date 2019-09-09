//
// Created by thais on 06/09/2019.
//

#include "LuzPontual.hpp"

LuzPontual::LuzPontual(float r, float g, float b, double x,double y,double z): Luz(r, g, b){
    posicaoPontual = new Ponto();
    posicaoPontual->x = x;
    posicaoPontual->y = y;
    posicaoPontual->z = z;
}

double LuzPontual::calcularFatorDifuso(PontoIntersecao *p) {
    VectorXd PlPint = biblioteca::SubtracaoPontos(p->p, posicaoPontual, 3);
    VectorXd l = biblioteca::NormalizaVetor(PlPint, 3);
    VectorXd normal = p->objeto->calcularNormal(p->p);
    double fatorDifuso = biblioteca::ProdutoEscalar(normal, l, 3);
    if(fatorDifuso < 0){
        return 0;
    }
    return fatorDifuso;

}

VectorXd LuzPontual::calcularIntensidadeDifusa(PontoIntersecao* p){
    VectorXd Id(3);
    Id[0] = intensidadeRgb[0] * p->objeto->material->Ka[0];
    Id[1] = intensidadeRgb[1] * p->objeto->material->Ka[1];
    Id[2] = intensidadeRgb[2] * p->objeto->material->Ka[2];

    Id = Id * calcularFatorDifuso(p);
    return Id;
}

void LuzPontual::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(posicaoPontual);
}

void LuzPontual::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(posicaoPontual);

}