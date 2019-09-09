//
// Created by thais on 06/09/2019.
//

#ifndef COMPUTACAOGRAFICA_LUZ_HPP
#define COMPUTACAOGRAFICA_LUZ_HPP
#include "biblioteca.hpp"
#include "PontoIntersecao.hpp"
#include "Camera.hpp"

class Luz {
public:
    VectorXd intensidadeRgb;
    virtual VectorXd calcularIntensidadeDifusa(PontoIntersecao* p) = 0;
    virtual void mudaCoodCamera(Camera *camera) = 0;
    virtual void mudaCoodMundo(Camera *camera) = 0;
    Luz(float r, float g, float b);
};


#endif //COMPUTACAOGRAFICA_LUZ_HPP
