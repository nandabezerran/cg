//
// Created by fbeze on 24/08/2019.
//

#include <c++/cmath>
#include "Esfera.hpp"
#include "Cluster.h"


Esfera::Esfera(float pRaio, Ponto* pCentro, Material* material) : raio(pRaio), centro(pCentro),
                                              Objeto("Esfera",false, material)  {}

tuple<Ponto*, Objeto*> Esfera::IntersecaoReta(Ponto* pP0, const Vetor &pV0){
    //p_t_int eh o ponto dado o t_int
    Ponto* p_t_int1 = nullptr;
    Ponto* p_t_int2 = nullptr;
    double t_int1, t_int2;

    // A*t_int² + B*t_int + C = 0

    Vetor pV0N = biblioteca::NormalizaVetor(pV0);

    // C0P0 eh o P0 - C0
    Vetor C0P0 = biblioteca::SubtracaoPontos(*this->centro, *pP0);

    // A = u*u
    double produtoA = biblioteca::ProdutoEscalar(pV0N,pV0N);

    // B = 2 * (P0 - C0) * u
    double produtoB = biblioteca::ProdutoEscalar(C0P0,pV0N);

    // C = (P0 - C0) * (P0 - C0) - R²
    double produtoC = biblioteca::ProdutoEscalar(C0P0,C0P0) - (this->raio*this->raio);

    /*  Δ > 0 tem 2 intersecoes
        Δ = 0 tem 1 intersecao
        Δ < 0 tem 0 intersecoes */

    double Delta = (produtoB*produtoB) - (produtoA)*(produtoC);

    if (Delta > 0){

        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        t_int2 = (-produtoB - sqrt(Delta))/produtoA;
        p_t_int1 = biblioteca::EquacaoDaReta(*pP0,t_int1,pV0N);
        p_t_int2 = biblioteca::EquacaoDaReta(*pP0,t_int2,pV0N);
        if(biblioteca::distanciaEntrePontos(p_t_int1,pP0) > biblioteca::distanciaEntrePontos(p_t_int2,pP0)) {
            p_t_int1 = p_t_int2;
        }
    }

    else if (Delta == 0){

        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        p_t_int1 = biblioteca::EquacaoDaReta(*pP0,t_int1,pV0N);
    }

    return make_tuple(p_t_int1, this);

}

void Esfera::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(centro);
}

void Esfera::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(centro);
}

Vetor Esfera::calcularNormal(Ponto* p){
    Vetor v;
    v = biblioteca::SubtracaoPontos(*this->centro,*p);
    v = biblioteca::NormalizaVetor(v);
    return v;
}   

Ponto *Esfera::PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0) {
    return nullptr;
}

Objeto* Esfera::aplicarEspelhamento(vector<Matriz> &pMatrizesTransf){
    return this;
}

Ponto *Esfera::getCentro() {
    return centro;
}

void Esfera::aplicarTransformacao(vector<Matriz> &pMatrizesTransf) {

}

tuple<Ponto, Ponto> Esfera::Limites()
{
    Ponto max{centro->x + raio, centro->y + raio, centro->z + raio};
    Ponto min{centro->x - raio, centro->y - raio, centro->z - raio};
    return make_tuple(max, min);
}
