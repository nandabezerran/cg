//
// Created by fbeze on 26/08/2019.
//

#ifndef COMPUTACAOGRAFICA_OBJETO_HPP
#define COMPUTACAOGRAFICA_OBJETO_HPP
#include "biblioteca.hpp"
enum colour { DARKBLUE=1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };
class Objeto {
public:
    string nome;
    colour cor;
    bool visibilidade;
    Objeto(const string& pNome, colour cor, bool visibilidade);
    virtual std::tuple<Ponto*,Ponto*> IntersecaoReta(Ponto* pP0, VectorXd pVetor0, int pTamanho) = 0;
};


#endif //COMPUTACAOGRAFICA_OBJETO_HPP
