//
// Created by fbeze on 26/08/2019.
//

#include "Objeto.hpp"

Objeto::Objeto(const string& pNome, float r, float g, float b, Material pMat, bool pVisibilidade) : nome(pNome),
                                                    visibilidade(pVisibilidade), material(pMat){
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;

}


