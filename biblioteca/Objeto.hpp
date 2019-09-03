//
// Created by fbeze on 26/08/2019.
//

#ifndef COMPUTACAOGRAFICA_OBJETO_HPP
#define COMPUTACAOGRAFICA_OBJETO_HPP
#include "biblioteca.hpp"
class Objeto {
public:
    string nome;
    int rgb[3];
    bool visibilidade;
    Objeto(const string& pNome, int r, int g, int b, bool visibilidade);
    virtual std::tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho) = 0;
};


#endif //COMPUTACAOGRAFICA_OBJETO_HPP
