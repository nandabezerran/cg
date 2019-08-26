//
// Created by fbeze on 24/08/2019.
//

#include "Cilindro.hpp"
#include "Plano.hpp"

Cilindro::Cilindro(float pAltura, float pRaio, Ponto* pCentro, VectorXd pNormal) : altura(pAltura), raio(pRaio),
                                                                                   centro(pCentro), normal(pNormal),
                                                                                   Objeto("Cilindro") {}

tuple<Ponto*,Ponto*> Cilindro::IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho){


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


    if (ValidacaoPontoBase(pP0, pVetor0, pTamanho) == 2){
        
        p_int1 = IntersecaoRetaBase(centroInf,pP0, pVetor0, pTamanho);
        p_int2 = IntersecaoRetaBase(centroSup,pP0, pVetor0, pTamanho);

    }

    else if (ValidacaoPontoBase(pP0, pVetor0, pTamanho) == 1){
        
        p_int1 = ChoseBase(pP0, pVetor0, pTamanho);

        t_int1 = (-b + sqrt(delta))/a;
        t_int2 = (-b - sqrt(delta))/a;

        Ponto* p_teste1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
        Ponto* p_teste2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);

        if (ValidacaoPontoLateral(p_teste1, pTamanho))
            p_int2 = p_teste1;
        else if (ValidacaoPontoLateral(p_teste2, pTamanho))
            p_int2 = p_teste2;

    }

    else{

        t_int1 = (-b + sqrt(delta))/a;
        t_int2 = (-b - sqrt(delta))/a;

        Ponto* p_teste1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
        Ponto* p_teste2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);

        if (ValidacaoPontoLateral(p_teste1, pTamanho))
            p_int1 = p_teste1;
        if (ValidacaoPontoLateral(p_teste2, pTamanho))
            p_int2 = p_teste2;
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

int Cilindro::ValidacaoPontoBase(Ponto* pP0,VectorXd pVetor0, int tamanho){

    /*
        Interseção com nenhuma Base = 0
        Interseção com uma Base = 1
        Interseção com uma Base = 2
    */

    VectorXd H_n = this->altura*this->normal;
    Ponto* centroInf = this->centro;
    Ponto* centroSup = biblioteca::CriarPonto(this->centro->x + H_n[0], this->centro->y + H_n[1],this->centro->z + H_n[2]);

    Ponto* p1 = IntersecaoRetaBase(centroInf, pP0, pVetor0, tamanho);
    VectorXd BasePonto1 = biblioteca::SubtracaoPontos(p1,centroInf,tamanho);
    double norma1 = sqrt(biblioteca::ProdutoEscalar(BasePonto1,BasePonto1,tamanho));

    Ponto* p2 = IntersecaoRetaBase(centroSup, pP0, pVetor0, tamanho);
    VectorXd BasePonto2 = biblioteca::SubtracaoPontos(p2,centroSup,tamanho);
    double norma2 = sqrt(biblioteca::ProdutoEscalar(BasePonto2,BasePonto2,tamanho));

    if ((0 <= norma1 && norma1 <= this->raio) && (0 <= norma2 && norma2 <= this->raio))
        return 2;
    else if ((0 <= norma1 && norma1 <= this->raio) || (0 <= norma2 && norma2 <= this->raio))
        return 1;
    else
        return 0;
}

Ponto* Cilindro::IntersecaoRetaBase(Ponto* centro, Ponto* pP0,VectorXd pVetor0, int tamanho){

    Plano* base = new Plano(centro, this->normal);
    Ponto* p_int = base->IntersecaoRetaPlano(pP0, pVetor0, tamanho);
    return p_int;

}

Ponto* Cilindro::ChoseBase(Ponto* pP0,VectorXd pVetor0, int tamanho){

    VectorXd H_n = this->altura*this->normal;
    Ponto* centroInf = this->centro;
    Ponto* centroSup = biblioteca::CriarPonto(this->centro->x + H_n[0], this->centro->y + H_n[1],this->centro->z + H_n[2]);

    Ponto* p = IntersecaoRetaBase(centroInf, pP0, pVetor0, tamanho);
    VectorXd BasePonto = biblioteca::SubtracaoPontos(p,centroInf,tamanho);
    double norma = sqrt(biblioteca::ProdutoEscalar(BasePonto,BasePonto,tamanho));

    if((0 <= norma && norma <= this->raio)) {
        return(IntersecaoRetaBase(centroInf, pP0, pVetor0, tamanho));
    }

    else
        return(IntersecaoRetaBase(centroSup, pP0, pVetor0, tamanho));

}
