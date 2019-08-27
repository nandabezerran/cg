//
// Created by thais on 26/08/2019.
//
/*

#ifndef COMPUTACAOGRAFICA_CUBO_HPP
#define COMPUTACAOGRAFICA_CUBO_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
#include "Plano.hpp"

class Cubo : public Objeto {
public:
    string nome;
    VectorXd normal;
    double aresta;
    Ponto* centro;
    vector<Plano*> planos;
    Cubo(VectorXd cNormal, double cAresta, Ponto* cCentro);
    tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho) override;
};
#endif //COMPUTACAOGRAFICA_CUBO_HPP

*/