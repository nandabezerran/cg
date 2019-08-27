//
// Created by thais on 26/08/2019.
//


#ifndef COMPUTACAOGRAFICA_CUBO_HPP
#define COMPUTACAOGRAFICA_CUBO_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
#include "Plano.hpp"

struct Aresta{
    Vector3d aresta;
    tuple<Ponto, Ponto> pontos;
};

struct Face{
    vector<Ponto> vertices;
    vector<Aresta> arestas;

};

class Cubo : public Objeto {
public:
    VectorXd normal;
    double aresta;
    Ponto* centro;
    vector<Face*> faces;
    Cubo(double cAresta, Ponto* cCentro, VectorXd cNormal);
    //tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho) override;
};
#endif //COMPUTACAOGRAFICA_CUBO_HPP
