//
// Created by thais on 06/09/2019.
//

#include "LuzPontual.hpp"

LuzPontual::LuzPontual(int r, int g, int b, int x, int y, int z): Luz(r, g, b){
    PosicaoPontual[0] = x;
    PosicaoPontual[1] = y;
    PosicaoPontual[2] = z;
}