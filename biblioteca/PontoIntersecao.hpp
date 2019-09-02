//
// Created by fbeze on 02/09/2019.
//

#ifndef COMPUTACAOGRAFICA_PONTOINTERSECAO_HPP
#define COMPUTACAOGRAFICA_PONTOINTERSECAO_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"

class PontoIntersecao {
public:
    Ponto *p;
    Objeto *objeto;
    double distOrigem;
    PontoIntersecao(Ponto* pP, Objeto *pObjeto, double distOrigem);
    PontoIntersecao();
};


#endif //COMPUTACAOGRAFICA_PONTOINTERSECAO_HPP
