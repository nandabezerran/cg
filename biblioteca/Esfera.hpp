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
    Esfera(float pRaio, Ponto* pCentro, Material* material);
    tuple<Ponto*,Objeto*> IntersecaoReta(Ponto* pP0, const Vetor &pV0) override;
    Ponto* PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0);
    void mudaCoodCamera(Camera *camera) override;
    void mudaCoodMundo(Camera *camera) override;
    Vetor calcularNormal(Ponto* p) override;
    Objeto* aplicarEspelhamento(vector<Matriz> &pMatrizesTransf) override;
    void aplicarTransformacao(vector<Matriz> &pMatrizesTransf) override;
    Ponto* getCentro() override;
    tuple<Ponto, Ponto> Limites() override;
};


#endif //COMPUTACAOGRAFICA_ESFERA_HPP
