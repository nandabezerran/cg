//
// Created by thais on 26/08/2019.
//

#ifndef COMPUTACAOGRAFICA_CUBO_HPP
#define COMPUTACAOGRAFICA_CUBO_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
#include "Plano.hpp"
#include "Triangulo.hpp"
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

class Triangulo;

struct Face {
    Triangulo* t1;
    Triangulo* t2;
};
class Cubo : public Objeto {
public:
    double aresta;
    Ponto* centro;
    vector<Triangulo*> triangulos;
    vector<Vertice*> vertices;
    vector<Face*> faces;
    vector<Aresta*> arestas;
    Vetor normal;
    Vertice* vMaisProx;

    Cubo(double cAresta, Ponto* cCentro, Material* material);
    tuple<Ponto*,Objeto*> IntersecaoReta(Ponto* pP0, const Vetor &pV0) override;
    Ponto* PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0) override;
    Vertice* CriarVertice(Ponto* p1,const string& id);
    Face* CriarFace(Triangulo* pT1, Triangulo* pT2);
    Aresta* CriarAresta(Vertice* pi, Vertice* pf, const string& id);
    Triangulo* CriarTriangulo(Vertice *v1, Vertice *v2, Vertice *v3, const string& id);
    void vMaisProxObs();
    void aplicarTransformacao(vector<Matriz> &pMatrizesTransf) override;

    void mudaCoodCamera(Camera *camera) override;
    void mudaCoodMundo(Camera *camera) override;
    Vetor calcularNormal(Ponto* p) override;
    Objeto* aplicarEspelhamento(vector<Matriz> &pMatrizesTransf) override;
    Ponto* getCentro() override;
    tuple<Ponto, Ponto> Limites() override;
};
#endif //COMPUTACAOGRAFICA_CUBO_HPP
