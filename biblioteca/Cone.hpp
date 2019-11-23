//
// Created by fbeze on 24/08/2019.
//

#ifndef COMPUTACAOGRAFICA_CONE_HPP
#define COMPUTACAOGRAFICA_CONE_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
#include "Matriz.hpp"
#include "Plano.hpp"

class Objeto;
class Cone : public Objeto{
public:
    string nome;
    float altura;
    float raio;
    Plano* base;
    Ponto* centro;
    Vetor normal;

    Cone(float pAltura, float pRaio, Ponto* pCentro, Vetor pNormal, Material* material);
    Vetor calcularNormal(Ponto* pi);
    bool ValidacaoPontoCone(Ponto* vertice, Ponto* p_int);
    tuple<Ponto*,Objeto*> IntersecaoReta(Ponto* pP0, const Vetor &pV0) override;
    Ponto* PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0);
    Ponto* IntersecaoRetaBase(Ponto* centro, const Ponto& pP0, const Vetor &pVetor0);
    void mudaCoodCamera(Camera *camera) override;
    void mudaCoodMundo(Camera *camera) override;
    void aplicarTransformacao(vector<Matriz> &pMatrizesTransf) override;
    Ponto* getCentro() override;

    Objeto* aplicarEspelhamento(vector<Matriz> &pMatrizesTransf) override;

    tuple<Ponto, Ponto> Limites() override;
};


#endif //COMPUTACAOGRAFICA_CONE_HPP
