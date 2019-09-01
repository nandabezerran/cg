//
// Created by fbeze on 25/08/2019.
//

#include "Plano.hpp"

Plano::Plano(Ponto* pPi, VectorXd pNormal) : p_pi(pPi), normal(pNormal) {}

Ponto* Plano::IntersecaoRetaPlano(Ponto* p0, VectorXd vetor0, int tamanho){
    //p_t_int eh o ponto dado o t_int
    Ponto* p_t_int = nullptr;

    //t_int = ( (P0 - Ppi) * n ) / (u*n)

    //vetor eh o Ppi - P0
    VectorXd vetor = biblioteca::SubtracaoPontos(p0, p_pi, tamanho);
    //produto0 eh o resultado do vetor * n
    double produto0 = biblioteca::ProdutoEscalar(vetor, normal, tamanho);
    //produto1 eh o u*n
    double produto1 = biblioteca::ProdutoEscalar(vetor0, normal, tamanho);

    //t_int eh o resultado de cima / resultado de baixo
    double t_int = produto0/produto1;

    //Dado um ponto p0 e um vetor vetor0 retornar a equacao da reta (P(t) = Po + t * V)
    p_t_int = biblioteca::EquacaoDaReta(p0,t_int,vetor0);

    if(biblioteca::ProdutoEscalar(biblioteca::SubtracaoPontos(p_t_int, p_pi, tamanho), normal, tamanho) != 0){
        return nullptr;
    }

    return p_t_int;
}
