#ifndef COMPUTACAOGRAFICA_LUZREMOTA_HPP
#define COMPUTACAOGRAFICA_LUZREMOTA_HPP

#include "Luz.hpp"
#include "biblioteca.hpp"
#include "PontoIntersecao.hpp"

class LuzRemota : public Luz {
public:
    Vetor direcao;
    LuzRemota(int r, int g, int b, Vetor Dr);
    Vetor calcularIntensidadeDifusa(PontoIntersecao* p) override;
    Vetor calcularIntensidadeEspecular(PontoIntersecao* p) override;
    double calcularFatorEspecular(PontoIntersecao* p);
    double calcularFatorDifuso(PontoIntersecao *p);
    void mudaCoodCamera(Camera *camera) = 0;
    void mudaCoodMundo(Camera *camera) = 0;
};


#endif //COMPUTACAOGRAFICA_LUZREMOTA_HPP
