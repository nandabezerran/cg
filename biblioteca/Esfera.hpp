//
// Created by fbeze on 24/08/2019.
//

#ifndef COMPUTACAOGRAFICA_ESFERA_HPP
#define COMPUTACAOGRAFICA_ESFERA_HPP
#include "biblioteca.hpp"

class Esfera {
public:
    float raio;
    Ponto centro;
    Esfera(float pRaio, Ponto pCentro);
    tuple<Ponto,Ponto,int> IntersecaoRetaEsfera(Ponto pP0, VectorXd pVetor0, int pTamanho);

};


#endif //COMPUTACAOGRAFICA_ESFERA_HPP
