//
// Created by fbeze on 20/09/2019.
//

#ifndef COMPUTACAOGRAFICA_MATRIZ_HPP
#define COMPUTACAOGRAFICA_MATRIZ_HPP

#include <vector>
#include "Vetor.hpp"

class Matriz {
public:
    Matriz(unsigned, unsigned, double);
    Matriz operator+(Matriz &);
    Matriz operator-(Matriz &);
    Matriz operator*(Matriz &);
    Matriz operator/(Matriz &);
    Matriz transpor();

    double& operator()(const unsigned &, const unsigned &);
    void imprimir() const;
    unsigned getRows() const;
    unsigned getCols() const;

private:
    unsigned linhas;
    unsigned colunas;
    vector<vector<double> > matriz;
};


#endif //COMPUTACAOGRAFICA_MATRIZ_HPP
