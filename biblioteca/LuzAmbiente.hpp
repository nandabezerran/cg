
#ifndef COMPUTACAOGRAFICA_LUZAMBIENTE_HPP
#define COMPUTACAOGRAFICA_LUZAMBIENTE_HPP

#include "Luz.hpp"
#include "biblioteca.hpp"
#include "PontoIntersecao.hpp"

class LuzAmbiente : Luz {
public:
    LuzAmbiente(int r, int g, int b);
    VectorXd calcularIntensidadeAmbiente(PontoIntersecao* p);
};


#endif //COMPUTACAOGRAFICA_LUZAMBIENTE_HPP
