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
    tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho) override;
    void mudaCoodCamera(Camera *camera) override;
    void mudaCoodMundo(Camera *camera) override;
    VectorXd calcularNormal(Ponto* p) override;


};


#endif //COMPUTACAOGRAFICA_ESFERA_HPP
