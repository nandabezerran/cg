//
// Created by fbeze on 24/08/2019.
//

//Changes: natalia-rios, 26/08/2019.

#include "Cilindro.hpp"
#include "Plano.hpp"

Cilindro::Cilindro(float pAltura, float pRaio, Ponto* pCentro, VectorXd pNormal) : altura(pAltura), raio(pRaio),
                                                                                  centro(pCentro), normal(pNormal) {}

tuple<Ponto*,Ponto*> Cilindro::IntersecaoRetaCilindro(Ponto* pP0, VectorXd pVetor0, int pTamanho){


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
    double a = biblioteca::ProdutoEscalar(w,w,pTamanho);

    //B = (v*w)
    double b = biblioteca::ProdutoEscalar(v,w,pTamanho);

    //C = (v*v - R²)
    double c = biblioteca::ProdutoEscalar(v,v,pTamanho) - (this->raio*this->raio);
    

    //delta
    double delta = b*b - a*c;
   /*  Δ > 0 tem 2 intersecoes
        Δ = 0 tem 1 intersecao
        Δ < 0 tem 0 intersecoes */

    double t_int1,t_int2;
    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;

    //Centro da Base Superior e da Base Inferior
    VectorXd H_n = this->altura*this->normal;
    Ponto* centroInf = this->centro;
    Ponto* centroSup = biblioteca::CriarPonto(this->centro->x + H_n[0], this->centro->y + H_n[1],this->centro->z + H_n[2]);

    bool tratamento_int1 = false, tratamento_int2 = false;


    if(a == 0) {
          t_int1 = -c / 2*b;
          t_int2 = -c / 2*b;
          p_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
          p_int2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);

    }else {

        if(delta == 0) {
            t_int1 = (-b + sqrt(delta))/a;
            tratamento_int1 = this->ValidacaoPontoLateral(p_int1, pTamanho);


            if(tratamento_int1) {
                if(Cilindro::ValidacaoPontoBase(centroInf, pP0, this->centro, pTamanho) || Cilindro::ValidacaoPontoBase(centroSup, pP0, this->centro, pTamanho)) {
                    p_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
                }
            }
        }

    }else if(delta > 0 && a!=0) {

        t_int1 = (-b + sqrt(delta))/a;
        t_int2 = (-b - sqrt(delta))/a;

        tratamento_int1 = this->ValidacaoPontoLateral(p_int1, pTamanho);
        tratamento_int2 = this->ValidacaoPontoLateral(p_int2, pTamanho);

        if(tratamento_int1 && tratamento_int2) {
            p_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
            p_int2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);
        }

      
        if(tratamento_int2) {
            p_int2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);
            if(Cilindro::ValidacaoPontoBase(centroInf, pP0, this->centro, pTamanho) || Cilindro::ValidacaoPontoBase(centroSup, pP0, this->centro, pTamanho)) {
                p_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
            }
        }

        if(tratamento_int1) {
            p_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
            if(Cilindro::ValidacaoPontoBase(centroInf, pP0, this->centro, pTamanho) || Cilindro::ValidacaoPontoBase(centroSup, pP0, this->centro, pTamanho)) {
                p_int2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);
            }
        }

        if(!tratamento_int1 && !tratamento_int2 && (biblioteca::ProdutoVetorial(pVetor0,VetorN_u) == 0)) {
            if(Cilindro::ValidacaoPontoBase(centroInf, pP0, this->centro, pTamanho) && Cilindro::ValidacaoPontoBase(centroSup, pP0, this->centro, pTamanho)) {
                p_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
                p_int2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);

        }

    } 

    return make_tuple(p_int1, p_int2);
}

bool Cilindro::ValidacaoPontoLateral(Ponto* p_int, int tamanho){

    VectorXd PB = biblioteca::SubtracaoPontos(p_int,this->centro,tamanho);
    double PB_u = biblioteca::ProdutoEscalar(PB, this->normal,tamanho);

    if (0 <= PB_u && PB_u <= this->altura)    
        return true;
    else 
        return false;

}

bool Cilindro::ValidacaoPontoBase(Ponto* pP0,VectorXd pVetor0, Ponto* centro, int tamanho){

    Plano* base = new Plano(centro, this->normal);
    Ponto* p_int = base->IntersecaoRetaPlano(pP0, pVetor0, tamanho);

    VectorXd BasePonto = biblioteca::SubtracaoPontos(p_int,centro,tamanho);
    double norma = sqrt(biblioteca::ProdutoEscalar(BasePonto,BasePonto,tamanho));

    if (0 <= norma && norma <= this->raio)
        return true;
    else
        return false;

}


