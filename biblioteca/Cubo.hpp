//
// Created by thais on 26/08/2019.
//


#ifndef COMPUTACAOGRAFICA_CUBO_HPP
#define COMPUTACAOGRAFICA_CUBO_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
#include "Plano.hpp"
#include <vector>

class Cubo : public Objeto {
public:
    double aresta;
    Ponto* centro;
    vector<Face*> faces;
    Cubo(double cAresta, Ponto* cCentro, VectorXd cNormal);
    tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho) override;
};
#endif //COMPUTACAOGRAFICA_CUBO_HPP
