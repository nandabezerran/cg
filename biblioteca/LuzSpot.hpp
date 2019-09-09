//
// Created by fbeze on 08/09/2019.
//

#ifndef COMPUTACAOGRAFICA_LUZSPOT_HPP
#define COMPUTACAOGRAFICA_LUZSPOT_HPP

#include "Luz.hpp"
#include "PontoIntersecao.hpp"
#include "Objeto.hpp"

class LuzSpot : public Luz{
public:
    Ponto* posicao;
    VectorXd direcao;
    float angAbertura;
    LuzSpot(float r, float g, float b, double x, double y, double z,VectorXd pDir,
            float pAng);
    double calcularFatorDifuso(PontoIntersecao* p);
    VectorXd calcularIntensidadeDifusa(PontoIntersecao* p) override;
    void mudaCoodCamera(Camera *camera) override;
    void mudaCoodMundo(Camera *camera) override;
};


#endif //COMPUTACAOGRAFICA_LUZSPOT_HPP
