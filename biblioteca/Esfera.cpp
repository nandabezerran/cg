//
// Created by fbeze on 24/08/2019.
//

#include "Esfera.hpp"



Esfera::Esfera(float pRaio, Ponto* pCentro) : raio(pRaio), centro(pCentro),
                                              Objeto("Esfera", 231,84,128, false)  {}

tuple<Ponto*,Ponto*> Esfera::IntersecaoReta(Ponto* pP0, VectorXd pVetor0,int pTamanho){
    //p_t_int eh o ponto dado o t_int
    Ponto* p_t_int1 = nullptr;
    Ponto* p_t_int2 = nullptr;
    double t_int1, t_int2;

    // A*t_int² + B*t_int + C = 0

    pVetor0 = biblioteca::NormalizaVetor(pVetor0,pTamanho);

    // C0P0 eh o P0 - C0
    VectorXd C0P0 = biblioteca::SubtracaoPontos(this->centro,pP0,pTamanho);

    // A = u*u
    double produtoA = biblioteca::ProdutoEscalar(pVetor0,pVetor0,pTamanho);

    // B = 2 * (P0 - C0) * u
    double produtoB = biblioteca::ProdutoEscalar(C0P0,pVetor0,pTamanho);

    // C = (P0 - C0) * (P0 - C0) - R²
    double produtoC = biblioteca::ProdutoEscalar(C0P0,C0P0,pTamanho) - (this->raio*this->raio);

    /*  Δ > 0 tem 2 intersecoes
        Δ = 0 tem 1 intersecao
        Δ < 0 tem 0 intersecoes */

    double Delta = (produtoB*produtoB) - (produtoA)*(produtoC);

    if (Delta > 0){

        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        t_int2 = (-produtoB - sqrt(Delta))/produtoA;
        p_t_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
        p_t_int2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);
    }

    else if (Delta == 0){

        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        p_t_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
    }



    //cout << "Esfera  " << produtoA << " "<< produtoB  << " "<<  produtoC  << " "<<  Delta  << " "<<  t_int1  << " "<< t_int2 <<  endl; 

    return make_tuple(p_t_int1, p_t_int2);

}

void Esfera::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(centro);
}

void Esfera::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(centro);
}


