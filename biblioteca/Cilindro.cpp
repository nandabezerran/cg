//
// Created by fbeze on 24/08/2019.
//

#include "Cilindro.hpp"

Cilindro::Cilindro(float pAltura, float pRaio, Ponto pCentro, VectorXd pNormal) : altura(pAltura), raio(pRaio),
                                                                                  centro(pCentro), normal(pNormal) {}

tuple<Ponto,Ponto,int,int> Cilindro::IntersecaoRetaCilindro(Ponto pP0, VectorXd pVetor0, int pTamanho){


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

    int intersec = 0;
    double t_int1,t_int2;
    Ponto p_int1,p_int2;
    bool tratamento_int1 = false, tratamento_int2 = false;
    //Vetor auxiliar para calcular o vertice do cone (H*n)
    VectorXd vetor_aux = this->altura*this->normal;
    Ponto vertice = biblioteca::CriarPonto(this->centro.x + vetor_aux[0], this->centro.y + vetor_aux[1],
            this->centro.z + vetor_aux[2]);

    if (delta > 0){
        intersec = 2;

        if(a!=0){
            t_int1 = (-b + sqrt(delta))/a;
            t_int2 = (-b - sqrt(delta))/a;
        }else{
            t_int1 = -c / 2*b;
            t_int2 = -c / 2*b;
        }

        p_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
        p_int2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);
        tratamento_int1 = this->ValidacaoPontoCilindro(vertice,p_int1, pTamanho);
        tratamento_int2 = this->ValidacaoPontoCilindro(vertice,p_int2, pTamanho);

    }
    else if (delta == 0 && (b!=0 && a!=0)){
        intersec = 1;
        t_int1 = (-b + sqrt(delta))/a;
        p_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
        tratamento_int1 = this->ValidacaoPontoCilindro(vertice,p_int1, pTamanho);
    }

    /* Pontos validos
        0 = nenhum ponto valido
        1 = primeiro ponto valido apenas
        2 = segundo ponto valido apenas
        3 = os dois pontos sao validos
    */

    int validacao = 0;

    if(tratamento_int1 && tratamento_int2){
        validacao = 3;
    }else if(tratamento_int1 && !tratamento_int2){
        validacao = 1;
    }else if(!tratamento_int1 && tratamento_int2){
        validacao = 2;
    }

    return make_tuple(p_int1, p_int2, validacao, intersec);
}

bool Cilindro::ValidacaoPontoCilindro(Ponto vertice, Ponto p_int, int tamanho){

    //escalar_tratamento e vetor_aux_tratamento
    VectorXd vetor_aux_tratamento(tamanho);
    vetor_aux_tratamento[0] = vertice.x - p_int.x;
    vetor_aux_tratamento[1] = vertice.y - p_int.y;
    vetor_aux_tratamento[2] = vertice.z - p_int.z;

    double escalar_tratamento = biblioteca::ProdutoEscalar(vetor_aux_tratamento,this->normal,tamanho);

    bool tratamento_int = 0 <= escalar_tratamento && escalar_tratamento <= this->altura;

    return tratamento_int;
}




