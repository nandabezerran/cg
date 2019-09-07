
#ifndef COMPUTACAOGRAFICA_LUZAMBIENTE_HPP
#define COMPUTACAOGRAFICA_LUZAMBIENTE_HPP

#include "Luz.hpp"
#include "biblioteca.hpp"
#include "PontoIntersecao.hpp"

class LuzAmbiente : Luz {
public:
    Ponto* posicaoPontual;
    LuzAmbiente(int r, int g, int b, int x, int y, int z);
};


#endif //COMPUTACAOGRAFICA_LUZAMBIENTE_HPP
