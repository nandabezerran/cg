//
// Created by thais on 26/08/2019.
//

#ifndef COMPUTACAOGRAFICA_CUBO_HPP
#define COMPUTACAOGRAFICA_CUBO_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
#include "Plano.hpp"
#include <vector>

struct Vertice {
    string id;
    Ponto* p;
};

struct Aresta{
    string id;
    Vertice* verticeInicial;
    Vertice* verticeFinal;
};

struct Face {
    string id;
    Vertice *p1;
    Vertice *p2;
    Vertice *p3;
    Plano *p;
};

class Cubo : public Objeto {
public:
    double aresta;
    Ponto* centro;
    vector<Face*> faces;
    vector<Vertice*> vertices;
    vector<Aresta*> arestas;
    Cubo(double cAresta, Ponto* cCentro, Material* material);
    tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho) override;
    Vertice* CriarVertice(Ponto* p1, string id);
    Aresta* CriarAresta(Vertice* pi, Vertice* pf, string id);
    Face* CriarFace(Vertice* v1, Vertice* v2, Vertice* v3, string id);
    //bool ValidacaoPontoCubo(Face *face, Ponto *p);
    bool ValidacaoPontoCubo(VectorXd PxPy, VectorXd PxP, VectorXd P1P2, VectorXd P1P3, int tamanho);
    void mudaCoodCamera(Camera *camera) override;
    void mudaCoodMundo(Camera *camera) override;
    VectorXd calcularNormal(Ponto* p) override;
};
#endif //COMPUTACAOGRAFICA_CUBO_HPP
