//
// Created by fbeze on 08/09/2019.
//

#ifndef COMPUTACAOGRAFICA_LUZSPOT_HPP
#define COMPUTACAOGRAFICA_LUZSPOT_HPP

#include "Luz.hpp"
#include "PontoIntersecao.hpp"
#include "Objeto.hpp"

class LuzSpot : Luz{
    Ponto* posicao;
    VectorXd direcao;
    float angAbertura;
    LuzSpot(float r, float g, float b, double x, double y, double z);
    double calcularFatorDifuso(PontoIntersecao* p, Objeto* o);
    VectorXd calcularIntensidadeDifusa(PontoIntersecao* p, Objeto* o);
};


#endif //COMPUTACAOGRAFICA_LUZSPOT_HPP
