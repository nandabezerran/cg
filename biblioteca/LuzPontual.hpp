//
// Created by thais on 06/09/2019.
//

#ifndef COMPUTACAOGRAFICA_LUZPONTUAL_HPP
#define COMPUTACAOGRAFICA_LUZPONTUAL_HPP


#include "Luz.hpp"

class LuzPontual : Luz {
public:
    int PosicaoPontual[3];
    LuzPontual(int r, int g, int b, int x, int y, int z);
};


#endif //COMPUTACAOGRAFICA_LUZPONTUAL_HPP
