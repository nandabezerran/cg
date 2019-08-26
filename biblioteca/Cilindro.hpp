//
// Created by fbeze on 24/08/2019.
//

#ifndef COMPUTACAOGRAFICA_CILINDRO_HPP
#define COMPUTACAOGRAFICA_CILINDRO_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
class Cilindro : public Objeto{
public:
    string nome;
    float altura;
    float raio;
    Ponto* centro;
    VectorXd normal;
    Cilindro(float pAltura, float pRaio, Ponto* pCentro, VectorXd pNormal);
    tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho);
    bool ValidacaoPontoLateral(Ponto* p_int, int tamanho);

    int ValidacaoPontoBase(Ponto* pP0,VectorXd pVetor0, int tamanho);
    Ponto* IntersecaoRetaBase(Ponto* centro, Ponto* pP0,VectorXd pVetor0, int tamanho);
    Ponto* ChoseBase(Ponto* pP0,VectorXd pVetor0, int tamanho);
};


#endif //COMPUTACAOGRAFICA_CILINDRO_HPP
