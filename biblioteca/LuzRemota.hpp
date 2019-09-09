#ifndef COMPUTACAOGRAFICA_LUZREMOTA_HPP
#define COMPUTACAOGRAFICA_LUZREMOTA_HPP

#include "Luz.hpp"
#include "biblioteca.hpp"
#include "PontoIntersecao.hpp"

class LuzRemota : public Luz {
public:
    VectorXd direcao;
    LuzRemota(int r, int g, int b, VectorXd Dr);
    VectorXd calcularIntensidadeDifusa(PontoIntersecao* p) override;
    double calcularFatorDifuso(PontoIntersecao *p);
    void mudaCoodCamera(Camera *camera) = 0;
    void mudaCoodMundo(Camera *camera) = 0;
};


#endif //COMPUTACAOGRAFICA_LUZREMOTA_HPP
