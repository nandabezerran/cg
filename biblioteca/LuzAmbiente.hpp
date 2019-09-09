
#ifndef COMPUTACAOGRAFICA_LUZAMBIENTE_HPP
#define COMPUTACAOGRAFICA_LUZAMBIENTE_HPP

#include "Luz.hpp"
#include "biblioteca.hpp"
#include "PontoIntersecao.hpp"

class LuzAmbiente {
public:
    VectorXd intensidadeRgb;
    LuzAmbiente(float r, float g, float b);
    VectorXd calcularIntensidadeAmbiente(PontoIntersecao* p);
};


#endif //COMPUTACAOGRAFICA_LUZAMBIENTE_HPP
