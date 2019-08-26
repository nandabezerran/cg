//
// Created by fbeze on 24/08/2019.
//

#ifndef COMPUTACAOGRAFICA_ESFERA_HPP
#define COMPUTACAOGRAFICA_ESFERA_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
class Esfera : public Objeto {
public:
    string nome;
    float raio;
    Ponto* centro;
    Esfera(float pRaio, Ponto* pCentro);
    tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho) override;

};


#endif //COMPUTACAOGRAFICA_ESFERA_HPP
