//
// Created by fbeze on 24/08/2019.
//

#include "Cone.hpp"

Cone::Cone(float pAltura, float pRaio, Ponto* pCentro, VectorXd pNormal) : altura(pAltura), raio(pRaio),
                                                                          centro(pCentro), normal(pNormal),
                                                                           Objeto("Cone") {}

tuple<Ponto*, Ponto*> Cone::IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho){

    //Vertice do cone
    //V = C + H*n

    //Vetor auxiliar para calcular o vertice do cone (H*n)
    VectorXd vetor_aux = this->altura*this->normal;

    Ponto* vertice = biblioteca::CriarPonto(this->centro->x + vetor_aux[0], this->centro->y + vetor_aux[1],
            this->centro->z + vetor_aux[2]);


    //cout << vertice.x << vertice.y << vertice.z << endl;

    //vetor d normalizado
    VectorXd d = biblioteca::NormalizaVetor(pVetor0,pTamanho);

    //cos alfa
    double cos_alfa = this->altura / (sqrt(pow(this->altura,2) + pow(raio,2)));

    //vetor v
    VectorXd v(pTamanho);
    v[0] = vertice->x - pP0->x;
    v[1] = vertice->y - pP0->y;
    v[2] = vertice->z - pP0->z;
    //cout << v << endl;

    //a
    double a = pow(biblioteca::ProdutoEscalar(d,this->normal,pTamanho),2) - (biblioteca::ProdutoEscalar(d,d, pTamanho) *
            pow(cos_alfa,2));
    //cout << a << endl;

    //b
    double b = (biblioteca::ProdutoEscalar(v,d,pTamanho) * pow(cos_alfa,2))
            - (biblioteca::ProdutoEscalar(v,this->normal,pTamanho)) * (biblioteca::ProdutoEscalar(d,this->normal,pTamanho));
    //cout << b << endl;

    //c
    double c = pow(biblioteca::ProdutoEscalar(v,this->normal,pTamanho),2)
            - (biblioteca::ProdutoEscalar(v,v,pTamanho)*pow(cos_alfa,2));
    //cout << c << endl;

    //delta
    double delta = b*b - a*c;
    //cout<<"delta:"<<delta<<endl;

    /*  Δ > 0 tem 2 intersecoes
        Δ = 0 tem 1 intersecao
        Δ < 0 tem 0 intersecoes */

    double t_int1,t_int2;
    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;
    bool tratamento_int1 = false, tratamento_int2 = false;

    if (delta > 0){

        if(a!=0){
            t_int1 = (-b + sqrt(delta))/a;
            t_int2 = (-b - sqrt(delta))/a;
        }else{
            t_int1 = -c / 2*b;
            t_int2 = -c / 2*b;
        }

        p_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
        p_int2 = biblioteca::EquacaoDaReta(pP0,t_int2,pVetor0);
        tratamento_int1 = this->ValidacaoPontoCone(vertice,p_int1, pTamanho);
        tratamento_int2 = this->ValidacaoPontoCone(vertice,p_int2, pTamanho);

    }
    else if (delta == 0 && (b!=0 && a!=0)){
        t_int1 = (-b + sqrt(delta))/a;
        p_int1 = biblioteca::EquacaoDaReta(pP0,t_int1,pVetor0);
        tratamento_int1 = this->ValidacaoPontoCone(vertice,p_int1, pTamanho);
    }

    if(p_int1){
        if(!tratamento_int1){
            p_int1 = nullptr;
        }
    }
    if(p_int2){
        if(!tratamento_int2){
            p_int2 = nullptr;
        }
    }

    return make_tuple(p_int1, p_int2);
}

bool Cone::ValidacaoPontoCone(Ponto* vertice, Ponto* p_int, int tamanho){

    //escalar_tratamento e vetor_aux_tratamento
    VectorXd vetor_aux_tratamento(tamanho);
    vetor_aux_tratamento[0] = vertice->x - p_int->x;
    vetor_aux_tratamento[1] = vertice->y - p_int->y;
    vetor_aux_tratamento[2] = vertice->z - p_int->z;

    double escalar_tratamento = biblioteca::ProdutoEscalar(vetor_aux_tratamento,this->normal,tamanho);

    bool tratamento_int = 0 <= escalar_tratamento && escalar_tratamento <= this->altura;

    return tratamento_int;
}


