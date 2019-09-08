//
// Created by fbeze on 26/08/2019.
//

#include "Objeto.hpp"

Objeto::Objeto(const string& pNome, float r, float g, float b, bool pVisibilidade, Material pMat) : nome(pNome),
                                                    visibilidade(pVisibilidade), material(pMat){
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;

}


