//
// Created by fbeze on 26/08/2019.
//

#ifndef COMPUTACAOGRAFICA_OBJETO_HPP
#define COMPUTACAOGRAFICA_OBJETO_HPP
#include "biblioteca.hpp"
#include "Camera.hpp"
#include "Material.hpp"
class Objeto {
public:
    string nome;
    float rgb[3];
    bool visibilidade;
    Material material;
    Objeto(const string& pNome, float r, float g, float b, bool visibilidade, Material pMat);
    virtual std::tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho) = 0;
    virtual void mudaCoodCamera(Camera *camera) = 0;
    virtual void mudaCoodMundo(Camera *camera) = 0;
    virtual VectorXd calcularNormal(Ponto* p) = 0;
};


#endif //COMPUTACAOGRAFICA_OBJETO_HPP
