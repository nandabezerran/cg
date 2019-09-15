#include "LuzRemota.hpp"
//# define M_PI 3.14159265358979323846  /* pi */

LuzRemota::LuzRemota(int r, int g, int b, Vetor Dr): direcao(Dr), Luz(r, g, b){
    direcao = biblioteca::NormalizaVetor(direcao);
}
double LuzRemota::calcularFatorDifuso(PontoIntersecao *p) {
    Vetor normal = p->objeto->calcularNormal(p->p);
    double fatorDifuso = biblioteca::ProdutoEscalar(normal, -direcao);
    if(fatorDifuso < 0){
        return 0;
    }
    return fatorDifuso;

}

Vetor LuzRemota::calcularIntensidadeDifusa(PontoIntersecao* p){
    Vetor Id;
    Id.x = intensidadeRgb.x * p->objeto->material->Kd[0];
    Id.y = intensidadeRgb.y * p->objeto->material->Kd[1];
    Id.z = intensidadeRgb.z * p->objeto->material->Kd[2];

    return Id;

}

void LuzRemota::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(direcao);
}

void LuzRemota::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(direcao);
}

double LuzRemota::calcularFatorEspecular(PontoIntersecao *p) {
    Vetor normal = p->objeto->calcularNormal(p->p);
    Vetor l = biblioteca::NormalizaVetor(-direcao);

    Vetor r = (2 * ((biblioteca::ProdutoEscalar(l, normal)))*normal) - l;
    Vetor v = biblioteca::SubtracaoPontos(*p->p, Ponto{0,0,0});
    double fatorEspecular = biblioteca::ProdutoEscalar(
        biblioteca::NormalizaVetor(v),
        biblioteca::NormalizaVetor(r));

    if(fatorEspecular < 0){
        return 0;
    }

    return fatorEspecular;

}

Vetor LuzRemota::calcularIntensidadeEspecular(PontoIntersecao *p) {
    Vetor Id;
    Id.x = intensidadeRgb.x * p->objeto->material->Ks[0];
    Id.y = intensidadeRgb.y * p->objeto->material->Ks[1];
    Id.z = intensidadeRgb.z * p->objeto->material->Ks[2];

    Id = Id * calcularFatorEspecular(p);
    return Id;
}

