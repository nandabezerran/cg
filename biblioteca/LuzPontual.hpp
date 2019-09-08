//
// Created by thais on 06/09/2019.
//

#ifndef COMPUTACAOGRAFICA_LUZPONTUAL_HPP
#define COMPUTACAOGRAFICA_LUZPONTUAL_HPP


#include "Luz.hpp"
#include "biblioteca.hpp"
#include "PontoIntersecao.hpp"

class LuzPontual : Luz {
public:
    Ponto* posicaoPontual;
    LuzPontual(float r, float g, float b, double x,double y,double z);
    double calcularFatorDifuso(PontoIntersecao* p, Objeto* o);
    VectorXd calcularIntensidadeDifusa(PontoIntersecao* p, Objeto* o);
};


#endif //COMPUTACAOGRAFICA_LUZPONTUAL_HPP
