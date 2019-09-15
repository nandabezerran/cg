//
// Created by fbeze on 25/08/2019.
//

#ifndef COMPUTACAOGRAFICA_PLANO_HPP
#define COMPUTACAOGRAFICA_PLANO_HPP
#include "biblioteca.hpp"

class Plano {
public:
    Ponto *p_pi;
    Vetor normal;

    Plano();
    Plano(Ponto *pPi, Vetor pNormal);
    Ponto* IntersecaoRetaPlano(const Ponto &p0, const Vetor &vetor0) const;
};


#endif //COMPUTACAOGRAFICA_PLANO_HPP
