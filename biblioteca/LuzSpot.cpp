//
// Created by fbeze on 08/09/2019.
//

#include "LuzSpot.hpp"
LuzSpot::LuzSpot(float r, float g, float b, double x, double y, double z): Luz(r, g, b){
    posicao = new Ponto();
    posicao->x = x;
    posicao->y = y;
    posicao->z = z;
}