//
// Created by fbeze on 26/08/2019.
//

#ifndef COMPUTACAOGRAFICA_OBJETO_HPP
#define COMPUTACAOGRAFICA_OBJETO_HPP
#include "biblioteca.hpp"
#include "Camera.hpp"
#include "Material.hpp"
#include "Matriz.hpp"

class Objeto {
public:
    string nome;
    bool visibilidade;
    Material* material;
    Objeto(const string& pNome, bool visibilidade, Material* pMat);
    virtual std::tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, const Vetor &pV0) = 0;
    virtual Ponto* PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0) = 0;
    virtual void mudaCoodCamera(Camera *camera) = 0;
    virtual void mudaCoodMundo(Camera *camera) = 0;
    virtual Vetor calcularNormal(Ponto* p) = 0;
    virtual Objeto* aplicarTransformacao(vector<Matriz> &pMatrizesTransf) = 0;
    virtual Ponto* getCentro() = 0;
};


#endif //COMPUTACAOGRAFICA_OBJETO_HPP
