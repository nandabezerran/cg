//
// Created by fbeze on 25/08/2019.
//

#include "Plano.hpp"

Plano::Plano() : p_pi(), normal() {

}

Plano::Plano(Ponto *pPi, Vetor pNormal) : p_pi(pPi), normal(pNormal) {}

Ponto* Plano::IntersecaoRetaPlano(const Ponto &p0, const Vetor &vetor0) const {
    //t_int = ( (P0 - Ppi) * n ) / (u*n)

    //vetor eh o Ppi - P0
    Vetor vetor = biblioteca::SubtracaoPontos(p0, *p_pi);
    //produto0 eh o resultado do vetor * n
    double produto0 = biblioteca::ProdutoEscalar(vetor, normal);
    //produto1 eh o u*n
    double produto1 = biblioteca::ProdutoEscalar(vetor0, normal);

    if(produto1 == 0){
        return nullptr;
    }

    //t_int eh o resultado de cima / resultado de baixo
    double t_int = produto0/produto1;

    //Dado um ponto p0 e um vetor vetor0 retornar a equacao da reta (P(t) = Po + t * V)
    return biblioteca::EquacaoDaReta(p0, t_int, vetor0);
}