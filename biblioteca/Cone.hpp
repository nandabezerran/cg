//
// Created by fbeze on 24/08/2019.
//

#ifndef COMPUTACAOGRAFICA_CONE_HPP
#define COMPUTACAOGRAFICA_CONE_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"

class Cone : public Objeto{
public:
    string nome;
    float altura;
    float raio;
    Ponto* centro;
    VectorXd normal;

    Cone(float pAltura, float pRaio, Ponto* pCentro, VectorXd pNormal);
    VectorXd calcularNormal(Ponto* pi);

    bool ValidacaoPontoCone(Ponto* vertice, Ponto* p_int, int tamanho);
    tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0,int pTamanho);
    Ponto* IntersecaoRetaBase(Ponto* centro, Ponto* pP0,VectorXd pVetor0, int tamanho);
    bool ValidacaoPontoBase(Ponto* pP0,VectorXd pVetor0, int tamanho);
    void mudaCoodCamera(Camera *camera) override;
    void mudaCoodMundo(Camera *camera) override;



};


#endif //COMPUTACAOGRAFICA_CONE_HPP
