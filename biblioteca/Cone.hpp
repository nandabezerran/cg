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
    Ponto* centro;
    Vetor normal;
    Plano* base;

    Cone(float pAltura, float pRaio, Ponto* pCentro, Vetor pNormal, Material* material);
    Vetor calcularNormal(Ponto* pi);
    bool ValidacaoPontoCone(Ponto* vertice, Ponto* p_int);
    tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, const Vetor &pV0) override;
    Ponto* PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0);
    Ponto* IntersecaoRetaBase(Ponto* centro, Ponto* pP0, const Vetor &pVetor0);
    bool ValidacaoPontoBase(Ponto* pP0, const Vetor &pVetor0);
    void mudaCoodCamera(Camera *camera) override;
    void mudaCoodMundo(Camera *camera) override;
    Ponto* getCentro() override;

    Objeto* aplicarTransformacao(vector<Matriz> &pMatrizesTransf) override;



};


#endif //COMPUTACAOGRAFICA_CONE_HPP
