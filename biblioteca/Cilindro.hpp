//
// Created by fbeze on 24/08/2019.
//

#ifndef COMPUTACAOGRAFICA_CILINDRO_HPP
#define COMPUTACAOGRAFICA_CILINDRO_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
#include "PontoIntersecao.hpp"
#include "Plano.hpp"

class Cilindro : public Objeto{
public:
    string nome;
    float altura;
    float raio;
    Ponto centro;
    Ponto centroSup;
    Plano baseInf;
    Plano baseSup;
    Vetor normal;
    Cilindro(float pAltura, float pRaio, Ponto pCentro, Vetor pNormal, Material *m);
    tuple<Ponto*,Objeto*> IntersecaoReta(Ponto* pP0, const Vetor &pV0) override;
    Ponto* PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0) override;
    bool ValidacaoPontoLateral(const Ponto &p_int) const;
    void mudaCoodCamera(Camera *camera) override;
    void mudaCoodMundo(Camera *camera) override;
    Vetor calcularNormal(Ponto* pi);
    Objeto* aplicarEspelhamento(vector<Matriz> &pMatrizesTransf) override;
    void aplicarTransformacao(vector<Matriz> &pMatrizesTransf) override;
    Ponto* getCentro() override;

    tuple<Ponto, Ponto> Limites() override;
};


#endif //COMPUTACAOGRAFICA_CILINDRO_HPP
