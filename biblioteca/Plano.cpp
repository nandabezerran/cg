//
// Created by fbeze on 25/08/2019.
//

#include "Plano.hpp"

Plano::Plano(Ponto pPi, VectorXd pNormal) : p_pi(pPi), normal(pNormal) {}

Ponto Plano::IntersecaoRetaPlano(Ponto p0, VectorXd vetor0, int tamanho){
    //p_t_int eh o ponto dado o t_int
    Ponto p_t_int;

    //t_int = ( (Ppi - P0) * n ) / (u*n)

    //vetor eh o Ppi - p0
    VectorXd vetor = biblioteca::SubtracaoPontos(p0,this->p_pi,tamanho);
    //produto0 eh o resultado do vetor * n
    double produto0 = biblioteca::ProdutoEscalar(vetor,this->normal,tamanho);
    //produto1 eh o u*n
    double produto1 = biblioteca::ProdutoEscalar(vetor0,this->normal,tamanho);

    //t_int eh o resultado de cima / resultado de baixo
    double t_int = produto0/produto1;

    //Dado um ponto p0 e um vetor vetor0 retornar a equacao da reta (P(t) = Po + t * V)
    p_t_int = biblioteca::EquacaoDaReta(p0,t_int,vetor0);

    return p_t_int;
}
