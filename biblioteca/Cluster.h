//
// Created by Celito on 2019-11-16.
//

#ifndef COMPUTACAOGRAFICA_CLUSTER_H
#define COMPUTACAOGRAFICA_CLUSTER_H


#include "Objeto.hpp"

class Cluster
    : public Objeto
{
private:
    vector<Objeto *> _objetosInternos;
    Objeto * _colisao;
public:
    Cluster(Objeto* colisao);
    void adicionarObjeto(Objeto * obj);
    tuple<Ponto*,Objeto*> IntersecaoReta(Ponto* pP0, const Vetor &pV0) override;
    Ponto* PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0) override;
    void aplicarTransformacao(vector<Matriz> &pMatrizesTransf) override;
    void mudaCoodCamera(Camera *camera) override;
    void mudaCoodMundo(Camera *camera) override;
    Vetor calcularNormal(Ponto* p) override;
    Objeto* aplicarEspelhamento(vector<Matriz> &pMatrizesTransf) override;
    Ponto* getCentro() override;
    tuple<Ponto, Ponto> Limites() override;
};


#endif //COMPUTACAOGRAFICA_CLUSTER_H
