//
// Created by fbeze on 08/09/2019.
//

#ifndef COMPUTACAOGRAFICA_LUZSPOT_HPP
#define COMPUTACAOGRAFICA_LUZSPOT_HPP

#include "Luz.hpp"
#include "PontoIntersecao.hpp"
#include "Objeto.hpp"

class LuzSpot : public Luz{
    Ponto* posicao;
    VectorXd direcao;
    float angAbertura;
    LuzSpot(float r, float g, float b, double x, double y, double z);
    double calcularFatorDifuso(PontoIntersecao* p);
    VectorXd calcularIntensidadeDifusa(PontoIntersecao* p) override;
    void mudaCoodCamera(Camera *camera) = 0;
    void mudaCoodMundo(Camera *camera) = 0;
};


#endif //COMPUTACAOGRAFICA_LUZSPOT_HPP
