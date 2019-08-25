//
// Created by fbeze on 24/08/2019.
//

#include "Cilindro.hpp"

Cilindro::Cilindro(float pAltura, float pRaio, Ponto pCentro, VectorXd pNormal) : altura(pAltura), raio(pRaio),
                                                                                  centro(pCentro), normal(pNormal) {}

tuple<Ponto,Ponto,int> Cilindro::IntersecaoRetaCilindro(Ponto pP0, VectorXd pVetor0, int pTamanho){
    //p_t_int eh o ponto dado o t_int
    Ponto p_t_int1, p_t_int2;
    double t_int1, t_int2;

    // A*t_int² + 2B*t_int + C = 0

    // Normalizar o vetor_d
    pVetor0 = biblioteca::NormalizaVetor(pVetor0,pTamanho);

    // C0P0 eh o P0 - C0
    VectorXd C0P0 = biblioteca::SubtracaoPontos(pP0,this->centro,pTamanho);

    // V eh o ((C0P0) - ((C0P0)* pVetor0)* pVetor0)
    double C0P0_u = biblioteca::ProdutoEscalar(C0P0,pVetor0,pTamanho);
    VectorXd v = C0P0 - (C0P0_u * pVetor0);

    // W eh o (vetor_n - (vetor_n * pVetor0)*pVetor0)
    double VetorN_u = biblioteca::ProdutoEscalar(this->normal,pVetor0,pTamanho);
    VectorXd w = this->normal - (VetorN_u * pVetor0);

    //A = w*w
    double produtoA = biblioteca::ProdutoEscalar(w,w,pTamanho);

    //B = (v*w)
    double produtoB = biblioteca::ProdutoEscalar(v,w,pTamanho);

    //C = (v*v - R²)
    double produtoC = biblioteca::ProdutoEscalar(v,v,pTamanho) - (this->raio*this->raio);

    /*  Δ > 0 tem 2 intersecoes
        Δ = 0 tem 1 intersecao
        Δ < 0 tem 0 intersecoes */

    int intersec = 0;
    bool tratamento = 0 <= C0P0_u && C0P0_u <= this->altura;
    double Delta = (produtoB*produtoB) - (produtoA)*(produtoC);

    if (Delta > 0 && tratamento){

        intersec = 2;
        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        t_int2 = (-produtoB - sqrt(Delta))/produtoA;
        p_t_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
        p_t_int2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);
    }

    else if (Delta == 0 && tratamento){

        intersec = 1;
        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        p_t_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
    }

    return make_tuple(p_t_int1, p_t_int2, intersec);
}


