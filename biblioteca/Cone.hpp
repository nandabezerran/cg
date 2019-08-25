//
// Created by fbeze on 24/08/2019.
//

#ifndef COMPUTACAOGRAFICA_CONE_HPP
#define COMPUTACAOGRAFICA_CONE_HPP
#include "biblioteca.hpp"

class Cone {
public:
    float altura;
    float raio;
    Ponto* centro;
    VectorXd normal;

    Cone(float pAltura, float pRaio, Ponto* pCentro, VectorXd pNormal);
    tuple<Ponto*,Ponto*> IntersecaoRetaCone(Ponto* pP0, VectorXd pVetor0,int pTamanho);
    bool ValidacaoPontoCone(Ponto* vertice, Ponto* p_int, int tamanho);
};


#endif //COMPUTACAOGRAFICA_CONE_HPP
