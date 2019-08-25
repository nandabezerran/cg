//
// Created by fbeze on 25/08/2019.
//

#ifndef COMPUTACAOGRAFICA_PLANO_HPP
#define COMPUTACAOGRAFICA_PLANO_HPP
#include "biblioteca.hpp"

class Plano {
public:
    Ponto p_pi;
    VectorXd normal;

    Plano(Ponto pPi, VectorXd pNormal);
    Ponto IntersecaoRetaPlano(Ponto p0, VectorXd vetor0, int tamanho);
};


#endif //COMPUTACAOGRAFICA_PLANO_HPP
