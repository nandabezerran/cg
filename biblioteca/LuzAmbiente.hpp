
#ifndef COMPUTACAOGRAFICA_LUZAMBIENTE_HPP
#define COMPUTACAOGRAFICA_LUZAMBIENTE_HPP

#include "Luz.hpp"
#include "biblioteca.hpp"
#include "PontoIntersecao.hpp"

class LuzAmbiente : Luz {
public:
    Ponto* posicaoAmbiente;
    LuzAmbiente(float r, float g, float b, double x,double y,double z);
};


#endif //COMPUTACAOGRAFICA_LUZAMBIENTE_HPP
