#ifndef COMPUTACAOGRAFICA_LUZREMOTA_HPP
#define COMPUTACAOGRAFICA_LUZREMOTA_HPP

#include "Luz.hpp"
#include "biblioteca.hpp"
#include "PontoIntersecao.hpp"

class LuzRemota : Luz {
public:
    LuzRemota(int r, int g, int b, VectorXd Dr);
    VectorXd calcularIntensidadeRemota(PontoIntersecao* p);
};


#endif //COMPUTACAOGRAFICA_LUZREMOTA_HPP
