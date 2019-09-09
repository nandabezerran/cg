#include "LuzRemota.hpp"
# define M_PI 3.14159265358979323846  /* pi */

LuzRemota::LuzRemota(int r, int g, int b, VectorXd Dr): direcao(Dr), Luz(r, g, b){
    direcao = biblioteca::NormalizaVetor(direcao, 3);
}
double LuzRemota::calcularFatorDifuso(PontoIntersecao *p) {
    VectorXd normal = p->objeto->calcularNormal(p->p);
    double fatorDifuso = (biblioteca::ProdutoEscalar(normal, -direcao, 3));
    if(fatorDifuso < 0){
        return 0;
    }
    return fatorDifuso;

}

VectorXd LuzRemota::calcularIntensidadeDifusa(PontoIntersecao* p){
    VectorXd Id(3);
    Id[0] = intensidadeRgb[0] * p->objeto->material->Ka[0];
    Id[1] = intensidadeRgb[1] * p->objeto->material->Ka[1];
    Id[2] = intensidadeRgb[2] * p->objeto->material->Ka[2];

    return Id;

}

void LuzRemota::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(direcao);
}

void LuzRemota::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(direcao);
}

