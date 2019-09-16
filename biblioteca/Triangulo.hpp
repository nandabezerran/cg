//
// Created by fbeze on 15/09/2019.
//

#ifndef COMPUTACAOGRAFICA_TRIANGULO_HPP
#define COMPUTACAOGRAFICA_TRIANGULO_HPP

#include "Cubo.hpp"
#include "Objeto.hpp"
struct Vertice;

class Triangulo {
public:
    Triangulo(const string &pId, Vertice *pP1, Vertice *pP2, Vertice *pP3, Plano *pP);
    string id;
    Vertice *p1;
    Vertice *p2;
    Vertice *p3;
    Plano *p;

    Vetor p2p3;
    Vetor p3p1;
    Vetor p1p2;
    Vetor p1p3;

    void mudaCoodCamera(Camera *camera);
    void mudaCoodMundo(Camera *camera);
    bool ValidacaoPontoTriangulo(const Vetor &P1P, const Vetor &P2P, const Vetor &P3P);


};


#endif //COMPUTACAOGRAFICA_TRIANGULO_HPP
